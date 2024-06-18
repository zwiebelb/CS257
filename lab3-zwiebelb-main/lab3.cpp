#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int exercise0() { return 4; }  // passed

double exercise1(double x1, double y1, double x2, double y2) {  // passed
  double distance = sqrt((pow(x2 - x1, 2)) + (pow(y2 - y1, 2)));
  return distance;
}

unsigned int exercise2(string s) {  // passed
  int count = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
      count++;
  }
  return count;
}

int exercise3(int n) {  // passed
  double result;
  for (int i = 1; i <= n; i++) {
    result += i;
  }
  return result;
}

string exercise4(string s) {  // passed //can use swap or reverse fumction
  int length = s.size();
  char reversed;
  for (int i = 0; i < length / 2; i++) {
    reversed = s[i];
    s[i] = s[length - i - 1];
    s[length - i - 1] = reversed;
  }
  return s;
}

bool exercise5(string s) {  // passed
  bool palindrome;
  int len = s.size() - 1;
  for (int i = 0; i < len;
       i++, len--) {  // for the length of the word, add 1 to i and subtract 1
                      // from the length, so it splits the string in half and
                      // gets each indvidual character.
    if (s[i] != s[len]) {  // tests the first and last character, then second
                           // and second to last... to see if the characters are
                           // the same
      palindrome = false;
      return palindrome;
    }
  }
  palindrome = true;
  return palindrome;
}

bool exercise6(bool x, bool y) {  // passed
  if (x && !y) {
    return true;
  }
  if (!x && y) {
    return true;
  } else {
    return false;
  }
}

string exercise7(string s) {  // passed
  int len = s.size();
  for (int i = 0; i < len; i++) {
    if (s[i] == 'e') {
      s[i] = '3';
    }
    if (s[i] == 'a') {
      s[i] = '4';
    }
  }
  return s;
}

string exercise8(string s) {  // passed
  int len = s.size();
  string result;
  int rotate = 13;
  for (int i = 0; i < len; i++) {
    result += (int(s[i] + rotate - 97) % 26 + 97);
  }
  return result;
}

int exercise9(int x, int y, int z) {  // passed
  int maximum = z;
  if (y > maximum) {
    maximum = y;
  } else if (x > maximum) {
    maximum = x;
  }
  return maximum;
}