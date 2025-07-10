#pragma once

#include "board.hpp"
#include "figure.hpp"

#include <string>

namespace Chess{

class Player{
    std::string name_;
    Color side_;
public:
    Player(std::string name, Color side);
    int move(Board& board);
    
};

}
