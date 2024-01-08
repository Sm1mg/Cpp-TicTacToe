#include <cstddef>
#include <string>

#include "Piece.cpp"
class Board {
    public:
        Board();
        bool place(std::byte x, std::byte y, bool player);
        bool is_won();
        std::string to_string();
    private:
        Piece board[3][3];
};

Board::Board()  {
    // Fill the board with empty Pieces
    for (unsigned char y; y < 3; y++){
        for (unsigned char x; x < 3; x++){
            this->board[y][x] = Piece();
        }
    }
}
