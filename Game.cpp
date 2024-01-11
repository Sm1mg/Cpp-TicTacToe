#include <iostream>
#include <string>

#include "Player.cpp"
#include "Board.cpp"
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
Game::Game(){
    setup();
    loop();
    std::cout << "\nGGs! Goodbye!\n";
}
// Perform game setup
void Game::setup(){
    std::cout << "Player 1, please enter your name.\n";
    std::cin >> player_one.name;
    player_one.team = false;
    std::cout << "Player 2, please enter your name.\n";
    std::cin >> player_two.name;
    player_two.team = true;

    turn = false;
}

void Game::loop(){
    Player* player;
    while (!board.is_won()){
        player = turn? &player_two : &player_one;
        print();
        unsigned char x;
        unsigned char y;

        std::cout << player->name + " please select your x position (0-2)\n";
        std::cin >> x;
        std::cout << "Now select your y position (0-2)\n";
        std::cin >> y;
        // Adjust for these being unsigned chars
        if (!board.place(x - 48, y - 48, player->team)){
            std::cout << "Invalid input, please try again.\n";
            continue;
        }
        // Swap turns
        turn = !turn;
    }
    std::cout << player->name + " wins!\n";

}

void Game::print(){
    std::cout << (turn ? player_two.name + "'s turn\n" : player_one.name + "'s turn\n");
    std::cout << board.to_string();
}