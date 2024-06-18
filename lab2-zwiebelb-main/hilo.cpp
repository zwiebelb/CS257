#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  int secret;
  int guess;
  int tries = 0;
  srand(time(0));
  secret = (rand() % 100 + 1);  // random number generator between 1 and 100

  while (guess != secret) {
    cout << "\nPlease enter a number between 1 and 100: ";
    cin >> guess;

    if (guess > secret) {
      cout << guess << " is larger than the secret number. Please try again."
           << endl;
    } else if (guess < secret) {
      cout << guess << " is lower than the secret number. Please try again."
           << endl;
    } else {
      cout << guess << " is the correct number. Good job!" << endl;
    }
    tries += 1;
  }
  cout << "\nIt took you " << tries << " tries to guess the correct number."
       << endl;

  return 0;
}
