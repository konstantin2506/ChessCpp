#include "../../include/figure.hpp"
#include "../../include/board.hpp"

using namespace Chess;

Pawn::Pawn(Color color, int x, int y): Piece{color, x, y, 'P'} {}

std::vector<std::pair<int, int>> Pawn::get_moves(const Board& board) const {
    std::vector<std::pair<int, int>> moves;
    Color color = get_color();
    int direction = (color == Color::White) ? 1 : -1;
    int x = get_x();
    int y = get_y();
    
    if(board.is_empty(x + direction, y)){ // 1pt move
        moves.emplace_back(x + direction, y);
        if(((x == 1 && direction == 1) || (x == 6 && direction == -1)) && board.is_empty(x + 2 * direction, y)){
            moves.emplace_back(x + 2 * direction, y);
            moves.emplace_back(x + 2 * direction, y);
        }
    }
    if(y < 7 && !board.is_empty(x + direction, y + 1) && board.get_color(x + direction, y + 1) != color){
        moves.emplace_back(x + direction, y + 1);
    }

    if(y > 0 && !board.is_empty(x + direction, y - 1) && board.get_color(x + direction, y - 1) != color){
        moves.emplace_back(x + direction, y - 1);
    }

    return moves;

}
