#include "../../include/figure.hpp"

using namespace Chess;

Pawn::Pawn(Color color, int x, int y): Piece(color, x, y) {}

std::vector<std::pair<int, int>> Pawn::get_moves(const Desk& desk)
{
    std::vector<std::pair<int, int>> moves;
    int direction = (get_color() == Color::White) ? 1 : -1;
    int x = get_x();
    int y = get_y();

// standart move
    if(desk.is_empty(x + direction, y)){
        moves.emplace_back(x + direction, y);
        if(desk.is_empty(x + 2 * direction, y && (x == 1 && )){
            moves.emplace_back(x + 2 * direction, y);
        }
    }


}
