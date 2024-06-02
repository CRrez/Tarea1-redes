#ifndef GAME_H
#define GAME_H
class Game {
public:
Game();
void displayBoard();
bool makeMove(int player, int column);
int checkWin();
private:
char board[6][7];
};
#endif // GAME_H