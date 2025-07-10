#include "../../include/figure.hpp"
#include "../../include/board.hpp"

using namespace Chess;

King::King(Color color, int x, int y): Piece(color, x, y, 'K'){}

std::vector<std::pair<int, int>> King::get_moves(const Board& board) const{
    std::vector<std::pair<int, int>> moves;
    int x = get_x();
    int y = get_y();
    Color color = get_color();
    
    if(x > 0 && (board.is_empty(x - 1, y) || (color != board.get_color(x - 1, y) && !board.is_defended(x - 1, y)))){ 
        moves.emplace_back(x - 1, y); 
    }
    if(y > 0 && (board.is_empty(x, y - 1) || (color != board.get_color(x, y - 1) && !board.is_defended(x, y - 1)))){ 
        moves.emplace_back(x, y - 1); 
    }
    if(x < 7 && (board.is_empty(x + 1, y) || (color != board.get_color(x + 1, y) && !board.is_defended(x + 1, y)))){ 
        moves.emplace_back(x + 1, y); 
    }
    if(y < 7 && (board.is_empty(x, y + 1) || (color != board.get_color(x, y + 1) && !board.is_defended(x, y + 1)))){ 
        moves.emplace_back(x, y + 1); 
    }

    return moves;
}
