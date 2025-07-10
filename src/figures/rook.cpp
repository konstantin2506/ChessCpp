#include "../../include/figure.hpp"
#include "../../include/board.hpp"

#include <vector>

using namespace Chess;

Rook::Rook(Color color, int x, int y): Piece{color, x, y, 'r'} {}

std::vector<std::pair<int, int>> Rook::get_moves(const Board& board) const{
    std::vector<std::pair<int, int>> moves;
    Color color = get_color();
    int x = get_x();
    int y = get_y();
    
    for(int i = 1; x + i < board.size(); i++){
        if(!board.is_empty(x + i, y) && color == board.get_color(x + i, y)){
            break;
        }
        moves.emplace_back(x + i, y);
        if(!board.is_empty(x + i, y) && color != board.get_color(x + i, y)){
            break;
        }
    }
    for(int i = 1; y + i < board.size(); i++){
        if(!board.is_empty(x, y + i) && color == board.get_color(x, y + i)){
            break;
        }
        moves.emplace_back(x, y + i);
        if(!board.is_empty(x, y + i) && color != board.get_color(x, y + i)){
            break;
        }
    }
    for(int i = 1; x - i >= 0; i++){
        if(!board.is_empty(x - i, y) && color == board.get_color(x - i, y)){
            break;
        }
        moves.emplace_back(x - i, y);
        if(!board.is_empty(x - i, y) && color != board.get_color(x - i, y)){
            break;
        }
    }
    for(int i = 1; y - i >= 0; i++){
        if(!board.is_empty(x, y - i) && color == board.get_color(x, y - i)){
            break;
        }
        moves.emplace_back(x, y - i);
        if(!board.is_empty(x, y - i) && color != board.get_color(x, y - i)){
            break;
        }
    }
    
    return moves;

}
