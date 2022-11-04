/*
    name: Ruth Oldja
    date: 11/3/2022
    purpose: convert an array of hexadecimal numbers into decimal integers
*/

#include <stdio.h>
#include "htoi.h"

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

int htoi(char hexString[])
{
  int decimalValue = 0;
  int placeValue = 1;

  for (int i = strlen(hexString); i > 0; i--)
  {
    if (hexString[i] == '\0')
    {
      continue;
    }
    else if (hexString[i] == 'x' || hexString[i] == 'X')
    {
      break;
    }

    int convertedDigit = hexToDecimal(hexString[i], placeValue);
    placeValue *= 16;
    decimalValue += convertedDigit;
  }

  return decimalValue;
}

int hexToDecimal(char hexDigit, int placeValue)
{
  int intValueOfChar = 0;
  if (hexDigit >= 'a' && hexDigit <= 'f')
  {
    intValueOfChar = hexDigit - 87;
  }
  else if (hexDigit >= 'A' && hexDigit <= 'F')
  {
    intValueOfChar = hexDigit - 55;
  }
  else if (hexDigit >= 0 && hexDigit <= 9)
  {
    intValueOfChar = hexDigit - 48;
  }

  int decimalValue = hexDigit * placeValue;

  return decimalValue;
}
