#include "../../include/figure.hpp"
#include "../../include/board.hpp"

#include <vector>

using namespace Chess;

Knight::Knight(Color color, int x, int y): Piece{color, x, y, 'k'} {}

std::vector<std::pair<int, int>> Knight::get_moves(const Board& board) const {
    std::vector<std::pair<int, int>> moves;
    moves.reserve(8);
    Color color = get_color();
    int x = get_x();
    int y = get_y();
    
    if(x > 0 && y > 1 && (board.is_empty(x - 1, y - 2) || board.get_color(x - 1, y - 2) != color)){
        moves.emplace_back(x - 1, y - 2);
    }
    if(x < 7 && y > 1 && (board.is_empty(x + 1, y - 2) || board.get_color(x + 1, y - 2) != color)){
        moves.emplace_back(x + 1, y - 2);
    }
    if(x < 7 && y < 6 && (board.is_empty(x + 1, y + 2) || board.get_color(x + 1, y + 2) != color)){
        moves.emplace_back(x + 1, y + 2);
    }
    if(x > 0 && y < 6 && (board.is_empty(x - 1, y + 2) || board.get_color(x - 1, y + 2) != color)){
        moves.emplace_back(x - 1, y + 2);
    }
    if(x < 6 && y < 7 && (board.is_empty(x + 2, y + 1) || board.get_color(x + 2, y + 1) != color)){
        moves.emplace_back(x + 2, y + 1);
    }
    if(x < 6 && y > 0 && (board.is_empty(x + 2, y - 1) || board.get_color(x + 2, y - 1) != color)){
        moves.emplace_back(x + 2, y - 1);
    }
    if(x > 1 && y > 0 && (board.is_empty(x - 2, y - 1) || board.get_color(x - 2, y - 1) != color)){
        moves.emplace_back(x - 2, y - 1);
    }
    if(x > 1 && y < 7 && (board.is_empty(x - 2, y + 1) || board.get_color(x - 2, y + 1) != color)){
        moves.emplace_back(x - 2, y + 1);
    }

    return moves;

}
