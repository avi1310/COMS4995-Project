.PHONY: debug, clean

test:
# 	g++ -O3 -std=c++14 -Wall -Wextra -Wpedantic -Werror -o test *.cpp -ljpeg
	g++ -O3 -Wall -Wextra -Wpedantic -Werror -shared -ljpeg -std=c++17 -undefined dynamic_lookup -fPIC `python3 -m pybind11 --includes` *.cpp -o ImgLibrary`python3-config --extension-suffix`

debug:
# 	g++ -g -O0 -std=c++14 -Wall -Wextra -Wpedantic -Werror -o test *.cpp -ljpeg
	g++ -O3 -O0 -Wall -Wextra -Wpedantic -Werror -shared -ljpeg -std=c++17 -undefined dynamic_lookup -fPIC `python3 -m pybind11 --includes` *.cpp -o ImgLibrary`python3-config --extension-suffix`

clean:
	rm -f test
	rm -f *.so
	rm -f output*