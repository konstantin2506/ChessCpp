#include "../include/board.hpp"
#include "../include/figure.hpp"
#include "../include/game.hpp"
#include "../include/player.hpp"

int main(){
    Chess::Player p1{"p1 (white)", Chess::Color::White};
    Chess::Player p2{"p2 (black)", Chess::Color::Black};

    Chess::Game game(p1, p2);
    game.start();

    return 0;
}
