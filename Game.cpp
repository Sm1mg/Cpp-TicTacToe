#include <iostream>

#include "Player.cpp"
#include "Board.cpp"
class Game {
    public:
        Game();
    private:
        Player player_one;
        Player player_two;

        Board board;
        
        
        void print();
        void setup();
        void loop();

};

