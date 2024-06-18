/*! \file main.cpp
    \brief The main source file for lab 4 three men's morris.
*/

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "brain.h"
#include "three_mens_morris.h"

using namespace std;

int main() {
  Board board(3, vector<int>(3, 0));
  int phase = 1;
  string input;
  string user;
  Move computer;
  int PlayerPieces = 3;
  int AiPieces = 3;

  while (GameOver(board) == -1) {
 cout << "----Updated Board----" <<endl;
    PrintBoard(board);
    if (phase == 1) {
      cout << "Please enter a move from a1 - c3: " << endl;
      getline(cin, input);
      if (input.size() == 2) {
        // phase = 1;
        Move parsed = ParseMove(phase, input);
        while (ValidMove(phase, 1, board, parsed) == false) {
          PrintBoard(board);
          cout << "Please enter a move from a1 - c3:" << endl;
          getline(cin, input);
          parsed = ParseMove(phase, input);
        }
        SetPlayerAtSpace(board, 1, parsed.second);
        PlayerPieces--;

        Move computer = GalaxyBrain(phase, board);
        while (ValidMove(phase, 2, board, computer) == false) {
          computer = GalaxyBrain(phase, board);
        }
        SetPlayerAtSpace(board, 2, computer.second);
        AiPieces--;
        if (PlayerPieces == 0 && AiPieces == 0) {
          phase = 2;
        cout << "----Updated Board----" <<endl;
          PrintBoard(board);
        cout << "----You have entered phase 2----" <<endl;
        }
      }
    }
    if (phase == 2 && GameOver(board) == -1) {
      cout << "Please enter where you would like to move from and to (eg. from "
              "a3 "
              "to b3 would be a3b3): " << endl;
      getline(cin, user);
      if (user.size() == 4) {
        Move parse = ParseMove(2, user);
        while (ValidMove(phase, 1, board, parse) == false) {
          PrintBoard(board);
          cout << "Please enter where you would like to move from and to (eg. "
                  "from "
                  "a3 "
                  "to b3 would be a3b3): " << endl;
          getline(cin, user);
          parse = ParseMove(2, user);
        }
        SetPlayerAtSpace(board, 0, parse.first);
        SetPlayerAtSpace(board, 1, parse.second);
        cout << "----Updated Board----" <<endl;
        PrintBoard(board);
        cout << "----Please wait while the computer makes its move.----" <<endl;
        Move computer = GalaxyBrain(phase, board);
        while (ValidMove(phase, 2, board, computer) == false) {
          computer = GalaxyBrain(phase, board);
        }
        SetPlayerAtSpace(board, 0, computer.first);
        SetPlayerAtSpace(board, 2, computer.second);
      }
    }
  }
  if (GameOver(board) == 1) {
cout << "----Game over!----" <<endl;
    PrintBoard(board);
    cout << "You won!" << endl;
  } else if (GameOver(board) == 2) {
    PrintBoard(board);
    cout << "You lost!" << endl;
  }
  return 0;
}

int GameOver(const Board board) {

  if ((board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 1) ||
      (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 1) ||
      (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 1) ||
      (board[0][0] == 1 && board[1][0] == 1 && board[1][2] == 1) ||
      (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 1) ||
      (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 1)) {
    return 1;
  } else if ((board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 2) ||
             (board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 2) ||
             (board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 2) ||
             (board[0][0] == 2 && board[1][0] == 2 && board[1][2] == 2) ||
             (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 2) ||
             (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 2)) {
    return 2;
  } else {
    return -1;
  }
}

void PrintBoard(Board board) {
  // print board
  cout << "  ";
  for (char ch = 'a'; ch <= 'c'; ++ch) {
    cout << "" << ch << " ";
  }
  cout << endl;
  for (unsigned int row = 0; row < board.size(); ++row) {
    cout << 1 + row << " ";
    for (unsigned int col = 0; col < board[row].size(); ++col) {
      cout << board[row][col] << " ";
    }
    cout << endl;
  }
}

int PlayerAtSpace(const Board board, const BoardIndex space) {
  // 0 for unoccupied
  // 1 for player 1
  // 2 for computer
  return board[space.first][space.second];
}

void SetPlayerAtSpace(Board &board, const int player, const BoardIndex space) {
  // change space to player moving there
  board[space.first][space.second] = player;
}

