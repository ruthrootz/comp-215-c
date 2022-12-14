// /*
//     name: Ruth Oldja
//     date: 11/3/2022
//     purpose: convert an array of hexadecimal numbers into decimal integers
// */

// #include <stdio.h>
// #include <math.h>
// #include "htoi.h"

// int main(void) {
//     printf("%d\n", htoi("0X1"));
//     printf("%d\n", htoi("0x1"));
//     printf("%d\n", htoi("97"));
//     printf("%d\n", htoi("0X7B"));
//     printf("%d\n", htoi("0Xaa"));
//     printf("%d\n", htoi("AA"));
//     printf("%d\n", htoi("ff"));
//     printf("%d\n", htoi("FF"));
//     printf("%d\n", htoi("0x12345"));
//     printf("%d\n", htoi("0x1a2B3Cf"));
//     printf("%d\n", htoi("FFff"));
//     printf("%d\n", htoi("0X0"));
    
//     return 0;
// }

// int htoi(char hexString[])
// {
//     int decimalValue = 0;
//     int placeValue = 0;
//     int startingIndex = strlen(hexString) - 1;
//     int endingIndex = 0;
//     if (hexString[1] == 'x' || hexString[1] == 'X')
//     {
//         endingIndex = 2;
//     }

//     for (int i = startingIndex; i >= endingIndex; i--)
//     {
//         int convertedDigit = hexToDecimal(hexString[i], pow(16, placeValue));
//         placeValue++;
//         decimalValue += convertedDigit;
//     }

//     return decimalValue;
// }

// int hexToDecimal(char hexDigit, int placeValue)
// {
//     int intValueOfChar = 0;
    
//     if (hexDigit >= 'a' && hexDigit <= 'f')
//     {
//         intValueOfChar = hexDigit - 87;
//     }
//     else if (hexDigit >= 'A' && hexDigit <= 'F')
//     {
//         intValueOfChar = hexDigit - 55;
//     }
//     else if (hexDigit >= '0' && hexDigit <= '9')
//     {
//         intValueOfChar = hexDigit - 48;
//     }
    
//     int decimalValue = intValueOfChar * placeValue;
    
//     return decimalValue;
// }
