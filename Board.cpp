#include <cstddef>
#include <string>

#include "Piece.cpp"

#define VALIDATE(a) (a >= 0 && a <3)
#define CHECK_INITALIZED(a,b,c) (a.initialized && b.initialized && c.initialized)
#define CHECK_WIN(a, b, c) (CHECK_INITALIZED(a,b,c)&& a.team == b.team && b.team == c.team)

class Board {
    public:
        Board();
        bool place(u_int8_t x, u_int8_t y, bool team);
        bool is_won();
        std::string to_string();
    private:
        Piece board[3][3];
};

Board::Board() {
    // Fill the board with empty Pieces
    for (unsigned char y; y < 3; y++){
        for (unsigned char x; x < 3; x++){
            this->board[y][x] = Piece();
        }
    }
}

bool Board::place(u_int8_t x, u_int8_t y, bool team){
    if (!VALIDATE(x) || !VALIDATE(y)){
        return false;
    }
    if (board[y][x].initialized){
        return false;
    }
    board[y][x] = Piece(team);
    return true;
}

bool Board::is_won(){
    for (unsigned char i = 0; i < 3; i++){
        // Check rows
        if (CHECK_WIN(board[i][0],board[i][1],board[i][2])){
            return true;
        }
        // Check columns
        if (CHECK_WIN(board[0][i],board[1][i],board[2][i])){
            return true;
        }
    }
        // Check diagonals
        if (CHECK_WIN(board[0][0],board[1][1],board[2][2])){
            return true;
        }
        if (CHECK_WIN(board[2][0],board[1][1],board[0][2])){
            return true;
        }
    return false;
}

std::string Board::to_string() {
    std::string str = "";
    // the voices are getting louder
    //why do i need auto here?
    //fiik
    for (auto &row : board){
        for (auto &p : row){
            str = str + "| ";
            if (!p.initialized){
                str = str + "  ";
                continue;
            }
            str = str + p.to_string() + " ";
        }
        str = str + "|\n";
    }
    return str;
}

