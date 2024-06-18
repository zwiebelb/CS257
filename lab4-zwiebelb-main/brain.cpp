#include "brain.h"

#include <random>
#include <ctime>
#include <cstdlib>

Move GalaxyBrain(int phase, const Board board) {// add phase
  Move move;
  if(phase == 1){
    if (board[0][0] == 2 && board[1][0] == 2 && board[2][0] == 0){
      move.second.first = 2;
      move.second.second = 0;
    }
    else if (board[0][0] == 2 && board [2][0] == 2 && board[1][0] == 0){
      move.second.first = 1;
      move.second.second = 0;}
    else if (board[1][0] == 2 && board [2][0] == 2 && board[0][0] == 0){
      move.second.first = 0;
      move.second.second = 0;}
    else if (board[0][0] == 2 && board [0][1] == 2 && board[0][2] == 0){
      move.second.first = 0;
      move.second.second = 2;}
    else if (board[0][0] == 2 && board [0][2] == 2 && board[0][1] == 0){
      move.second.first = 0;
      move.second.second = 1;}
    else if (board[0][1] == 2 && board [0][2] == 2 && board[0][0] == 0){
     move.second.first = 0;
      move.second.second = 0;}
    else if (board[1][0] == 2 && board [1][1] == 2 && board[1][2] == 0){
      move.second.first = 1;
      move.second.second = 2;}
    else if (board[1][0] == 2 && board [1][2] == 2 && board[1][1] == 0){
      move.second.first = 1;
      move.second.second = 1;}
    else if (board[1][1] == 2 && board [1][2] == 2 && board[1][0] == 0){
      move.second.first = 1;
      move.second.second = 0;}
    else if (board[2][0] == 2 && board [2][1] == 2 && board[2][2] == 0){
      move.second.first = 2;
      move.second.second = 2;}
    else if (board[2][0] == 2 && board [2][2] == 2 && board[2][1] == 0){
      move.second.first = 2;
      move.second.second = 1;}   
    else if (board[2][1] == 2 && board[2][2] == 2&& board[2][0] == 0){
      move.second.first = 2;
      move.second.second = 0;} 
    else if (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 0){
      move.second.first = 2;
      move.second.second = 1;} 
    else if (board[0][1] == 2 && board[2][1] == 2 && board[1][1] == 0){
      move.second.first = 1;
      move.second.second = 1;} 
    else if (board[1][1] == 2 && board[2][1] == 2 && board[0][1] == 0){
      move.second.first = 0;
      move.second.second = 1;} 
    else if (board[0][2] == 2 && board[2][2] == 2 && board[1][2] == 0){
      move.second.first = 1;
      move.second.second = 2;} 
     else if (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 0){
      move.second.first = 2;
      move.second.second = 2;} 
     else if (board[1][2] == 2 && board[2][2] == 2 && board[0][2] == 0){
      move.second.first = 0;
      move.second.second = 2;} 


    else if(board[0][0] == 1 && board[1][0] == 1 && board[2][0] == 0){
      move.second.first = 2;
      move.second.second = 0;}
    else if(board[0][0] == 1 && board [2][0] == 1 && board[1][0] == 0){
      move.second.first = 1;
      move.second.second = 0;}
    else if(board[1][0] == 1 && board [2][0] == 1 && board[0][0] == 0){
      move.second.first = 0;
      move.second.second = 0;}
    else if(board[0][0] == 1 && board [0][1] == 1 && board[0][2] == 0){
      move.second.first = 0;
      move.second.second = 2;}  
    else if(board[0][0] == 1 && board [0][2] == 1 && board[0][1] == 0){
      move.second.first = 0;
      move.second.second = 1;}
    else if (board[0][1] == 1 && board [0][2] == 1 && board[0][0] == 0){
      move.second.first = 0;
      move.second.second = 0;}
    else if (board[1][0] == 1 && board [1][1] == 1 && board[1][2] == 0){
      move.second.first = 1;
      move.second.second = 2;}
    else if (board[1][0] == 1 && board [1][2] == 1 && board[1][1] == 0){
      move.second.first = 1;
      move.second.second = 1;}
    else if (board[1][1] == 1 && board [1][2] == 1 && board[1][0] == 0){
      move.second.first = 1;
      move.second.second = 0;}
    else if (board[2][0] == 1 && board [2][1] == 1 && board[2][2] == 0){
      move.second.first = 2;
      move.second.second = 2;}
   else if (board[2][0] == 1 && board [2][2] == 1 && board[2][1] == 0){
      move.second.first = 2;
      move.second.second = 1;}   
    else if (board[2][1] == 1 && board [2][2] == 1 && board[2][0] == 0){
      move.second.first = 2;
      move.second.second = 0;} 
    else if (board[0][1] == 1 && board [1][1] == 1 && board[2][1] == 0){
      move.second.first = 2;
      move.second.second = 1;} 
    else if (board[0][1] == 1 && board[2][1] == 1 && board[1][1] == 0){
      move.second.first = 1;
      move.second.second = 1;} 
    else if (board[1][1] == 1 && board[2][1] == 1 && board[0][1] == 0){
      move.second.first = 0;
      move.second.second = 1;} 
    else if (board[0][2] == 1 && board[2][2] == 1 && board[1][2] == 0){
      move.second.first = 1;
      move.second.second = 2;} 
     else if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 0){
      move.second.first = 2;
      move.second.second = 2;} 
    else if (board[1][2] == 1 && board[2][2] == 1 && board[0][2] == 0){
      move.second.first = 0;
      move.second.second = 2;} 
    else{
      srand(time(0));
      int row = rand() % 3;  
      int col = rand() % 3;
      move.first.second = -1;
      move.first.first = -1;
      move.second.first = row;
      move.second.second = col;
    }
  }
  else if (phase == 2){
    //col 1
    if (board[2][0] == 2 && board[1][0] == 2 && board[0][0] == 0 && board[0][1] == 2){
      move.first.first = 0;
      move.first.second = 1;
      move.second.first = 0;
      move.second.second = 0;
    }
     else if (board[2][0] == 2 && board[0][0] == 2 && board[1][0] == 0 && board[1][1] == 2){
      move.first.first = 1;
      move.first.second = 1;
      move.second.first = 1;
      move.second.second = 0;
    }
    else if (board[0][0] == 2 && board[1][0] == 2 && board[3][0] == 0 && board[3][1] == 2){
      move.first.first = 3;
      move.first.second = 1;
      move.second.first = 3;
      move.second.second = 0;
    }
    //col 2
    else if (board[1][1] == 2 && board[2][1] == 2 && board[0][1] == 0 && board[0][0] == 2){
      move.first.first = 0;
      move.first.second = 0;
      move.second.first = 0;
      move.second.second = 1;
    }
else if (board[1][1] == 2 && board[2][1] == 2 && board[0][1] == 0 && board[0][2] == 2){
      move.first.first = 0;
      move.first.second = 2;
      move.second.first = 0;
      move.second.second = 1;
    }
    else if (board[0][1] == 2 && board[2][1] == 2 && board[1][1] == 0 && board[1][0] == 2){
      move.first.first = 1;
      move.first.second = 0;
      move.second.first = 1;
      move.second.second = 1;
    }
        else if (board[0][1] == 2 && board[2][1] == 2 && board[1][1] == 0 && board[1][2] == 2){
      move.first.first = 1;
      move.first.second = 2;
      move.second.first = 1;
      move.second.second = 1;
    }

    else if (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 0 && board[2][0] == 2){
      move.first.first = 2;
      move.first.second = 0;
      move.second.first = 2;
      move.second.second = 1;
    }
        else if (board[0][1] == 2 && board[1][1] == 2 && board[2][1] == 0 && board[2][2] == 2){
      move.first.first = 2;
      move.first.second = 2;
      move.second.first = 2;
      move.second.second = 1;
    }
    //col 3

      else if (board[1][2] == 2 && board[2][2] == 2 && board[0][2] == 0 && board[0][1] == 2){
      move.first.first = 0;
      move.first.second = 1;
      move.second.first = 0;
      move.second.second = 2;
    }
   else if (board[0][2] == 2 && board[2][2] == 2 && board[1][2] == 0 && board[1][1] == 2){
      move.first.first = 1;
      move.first.second = 1;
      move.second.first = 1;
      move.second.second = 2;
    }
  else if (board[0][2] == 2 && board[1][2] == 2 && board[2][2] == 0 && board[2][1] == 2){
      move.first.first = 2;
      move.first.second = 1;
      move.second.first = 2;
      move.second.second = 2;
    }
      //row 1
  else if (board[0][0] == 2 && board[0][1] == 2 && board[0][2] == 0 && board[1][2] == 2){
      move.first.first = 1;
      move.first.second = 2;
      move.second.first = 0;
      move.second.second = 2;
    }
    else if (board[0][0] == 2 && board[0][2] == 2 && board[0][1] == 0 && board[1][1] == 2){
      move.first.first = 1;
      move.first.second = 1;
      move.second.first = 0;
      move.second.second = 1;
    }
      else if (board[0][1] == 2 && board[0][2] == 2 && board[0][0] == 0 && board[1][0] == 2){
      move.first.first = 1;
      move.first.second = 0;
      move.second.first = 0;
      move.second.second = 0;
    }
        //row 2
      else if (board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 0 && board[0][2] == 2){
      move.first.first = 0;
      move.first.second = 2;
      move.second.first = 1;
      move.second.second = 2;
    }
    else if (board[1][0] == 2 && board[1][1] == 2 && board[1][2] == 0 && board[2][2] == 2){
      move.first.first = 2;
      move.first.second = 2;
      move.second.first = 1;
      move.second.second = 2;
    }

    else if (board[1][0] == 2 && board[1][2] == 2 && board[1][1] == 0 && board[0][1] == 2){
      move.first.first = 0;
      move.first.second = 1;
      move.second.first = 1;
      move.second.second = 1;
    }
    else if (board[1][0] == 2 && board[1][2] == 2 && board[1][1] == 0 && board[2][1] == 2){
      move.first.first = 2;
      move.first.second = 1;
      move.second.first = 1;
      move.second.second = 1;
    }

    else if (board[1][1] == 2 && board[1][2] == 2 && board[1][0] == 0 && board[0][0] == 2){
      move.first.first = 0;
      move.first.second = 0;
      move.second.first = 1;
      move.second.second = 0;
    }
    else if (board[1][1] == 2 && board[1][2] == 2 && board[1][0] == 0 && board[2][0] == 2){
      move.first.first = 2;
      move.first.second = 0;
      move.second.first = 1;
      move.second.second = 0;
    }
   //row 3
    else if (board[2][0] == 2 && board[2][1] == 2 && board[2][2] == 0 && board[1][2] == 2){
      move.first.first = 1;
      move.first.second = 2;
      move.second.first = 2;
      move.second.second = 2;
    }
    else if (board[2][0] == 2 && board[2][2] == 2 && board[2][1] == 0 && board[1][1] == 2){
      move.first.first = 1;
      move.first.second = 1;
      move.second.first = 2;
      move.second.second = 1;
    }
    else if (board[2][1] == 2 && board[2][2] == 2 && board[2][0] == 0 && board[1][0] == 2){
      move.first.first = 1;
      move.first.second = 0;
      move.second.first = 2;
      move.second.second = 0;
    }

    //col 1
    if (board[2][0] == 1 && board[1][0] == 1 && board[0][0] == 0 && board[0][1] == 2){
      move.first.first = 0;
      move.first.second = 1;
      move.second.first = 0;
      move.second.second = 0;
    }

    else if (board[2][0] == 1 && board[0][0] == 1 && board[1][0] == 0 && board[1][1] == 2){
      move.first.first = 1;
      move.first.second = 1;
      move.second.first = 1;
      move.second.second = 0;
    }
    else if (board[0][0] == 1 && board[1][0] == 1 && board[3][0] == 0 && board[3][1] == 2){
      move.first.first = 3;
      move.first.second = 1;
      move.second.first = 3;
      move.second.second = 0;
    }
    //col 2
else if (board[1][1] == 1 && board[2][1] == 1 && board[0][1] == 0 && board[0][0] == 2){
      move.first.first = 0;
      move.first.second = 0;
      move.second.first = 0;
      move.second.second = 1;
    }
   else if (board[1][1] == 1 && board[2][1] == 1 && board[0][1] == 0 && board[0][2] == 2){
      move.first.first = 0;
      move.first.second = 2;
      move.second.first = 0;
      move.second.second = 1;
    }
    else if (board[0][1] == 1 && board[2][1] == 1 && board[1][1] == 0 && board[1][0] == 2){
      move.first.first = 1;
      move.first.second = 0;
      move.second.first = 1;
      move.second.second = 1;
    }
else if (board[0][1] == 1 && board[2][1] == 1 && board[1][1] == 0 && board[1][2] == 2){
      move.first.first = 1;
      move.first.second = 2;
      move.second.first = 1;
      move.second.second = 1;
    }
        else if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 0 && board[2][0] == 2){
      move.first.first = 2;
      move.first.second = 0;
      move.second.first = 2;
      move.second.second = 1;
    }
        else if (board[0][1] == 1 && board[1][1] == 1 && board[2][1] == 0 && board[2][2] == 2){
      move.first.first = 2;
      move.first.second = 2;
      move.second.first = 2;
      move.second.second = 1;
    }
  //col 3
  else if (board[1][2] == 1 && board[2][2] == 1 && board[0][2] == 0 && board[0][1] == 2){
      move.first.first = 0;
      move.first.second = 1;
      move.second.first = 0;
      move.second.second = 2;
    }
   else if (board[0][2] == 1 && board[2][2] == 1 && board[1][2] == 0 && board[1][1] == 2){
      move.first.first = 1;
      move.first.second = 1;
      move.second.first = 1;
      move.second.second = 2;
    }
  else if (board[0][2] == 1 && board[1][2] == 1 && board[2][2] == 0 && board[2][1] == 2){
      move.first.first = 2;
      move.first.second = 1;
      move.second.first = 2;
      move.second.second = 2;
    }
 //row1 
  else if (board[0][0] == 1 && board[0][1] == 1 && board[0][2] == 0 && board[1][2] == 2){
      move.first.first = 1;
      move.first.second = 2;
      move.second.first = 0;
      move.second.second = 2;
    }
    else if (board[0][0] == 1 && board[0][2] == 1 && board[0][1] == 0 && board[1][1] == 2){
      move.first.first = 1;
      move.first.second = 1;
      move.second.first = 0;
      move.second.second = 1;
    }
      else if (board[0][1] == 1 && board[0][2] == 1 && board[0][0] == 0 && board[1][0] == 2){
      move.first.first = 1;
      move.first.second = 0;
      move.second.first = 0;
      move.second.second = 0;
    }
    //row 2
      else if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 0 && board[0][2] == 2){
      move.first.first = 0;
      move.first.second = 2;
      move.second.first = 1;
      move.second.second = 2;
    }
    else if (board[1][0] == 1 && board[1][1] == 1 && board[1][2] == 0 && board[2][2] == 2){
      move.first.first = 2;
      move.first.second = 2;
      move.second.first = 1;
      move.second.second = 2;
    }

    else if (board[1][0] == 1 && board[1][2] == 1 && board[1][1] == 0 && board[0][1] == 2){
      move.first.first = 0;
      move.first.second = 1;
      move.second.first = 1;
      move.second.second = 1;
    }
    else if (board[1][0] == 1 && board[1][2] == 1 && board[1][1] == 0 && board[2][1] == 2){
      move.first.first = 2;
      move.first.second = 1;
      move.second.first = 1;
      move.second.second = 1;
    }

    else if (board[1][1] == 1 && board[1][2] == 1 && board[1][0] == 0 && board[0][0] == 2){
      move.first.first = 0;
      move.first.second = 0;
      move.second.first = 1;
      move.second.second = 0;
    }
    else if (board[1][1] == 1 && board[1][2] == 1 && board[1][0] == 0 && board[2][0] == 2){
      move.first.first = 2;
      move.first.second = 0;
      move.second.first = 1;
      move.second.second = 0;
    }
    //row 3
    else if (board[2][0] == 1 && board[2][1] == 1 && board[2][2] == 0 && board[1][2] == 2){
      move.first.first = 1;
      move.first.second = 2;
      move.second.first = 2;
      move.second.second = 2;
    }
    else if (board[2][0] == 1 && board[2][2] == 1 && board[2][1] == 0 && board[1][1] == 2){
      move.first.first = 1;
      move.first.second = 1;
      move.second.first = 2;
      move.second.second = 1;
    }
    else if (board[2][1] == 1 && board[2][2] == 1 && board[2][0] == 0 && board[1][0] == 2){
      move.first.first = 1;
      move.first.second = 0;
      move.second.first = 2;
      move.second.second = 0;
    }
    //add way for person to win if have they have a piece adjacent to the empty space
  else {
    srand(time(0));
    int row_1 = rand() % 3;  
    int col_1 = rand() % 3;
    int row_2 = rand() % 3; 
    int col_2 = rand() % 3;
    move.first.first = row_1;
    move.first.second = col_1;
    move.second.first = row_2;
    move.second.second = col_2;
  }
    }
    // The AI's priorities are:
  // #1 if theres a way to move and win take it //flip
  // #2 Block the way of the opposing player when one piece is left to win
  // #3 Place at a random position
  // Computer AI goes here.

  return move;
}
