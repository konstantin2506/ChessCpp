#include "../../include/board.hpp"
#include "../../include/player.hpp"

#include <string>
#include <iostream>

using namespace Chess;

Player::Player(std::string name, Color side): name_(name), side_(side) {}

int Player::move(Board& board){
    while(1){
        board.unshow_moves();
        board.print();
        std::string from, to;
        std::string name_upd = name_ + "| ";
        std::cout << name_upd <<"from: ";
        std::cin >> from;

        if(std::cin.eof()){
            return 1;
        }
        if(from.length() != 2){
            std::cerr << " Error: invalid length:" << from.length() <<"\n";
            continue; 
        }

        int y = 'H' - from[0];
        int x = from[1] - '0' - 1;
        if(x > 7 || x < 0 || y > 7 || y < 0){
            std::cerr << name_upd <<"Out of range: (" << x << ", "<< y << ")\n";
            continue;
        }
        if(!board.is_empty(x, y) && side_ != board.get_color(x, y)){
            std::cerr << "Not your piece!\n";
            continue;
        }
        int_pair from_i = {x, y};
        board.show_moves(x, y);
        if(!board.is_moving()){
            std::cerr << name_upd <<"No moves\n";
            continue;
        }
        board.print();
                
        std::cout << name_upd<< "to: ";
        std::cin >> to;

        if(std::cin.eof()){
            return 1;
        }
        if(to.length() != 2){
            std::cerr << " Error: invalid length:" << to.length() <<"\n";
            continue; 
        }
        y = 'H' - to[0]; //repeat
        x = to[1] - '0' - 1;
        if(x > 7 || x < 0 || y > 7 || y < 0) continue;
        int_pair to_i = {x, y};
        bool valid = board.check_move(to_i.first, to_i.second);
        
        if(valid){
            board.replace_piece(from_i, to_i);
            return 0;
        }
        std::cerr << name_upd <<"Invalid move, try again!\n";
    }

}

