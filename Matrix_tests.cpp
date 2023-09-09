// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"
#include <iostream>

using namespace std;

// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.

TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
  
  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

// Initializes a 4x5 Matrix and checks
// that its properties are correct.
TEST(test_Matrix_init){
  Matrix *mat = new Matrix; 
  Matrix_init(mat, 4, 5);

  ASSERT_EQUAL(Matrix_width(mat), 4);
  ASSERT_EQUAL(Matrix_height(mat), 5);

  delete mat;
}

// Initializes a 500x500 Matrix and checks
// if its properties are correct
TEST(test_Matrix_init2){
  Matrix *mat = new Matrix; 
  Matrix_init(mat, 500, 500);

  ASSERT_EQUAL(Matrix_width(mat), 500);
  ASSERT_EQUAL(Matrix_height(mat), 500);

  delete mat;
}

// Initializes a 4x4 Matrix, fills it with 69s,
// checks if it prints correctly, then fills 
// the border with 0s and checks if it prints
// correctly. 
TEST(test_matrix_print_basic) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 69);
  ostringstream expected1; //For regular fill
  ostringstream expected2; //Adding a border
  ostringstream result1;   
  ostringstream result2;

  expected1 << "4 4\n"
           << "69 69 69 69 \n"
           << "69 69 69 69 \n"
           << "69 69 69 69 \n"
           << "69 69 69 69 \n";
  Matrix_print(mat, result1);
  ASSERT_EQUAL(expected1.str(), result1.str());

  Matrix_fill_border(mat, 0);
  expected2 << "4 4\n"
            << "0 0 0 0 \n"
            << "0 69 69 0 \n"
            << "0 69 69 0 \n"
            << "0 0 0 0 \n";

  Matrix_print(mat, result2);
  ASSERT_EQUAL(expected2.str(), result2.str());
  
  delete mat;
}

// Initializes a 1x1 Matrix, fills it with 69s,
// checks if it prints correctly, then fills 
// the border with 0s and checks if it prints
// correctly. 
TEST(test_matrix_print_1x1) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);
  Matrix_fill(mat, 69);
  ostringstream expected1; //For regular fill
  ostringstream expected2; //Adding a border
  ostringstream result1;   
  ostringstream result2;

  expected1 << "1 1\n"
            << "69 \n";
  Matrix_print(mat, result1);
  ASSERT_EQUAL(expected1.str(), result1.str());

  Matrix_fill_border(mat, 0);
  expected2 << "1 1\n"
            << "0 \n";

  Matrix_print(mat, result2);
  ASSERT_EQUAL(expected2.str(), result2.str());
  
  delete mat;
}

// Initializes a 1x5 Matrix, fills it with 69s,
// checks if it prints correctly, then fills 
// the border with 0s and checks if it prints
// correctly. 
TEST(test_matrix_print_column) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 5);
  Matrix_fill(mat, 69);
  ostringstream expected1; //For regular fill
  ostringstream expected2; //Adding a border
  ostringstream result1;   
  ostringstream result2;

  expected1 << "1 5\n"
            << "69 \n"
            << "69 \n"
            << "69 \n"
            << "69 \n"
            << "69 \n";

  Matrix_print(mat, result1);
  ASSERT_EQUAL(expected1.str(), result1.str());

  Matrix_fill_border(mat, 0);
  expected2 << "1 5\n"
            << "0 \n"
            << "0 \n"
            << "0 \n"
            << "0 \n"
            << "0 \n";

  Matrix_print(mat, result2);
  ASSERT_EQUAL(expected2.str(), result2.str());
  
  delete mat;
}

// Initializes a 5x1 Matrix, fills it with 69s,
// checks if it prints correctly, then fills 
// the border with 0s and checks if it prints
// correctly. 
TEST(test_matrix_print_row) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 1);
  Matrix_fill(mat, 69);
  ostringstream expected1; //For regular fill
  ostringstream expected2; //Adding a border
  ostringstream result1;   
  ostringstream result2;

  expected1 << "5 1\n"
            << "69 69 69 69 69 \n";

  Matrix_print(mat, result1);
  ASSERT_EQUAL(expected1.str(), result1.str());

  Matrix_fill_border(mat, 0);
  expected2 << "5 1\n"
            << "0 0 0 0 0 \n";

  Matrix_print(mat, result2);
  ASSERT_EQUAL(expected2.str(), result2.str());
  
  delete mat;
}

// Initializes a 4x4 Matrix, fills it with 69s,
// then initialzes 3 pointers pointing to elements
// {0,0}, {1,2}, {3,3} ({row, column}) in the Matrix
// and checks if the returned row is correct for each. 
TEST(test_Matrix_row){
  Matrix *mat = new Matrix; 
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 69);

  int *ptr1 = Matrix_at(mat,0,0);
  ASSERT_EQUAL(Matrix_row(mat,ptr1),0);
  int *ptr2 = Matrix_at(mat,1,2);
  ASSERT_EQUAL(Matrix_row(mat,ptr2),1);
  int *ptr3 = Matrix_at(mat,3,3);
  ASSERT_EQUAL(Matrix_row(mat,ptr3),3);
  delete mat;
}

