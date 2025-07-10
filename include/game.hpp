#pragma once

#include "figure.hpp"
#include "board.hpp"
#include "player.hpp"

#include <vector>
#include <string>
#include <memory>

namespace Chess{

class Game{
    std::vector<Player*> players_;
    int current_index_;
    std::vector<int_pair> moves_;
    std::unique_ptr<Board> board_;
    bool finished_;
public:
    Game(Player& p1, Player& p2);
    void start();
    void show() const;
    void finish();
    
    bool finished() const;
};

}
