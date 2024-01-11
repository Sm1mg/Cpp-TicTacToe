#include <string>
class Piece{
    public:
        bool team;
        bool initialized = false;
        Piece() {
            return;
        }
        Piece(bool team) {
            this->team = team;
            this->initialized = true;
        }
        std::string to_string();
};
std::string Piece::to_string(){
    return team ? "O" : "X";
}