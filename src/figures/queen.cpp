#include "../../include/board.hpp"
#include "../../include/figure.hpp"

using namespace Chess;

Queen::Queen(Color color, int x, int y) : Piece(color, x, y, 'Q'), rook_part_(color, x, y), bishop_part_(color, x, y) {}

std::vector<std::pair<int, int>> Queen::get_moves(const Board& board) const {
    std::vector<std::pair<int, int>> moves;
    
    auto rook_moves = rook_part_.get_moves(board);
    auto bishop_moves = bishop_part_.get_moves(board);
    
    moves.insert(moves.end(), rook_moves.begin(), rook_moves.end());
    moves.insert(moves.end(), bishop_moves.begin(), bishop_moves.end());
    
    return moves;
}
void Queen::move_to(int x, int y){
    rook_part_.move_to(x, y);
    bishop_part_.move_to(x, y);
    x_ = x;
    y_ = y;
}
