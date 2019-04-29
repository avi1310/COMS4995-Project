#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

// forward declarations of jpeglib struct
struct jpeg_error_mgr;

namespace marengo
{
	namespace jpeg
	{

		class Image
		{
		private:
			// Note that m_errorMgr is a shared ptr and will be shared
			// between objects if one copy constructs from another
			std::shared_ptr< ::jpeg_error_mgr > m_errorMgr;
			std::vector< std::vector<uint8_t> > m_bitmapData;
			size_t                            m_width;
			size_t                            m_height;
			size_t                            m_pixelSize;
			int                               m_colourSpace;

			// explicit Image(
			//     const size_t x,
			//     const size_t y,
			//     const std::vector<std::vector<uint8_t>> bitmap_Data,
			//     const size_t pixelSize = 3,
			//     const int colourSpace = 2
			// )
			// {
			//     m_errorMgr = std::make_shared<::jpeg_error_mgr>();
			//     // Note this usage of a lambda to provide our own error handler
			//     // to libjpeg. If we do not supply a handler, and libjpeg hits
			//     // a problem, it just prints the error message and calls exit().
			//     m_errorMgr->error_exit = [](::j_common_ptr cinfo){
			//         char jpegLastErrorMsg[JMSG_LENGTH_MAX];
			//         // Call the function pointer to get the error message
			//         (*(cinfo->err->format_message))(cinfo, jpegLastErrorMsg);
			//         throw std::runtime_error(jpegLastErrorMsg);
			//     };

			//     m_width       = x;
			//     m_height      = y;
			//     m_pixelSize   = pixelSize;
			//     m_colourSpace = colourSpace;

			//     m_bitmapData.clear();
			//     m_bitmapData.reserve(m_height);

			//     for(size_t i = 0; i < m_height && i < bitmap_Data.size(); ++i){
			//         for(size_t j = 0; i < m_height &&)
			//     }
			// }

		public:
			explicit Image(
					const size_t x,
					const size_t y,
					const size_t pixelSize = 3,
					const int colourSpace = 2
			);

			// Currently can only construct with an existing file.
			// Will throw if file cannot be loaded, or is in the wrong format,
			// or some other error is encountered.
			explicit Image( const std::string& fileName );

			// We can construct from an existing image object. This allows us
			// to work on a copy (e.g. shrink then save) without affecting the
			// original we have in memory.
			Image( const Image& rhs );

			// But assigment and move operations are currently disallowed
			// Image& operator=( const Image& );
			// Image( Image&& )                 = delete;
			// Image& operator=( Image&& )      = delete;

			// pass in the values
			// Image(size_t m_width, size_t m_height, size_t m_pixelSize);
			// Image(size_t, size_t, size_t) = delete;
			~Image();

			Image();

			// Will throw if file cannot be saved. If no
			// filename is supplied, writes to fileName supplied in load()
			// (if that was called, otherwise throws)
			// Quality's usable values are 0-100
			void save( const std::string& fileName, int quality = 95 ) const;

			// Mainly for testing, writes an uncompressed PPM file
			void savePpm( const std::string& fileName ) const;

			size_t getHeight()    const { return m_height; }
			size_t getWidth()     const { return m_width;  }
			size_t getPixelSize() const { return m_pixelSize; }

			// Will return a vector of pixel components. The vector's
			// size will be 1 for monochrome or 3 for RGB.
			// Elements for the latter will be in order R, G, B.
			std::vector<uint8_t> getPixel( size_t x, size_t y ) const;

			void setPixel(size_t x, size_t y, std::vector<uint8_t> pixelValue);
			// void setPixel(size_t x, size_t y, size_t pixelValue) const;

			// Returns a fast approximation of perceived brightness for RGB images.
			// For monochrome, will just return the pixel's value directly.
			uint8_t getLuminance( size_t x, size_t y ) const;

			// Get average of a box of pixels, returns a vector<uint8_t> of
			// size 1 for monochrome or three for RGB.
			// Note x & y specify the top left pixel of the box.
			// If the box runs off the end of the row or column then it is
			// shifted left/up to fit which means averages may be a little
			// odd near the right edge / bottom :)
			std::vector<uint8_t> getAverage( size_t x, size_t y, size_t boxSize ) const;

			// Shrink (resize smaller, retaining proportion). Does nothing
			// if the specified new width is larger than the existing width.
			// Simply averages pixels' values.
			void shrink( size_t newWidth );

			// Expand (resize larger). Simply pads out pixels.
			// Does nothing if the specified new width is less than, or
			// equal to the existing width.
			void expand( size_t newWidth );

			// Convenience function which either calls shrink or expand
			void resize( size_t newWidth );

		};

	} // namespace jpeg
} // namespace marengo
