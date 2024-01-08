
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
};