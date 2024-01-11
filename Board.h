#include <cstddef>

#include "Piece.h"

class Board {
    public:
        Board();
        bool place(u_int8_t x, u_int8_t y, bool team);
        bool is_won();
        std::string to_string();
    private:
        Piece board[3][3];
};