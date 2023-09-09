// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Image_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Sets various pixels in a 2x2 Image and checks
// that Image_print produces the correct output.
TEST(test_print_basic) {
  Image *img = new Image; // create an Image in dynamic memory

  const Pixel red = {255, 0, 0};
  const Pixel green = {0, 255, 0};
  const Pixel blue = {0, 0, 255};
  const Pixel white = {255, 255, 255};

  Image_init(img, 2, 2);
  Image_set_pixel(img, 0, 0, red);
  Image_set_pixel(img, 0, 1, green);
  Image_set_pixel(img, 1, 0, blue);
  Image_set_pixel(img, 1, 1, white);

  // Capture our output
  ostringstream s;
  Image_print(img, s);

  // Correct output
  ostringstream correct;
  correct << "P3\n2 2\n255\n";
  correct << "255 0 0 0 255 0 \n";
  correct << "0 0 255 255 255 255 \n";
  ASSERT_EQUAL(s.str(), correct.str());

  delete img; // delete the Image
}

// IMPLEMENT YOUR TEST FUNCTIONS HERE
// You are encouraged to use any functions from Image_test_helpers.h as needed.

// Initializes two 2x2 Images with various Pixels by 
// passing the function with different paramters 
// (width and height vs. istream) and checks if 
// their properties are correct. 
TEST(test_both_init) {

  // Testing 3 parameters (img,width,height)
  Image *img1 = new Image; 

  Image_init(img1, 2, 2);

  ASSERT_EQUAL(Image_width(img1), 2);
  ASSERT_EQUAL(Image_height(img1), 2);

  Pixel red = {255, 0, 0};
  Pixel green = {0, 255, 0};
  Pixel blue = {0, 0, 255};
  Pixel white = {255, 255, 255};
  Image_set_pixel(img1, 0, 0, red);
  Image_set_pixel(img1, 0, 1, green);
  Image_set_pixel(img1, 1, 0, blue);
  Image_set_pixel(img1, 1, 1, white);

  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img1, 0, 0), red), true);
  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img1, 0, 1), green), true);
  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img1, 1, 0), blue), true);
  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img1, 1, 1), white), true);

  delete img1;

  // Testing 2 parameters (img, input)

  stringstream input;
               input << "P3\n2 2\n255\n"
                     << "255 0 0 0 255 0 \n"
                     << "0 0 255 255 255 255 \n";

  Image *img2 = new Image;
  Image_init(img2, input);

  ASSERT_EQUAL(Image_width(img2), 2);
  ASSERT_EQUAL(Image_width(img2), 2);
  ASSERT_EQUAL(Image_get_pixel(img2, 0, 0).r, 255);
  ASSERT_EQUAL(Image_get_pixel(img2, 0, 0).g, 0);
  ASSERT_EQUAL(Image_get_pixel(img2, 0, 0).b, 0);

  delete img2; 
}

// Initializes a 1x3 Image and 500x500 Image and checks
// if the width and height are correct.
TEST(test_width_and_height) {

  Image *img1 = new Image; 

  Image_init(img1, 1, 3);

  ASSERT_EQUAL(Image_width(img1), 1);
  ASSERT_EQUAL(Image_height(img1), 3);
  
  delete img1;

  Image *img2 = new Image; 

  Image_init(img2, 500, 500);

  ASSERT_EQUAL(Image_width(img2), 500);
  ASSERT_EQUAL(Image_height(img2), 500);
  
  delete img2;
}

// Initializes a 4x1 Image and sets four different Pixels and checks
// if the returned Pixels are correct. Then a second 4x1 Image is 
// initialized with four of the same Pixel and checks if the returned
// Pixels are correct. 
TEST(test_get_Pixel) {

  Image *img1 = new Image; 

  Image_init(img1, 4, 1);

  Pixel red = {255, 0, 0};
  Pixel green = {0, 255, 0};
  Pixel blue = {0, 0, 255};
  Pixel white = {255, 255, 255};
  Image_set_pixel(img1, 0, 0, red);
  Image_set_pixel(img1, 0, 1, green);
  Image_set_pixel(img1, 0, 2, blue);
  Image_set_pixel(img1, 0, 3, white);
  
  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img1, 0, 0), red), true);
  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img1, 0, 1), green), true);
  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img1, 0, 2),  blue), true);
  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img1, 0, 3), white), true);
 
  delete img1;

  Image *img2 = new Image; 

  Image_init(img2, 4, 1);
  Image_set_pixel(img2, 0, 0, red);
  Image_set_pixel(img2, 0, 1, red);
  Image_set_pixel(img2, 0, 2, red);
  Image_set_pixel(img2, 0, 3, red);

  for(int x = 0; x < Image_width(img2); x++) {
     ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img2,0, x), red), true);
  }

  delete img2;
}

// Initializes a 2x2 Image and sets all the Pixels to red before checking
// the return output. Then all the pixels are set to green before checking
// the return output. Then two specific pixels are set to blue before
// checking the return output. 
TEST(test_set_Pixel) {
  Image *img = new Image; 

  Image_init(img, 2, 2);
  Pixel red = {255, 0, 0};
  Pixel green = {0, 255, 0};
  Pixel blue = {0, 0, 255};

  for(int x = 0; x < 2; x++){
    for(int y = 0; y < 2; y++){
       Image_set_pixel(img, x, y, red);
       ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, x, y), red), true);
    }
  }
  for(int x = 0; x < 2; x++){
    for(int y = 0; y < 2; y++){
       Image_set_pixel(img, x, y, green);
       ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, x, y), green), true);
    }
  }
  
  Image_set_pixel(img, 0, 1, blue);
  Image_set_pixel(img, 1, 0, blue);
  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 0), green), true);
  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 0, 1), blue), true);
  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 1, 0), blue), true);
  ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img, 1, 1), green), true);

  delete img;
}

// Initializes a 2x2 Image and fills it with red Pixels before checking 
// if each Pixel is a red Pixel. Then initializes a 3x1 Image and fills it
// with red Pixels before checking if each Pixel is a red Pixel.
TEST(test_Image_fill) {
  Image *img1 = new Image; 

  Image_init(img1, 2, 2);
  Pixel red = {255, 0, 0};

  Image_fill(img1, red);
  for(int x = 0; x < 2; x++){
    for(int y = 0; y < 2; y++){
       ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img1, x, y), red), true);
    }
  }

  delete img1;

  Image *img2 = new Image; 

  Image_init(img2, 3, 1);

  Image_fill(img2, red);
  for(int x = 0; x < 1; x++){
    for(int y = 0; y < 3; y++){
       ASSERT_EQUAL(Pixel_equal(Image_get_pixel(img2, x, y), red), true);
    }
  }

  delete img2;
}
// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