Move ParseMove(int phase, const string move) {
  if (phase == 1) {
    Move ret;
    ret.first = ParseSpace("a4");
    ret.second = ParseSpace(move);
    return ret;
  } else {
    Move ret;
    string origin = move.substr(0, 2);
    BoardIndex original = ParseSpace(origin);
    string moving = move.substr(2, 5);
    BoardIndex movePiece = ParseSpace(moving);
    ret.first = original;
    ret.second = movePiece;
    return ret;
  }
}

BoardIndex ParseSpace(const string &space) {
  BoardIndex ret;
  // split the string into the letter and number
  char col = space.at(0);
  char row = space.at(1);

  // change letter to a number for column
  if (col == 'a') {
    ret.second = 0;
  } else if (col == 'b') {
    ret.second = 1;
  } else if (col == 'c') {
    ret.second = 2;
  }
  // subtract 1 from row
  ret.first = row - '0' - 1;
  return ret;
}

bool ValidMove(int phase, int player, const Board board, Move move) {
  while (phase == 1) {
    int row = move.second.first;  // error
    int col = move.second.second;

    if (row < 0 || row > 2)  // check bounds
    {
      cout << "Your row is out of bounds. Please try again." << endl;
      return false;
    } else if (col < 0 || col > 2) {
      cout << "Your column is out of bounds. Please try again" << endl;
      return false;
    } else if (board[row][col] != 0) {
      if (player == 1) {
        cout << "Already occupied. Choose again." << endl;
        return false;
      } else if (player == 2) {
        return false;
      }
    } else
      return true;
  }
  while (phase == 2) {
    if (board[move.first.first][move.first.second] != player) {
      if (player == 1) {
        cout << "That is not your piece to move" << endl;
        return false;
      }
      if (player == 2) {
        return false;
      }
    } else if (board[move.second.first][move.second.second] != 0) {
      if (player == 1) {
        cout << "This space is already occupied. Please try again" << endl;
        return false;
      }
      if (player == 2) {
        return false;
      }
    } else if ((move.first.first == 0 && move.first.second == 0) &&
               ((move.second.first == 1 && move.second.second == 0) ||
                (move.second.first == 0 && move.second.second == 1))) {
      return true;
    } else if ((move.first.first == 1 && move.first.second == 0) &&
               ((move.second.first == 0 && move.second.second == 0) ||
                (move.second.first == 2 && move.second.second == 0) ||
                (move.second.first == 1 && move.second.second == 1))) {
      return true;
    } else if ((move.first.first == 2 && move.first.second == 0) &&
               ((move.second.first == 1 && move.second.second == 0) ||
                (move.second.first == 2 && move.second.second == 1))) {
      return true;
    } else if ((move.first.first == 0 && move.first.second == 1) &&
               ((move.second.first == 0 && move.second.second == 0) ||
                (move.second.first == 0 && move.second.second == 2) ||
                (move.second.first == 1 && move.second.second == 1))) {
      return true;
    } else if ((move.first.first == 1 && move.first.second == 1) &&
               ((move.second.first == 0 && move.second.second == 1) ||
                (move.second.first == 2 && move.second.second == 1) ||
                (move.second.first == 1 && move.second.second == 2) ||
                (move.second.first == 1 && move.second.second == 0))) {
      return true;
    } else if ((move.first.first == 2 && move.first.second == 1) &&
               ((move.second.first == 1 && move.second.second == 1) ||
                (move.second.first == 2 && move.second.second == 2) ||
                (move.second.first == 2 && move.second.second == 0))) {
      return true;
    } else if ((move.first.first == 0 && move.first.second == 2) &&
               ((move.second.first == 0 && move.second.second == 1) ||
                (move.second.first == 1 && move.second.second == 2))) {
      return true;
    } else if ((move.first.first == 1 && move.first.second == 2) &&
               ((move.second.first == 1 && move.second.second == 1) ||
                (move.second.first == 0 && move.second.second == 2) ||
                (move.second.first == 2 && move.second.second == 2))) {
      return true;
    } else if ((move.first.first == 2 && move.first.second == 2) &&
               ((move.second.first == 2 && move.second.second == 1) ||
                (move.second.first == 1 && move.second.second == 2))) {
      return true;
    } else {
      if (player == 1) {
        cout << "Your move is not adjacent to the origin." << endl;
        return false;
      }
      if (player == 2) {
        return false;
      }
    }
  }
  return true;
}