/*
    name: Ruth Oldja
    date: 11/3/2022
    purpose: convert an array of hexadecimal numbers into decimal integers
*/

#include <stdio.h>
#include <htoi.h>

int main(void) {
  // TESTS:
  // 0X
  // 0x
  // lowercase a-f
  // uppercase A-F
  // zero
  // MAX
  return 0;
}

int[] htoi(char hexString[])
{
  // create a new array of the same length as the input
  // check if second char is x or X
    // if it is, remove first two chars
  // loop through input (while checking for \0)
    // convert each hexadecimal number
    // add converted number to array
  // return array
}

/*
 * call hexToDecimal(char hex[])
 * ^ on each string
 * ignore 0x and 0X
 * in hexToDecimal: loop through array from the end, multiple each digit by 16 ^ i, where i starts at 0 and goes up each loop through
 * convert each char into an int: char value -48 for 0-9, -55 for A-F, -87 for a-f
 */
