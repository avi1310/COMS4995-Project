.PHONY: clean

opencv:
	g++ $(pkg-config --cflags --libs opencv4) -std=c++14 performance_opencv.cpp -o test_opencv

imglib:
	g++ -O3 -std=c++14 -Wall -Wextra -Wpedantic -Werror performance_imglib.cpp -o test_imglib -ljpeg -v
# 	g++ -O3 -Wall -Wextra -Wpedantic -Werror -shared -ljpeg -std=c++17 -undefined dynamic_lookup -fPIC `python3 -m pybind11 --includes` performance_imglib.cpp -o ImgLibrary`python3-config --extension-suffix`

clean:
	rm -rf test_*