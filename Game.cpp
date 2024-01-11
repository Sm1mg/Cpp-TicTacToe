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
    std::cout << "\n\nGGs! Goodbye!";
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

        std::cout << player->name + " please select your x position (0-2)";
        std::cin >> x;
        std::cout << "Now select your y position (0-2)";
        std::cin >> y;
        if (!board.place(x, y, player->team)){
            std::cout << "Invalid input, please try again.";
            continue;
        }
        // Swap turns
        turn = !turn;
    }
    std::cout << player->name + " wins!";

}

void Game::print(){
    std::cout << turn ? player_two.name + "'s turn\n" : player_one.name + "'s turn\n";
    std::cout << board.to_string();
}