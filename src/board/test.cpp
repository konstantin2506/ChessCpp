#include "../../include/board.hpp"

int main(){
    Chess::Board board;
    board.print();
    
    board.show_moves(6,2);
    board.print();
    std::pair<int, int> pf = {6,2};
    std::pair<int, int> pt = {5,2};
    board.replace_piece(pf, pt);
    board.print();
    return 0;
}
