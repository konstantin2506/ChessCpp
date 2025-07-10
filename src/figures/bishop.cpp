#include "../../include/figure.hpp"
#include "../../include/board.hpp"

#include <vector>

using namespace Chess;

Bishop::Bishop(Color color, int x, int y): Piece{color, x, y, 'b'} {}

std::vector<std::pair<int, int>> Bishop::get_moves(const Board& board) const{
    std::vector<std::pair<int, int>> moves;
    Color color = get_color();
    int x = get_x();
    int y = get_y();
    
    for(int i = 1; x + i < board.size() && y + i < board.size(); i++){
        if(!board.is_empty(x + i, y + i) && color == board.get_color(x + i, y + i)){
            break;
        }
        moves.emplace_back(x + i, y + i);
        if(!board.is_empty(x + i, y + i) && color != board.get_color(x + i, y + i)){
            break;
        }
    }
    for(int i = 1; x - i >= 0 && y + i < board.size(); i++){
        if(!board.is_empty(x - i, y + i) && color == board.get_color(x - i, y + i)){
            break;
        }
        moves.emplace_back(x - i, y + i);
        if(!board.is_empty(x - i, y + i) && color != board.get_color(x - i, y + i)){
            break;
        }
    }
    for(int i = 1; x - i >= 0 && y - i >= 0; i++){
        if(!board.is_empty(x - i, y - i) && color == board.get_color(x - i, y - i)){
            break;
        }
        moves.emplace_back(x - i, y - i);
        if(!board.is_empty(x - i, y - i) && color != board.get_color(x - i, y - i)){
            break;
        }
    }
    for(int i = 1; x + i < board.size() && y - i >= 0; i++){
        if(!board.is_empty(x + i, y - i) && color == board.get_color(x + i, y - i)){
            break;
        }
        moves.emplace_back(x + i, y - i);
        if(!board.is_empty(x + i, y - i) && color != board.get_color(x + i, y - i)){
            break;
        }
    }
    
    return moves;

}
