#include <iostream>
using namespace std;

int main() {
  const int SECRET = 42;
  int guess = 0;
  int tries = 0;

  while (guess != SECRET) {
    cout << "\nPlease enter a random integer: ";
    cin >> guess;

    if (guess > SECRET) {
      cout << guess << " is larger than the secret number. Please try again."
           << endl;
    } else if (guess < SECRET) {
      cout << guess << " is lower than the secret number. Please try again."
           << endl;
    } else {
      cout << guess << " is the secret number. Good job!" << endl;
    }
    tries += 1;
  }
  cout << "\nIt took you " << tries << " tries to guess the secret number correctly."
       << endl;

  return 0;
}