// Initializes a 4x4 Matrix, fills it with 69s,
// then initialzes 3 pointers pointing to elements
// {0,0}, {1,2}, {3,3} ({row, column}) in the Matrix
// and checks if the returned column is correct for each. 
TEST(test_Matrix_column){
  Matrix *mat = new Matrix; 
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 69);

  int *ptr1 = Matrix_at(mat,0,0);
  ASSERT_EQUAL(Matrix_column(mat,ptr1),0);
  int *ptr2 = Matrix_at(mat,1,2);
  ASSERT_EQUAL(Matrix_column(mat,ptr2),2);
  int *ptr3 = Matrix_at(mat,3,3);
  ASSERT_EQUAL(Matrix_column(mat,ptr3),3);
  delete mat;
}

// Initializes a 4x4 Matrix, fills it with 69s,
// then checks to see if the pointer value returned at
// element {0,0} is correct.
// Then manually sets the element {0,0} to 0 using the 
// function and checks again if the return pointer value
// at element {0,0} is correct.
// Then the border is filled with 21, and the values of 
// pointers at each corner are checked, before checking
// a returned pointer value outside of the border. 
TEST(test_Matrix_at){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 69);

  ASSERT_EQUAL(*Matrix_at(mat,0,0),69);

  *Matrix_at(mat,0,0) = 0;

  ASSERT_EQUAL(*Matrix_at(mat,0,0),0);

  Matrix_fill_border(mat,21);

  ASSERT_EQUAL(*Matrix_at(mat,0,0), 21);
  ASSERT_EQUAL(*Matrix_at(mat,0,3), 21);
  ASSERT_EQUAL(*Matrix_at(mat,3,0), 21);
  ASSERT_EQUAL(*Matrix_at(mat,3,3), 21);
  ASSERT_EQUAL(*Matrix_at(mat,2,2), 69);

  delete mat;
}

// Initializes a 4x4 Matrix, fills it with 69s and sets the border
// to 21s.
// Then the matrix is traversed and each individual element is checked
// to ensure only the bordering elements were changed. 
TEST(test_Matrix_fill_border){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 69);
  Matrix_fill_border(mat, 21);
  for(int row = 0; row < Matrix_height(mat); row++){
     for(int col = 0; col < Matrix_width(mat); col++){
       if(row == 0 || row == Matrix_height(mat) - 1){
         ASSERT_EQUAL(*Matrix_at(mat, row, col),21);
       }
       else if(col == 0 || col == Matrix_width(mat) -1){
         ASSERT_EQUAL(*Matrix_at(mat, row, col),21);
       }
       else{
         ASSERT_EQUAL(*Matrix_at(mat, row, col),69);
       }
  } 
  }
  delete mat;
}

// Initializes a 4x4 Matrix, fills it with 69s and sets the border
// to 21s.
// Then the border is changed to a smaller value than the current max,
// the maximum value is checked, then the border is changed to a larger
// value than the current max before the maximum value is checked. Finally,
// a specific element is changed to a value larger than the current max before
// the maximum value is checked.
TEST(test_Matrix_max){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 69);
  ASSERT_EQUAL(Matrix_max(mat),69);
  Matrix_fill_border(mat, 21);
  ASSERT_EQUAL(Matrix_max(mat),69);
  Matrix_fill_border(mat, 90);
  ASSERT_EQUAL(Matrix_max(mat),90);
  *Matrix_at(mat,2,2) = 99;
  ASSERT_EQUAL(Matrix_max(mat),99);
  delete mat;
}

// Initializes a 4x4 Matrix, fills it with 69s and checks for
// the correct, left-most columns at specific ranges. 
// Then, the border is filled with 21s before checking for 
// the correct, left-most columns at specific ranges. 
TEST(test_Matrix_column_of_min_value_in_row){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 69);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,2,0,4),0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,2,1,3),1);
  Matrix_fill_border(mat, 21);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,0,0,4),0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,1,0,3),0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,1,0,4),0);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,1,1,3),1);
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat,1,2,4),3);
  delete mat;
}

// Initializes a 4x4 Matrix, fills it with 69s and checks for
// the correct, left-most minimum values at specific ranges. 
// Then, the border is filled with 21s before checking for 
// the correct, left-most minimum values at specific ranges. 
TEST(test_Matrix_min_value_in_row){
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory
  Matrix_init(mat, 4, 4);
  Matrix_fill(mat, 69);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat,2,0,4),69);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat,2,1,3),69);
  Matrix_fill_border(mat, 21);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat,0,0,4),21);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat,1,0,3),21);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat,1,0,4),21);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat,1,1,3),69);
  ASSERT_EQUAL(Matrix_min_value_in_row(mat,1,2,4),21);
  delete mat;
}

// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
