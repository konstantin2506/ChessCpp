#include "../../include/figure.hpp"
#include "../../include/board.hpp"
#include "../../include/game.hpp"
#include "../../include/player.hpp"

#include <vector>
#include <memory>
using namespace Chess;

Game::Game(Player& p1, Player& p2): current_index_(0), players_(2), finished_(false) {
    moves_.reserve(100);

    players_[0] = &p1;
    players_[1] = &p2;
    board_ = std::make_unique<Board>();
}

void Game::start(){
    while(!finished()){
        if(players_[current_index_]->move(*board_) != 0){
            finish();
        }
        current_index_ = (current_index_ + 1) % 2;
    }
    return;
}

void Game::show() const{
    board_->print();
}

void Game::finish(){
    finished_ = true;
}

bool Game::finished() const{
    return finished_;
}
