/*
Plate Date

The MIT License (MIT)

Copyright (c) 2014 Derek Chafin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <stdio.h>
#include <stdbool.h>

/*
Source: http://en.wikipedia.org/wiki/Vehicle_registration_plates_of_Missouri#Month_coding
Month     | Codes
January   | A, B
February  | C
March     | D, E
April     | F, G
May       | H, J
June      | K, L
July      | M, N
August    | P, R
September | S, T
October   | U, V
November  | W, X
December  | Y, Z
 */

const char *months[12] =
{
  "January",
  "February",
  "March",
  "April",
  "May",
  "June",
  "July",
  "August",
  "September",
  "October",
  "November",
  "December"
};

void about();
void flushinput();
int getmonth(char input);
bool again();

int main (void)
{
  int month;
  char letter;

  about();

  while (true)
  {
    printf("Enter the first letter of your license plate: ");
    scanf("%1c", &letter);
    printf("\n");

    if (isupper(letter))
      letter = tolower(letter);

    // Consume all other chars
    flushinput();

    month = getmonth(letter);

    if (month < 0)
    {
      puts("Invalid letter.");
      if (again())
        continue;
      else
        break;
    }

    printf("Your license plate registration month is %s\n", months[month]);
    if (again())
      continue;
    else
      break;
  }

  return 0;
}

void about()
{
  puts("This is a small C demo program.");
  puts("Input the first letter of a post-2006 Missouri license plate.");
  puts("It will output the registration month of that license.");
  puts("Source: http://en.wikipedia.org/wiki/Vehicle_registration_plates_of_Missouri#Month_coding");
  puts("");
}

void flushinput()
{
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
  return;
}

bool again()
{
  char keepgoing;
  printf("Would you like to try another letter? [y/n] ");
  scanf("%1c", &keepgoing);
  printf("\n");
  flushinput();
  return keepgoing == 'y' || keepgoing == 'Y';
}

int getmonth(char input)
{
  switch (input)
  {
  case 'a':
  case 'b':
    return 0;
  case 'c':
    return 1;
  case 'd':
  case 'e':
    return 2;
  case 'f':
  case 'g':
    return 3;
  case 'h':
  case 'j':
    return 4;
  case 'k':
  case 'l':
    return 5;
  case 'm':
  case 'n':
    return 6;
  case 'p':
  case 'r':
    return 7;
  case 's':
  case 't':
    return 8;
  case 'u':
  case 'v':
    return 9;
  case 'w':
  case 'x':
    return 10;
  case 'y':
  case 'z':
    return 11;
  default:
    return -1;
  }
}