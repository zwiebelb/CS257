#ifndef THREE_MENS_MORRIS_H

#include <string>
#include <utility>  // For pair
#include <vector>


typedef std::vector<std::vector<int> > Board;
typedef std::pair<int, int> BoardIndex;
typedef std::pair<BoardIndex, BoardIndex> Move;

void PrintBoard(Board board);
BoardIndex ParseSpace(const std::string &space);
int PlayerAtSpace(const Board board, const BoardIndex space);
void SetPlayerAtSpace(Board &board, const int player, const BoardIndex space);
bool ValidMove(int phase, int player, const Board board, Move move);
Move ParseMove(int phase, const std::string move);
int GameOver(const Board board);

#endif
