CXX = g++
CXXFLAGS = -O3 -Wall -Wextra -Wpedantic -Werror -ljpeg -std=c++17
UNIXFLAGS = -undefined dynamic_lookup
PYFLAGS = -shared -Dpywrapper -fPIC

ifneq ($(OS),Windows_NT)     # is Windows_NT on XP, 2000, 7, Vista, 10...
    PYFLAGS += -undefined dynamic_lookup
endif

test: main.cpp ImgLibrary.cpp jpeg.cpp
	$(CXX) $(CXXFLAGS) $(LFLAGS) -o test main.cpp ImgLibrary.cpp jpeg.cpp

python: ImgLibrary.cpp jpeg.cpp
	$(CXX) $(CXXFLAGS) $(LFLAGS) $(PYFLAGS) `python3 -m pybind11 --includes` ImgLibrary.cpp jpeg.cpp -o ImgLibrary`python3-config --extension-suffix`

clean:
	rm -f test		#CPP Executable
	rm -f *.so		#Python wrapper binary
	rm -f output*		#All output images named output*
	rm -f *.o		#Object files