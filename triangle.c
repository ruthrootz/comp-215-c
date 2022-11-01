// name: Ruth Oldja
// purpose: output a triangle of n rows, where n is user input, an integer between 1 and 20 (inclusive)
// date: 11/1/2022

#include <stdio.h>

int main(void) {
  // get user input
  int rows;
  printf("Enter a number [1, 20]: ");
  scanf("%d", &rows);

  // validate user input
  while (!(rows <= 20 && rows >= 1)) {
    printf("Enter a number [1, 20]: ");
    scanf("%d", &rows);
  }

  // figure out how long each line will be
  int columns = 2 * rows - 1;

  for (int i = 0; i < rows; i++) {
    // if this is the last row:
    if (i == rows - 1) {
      for (int j = 0; j < columns; j++) {
        printf("*");
      }
    }
    // otherwise:
    else {
      for (int j = 1; j <= columns; j++) {
        if (j == rows - i || j == columns - (rows - i - 1)) {
          printf("*");
        } else {
          printf(" ");
        }
      }
    }

    printf("\n");
  }

  return 0;
}
