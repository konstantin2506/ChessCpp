#include "../../include/board.hpp"

int main(){
    Chess::Board board;
    board.show_moves(1,1);
    board.init_pieces();
    board.print();

    return 0;
}
