import unittest
import ImgLib  # our `pybind11`-based extension module

class MainTest(unittest.TestCase):
    def test_grayScale(self):
        # test that 1 + 1 = 2

        print("hello")
        #print(ImgLib.__dict__)
        dir(ImgLib)

        p = ImgLib.ImgLibrary("test.jpg")
        print(p)
        # p.grayScale()
        self.assertEqual(1, 1)


