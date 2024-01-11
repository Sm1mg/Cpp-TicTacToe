#include "Player.h"
#include "Board.h"
class Game {
    public:
        Game();
    private:
        Player player_one;
        Player player_two;

        Board board;

        // false = p1, true = p2        
        bool turn;
        
        void print();
        void setup();
        void loop();

};