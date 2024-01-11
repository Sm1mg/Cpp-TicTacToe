#include <string>

class Piece{
    public:
        bool team;
        bool initialized = false;
        Piece();
        Piece(bool team);
        std::string to_string();
};