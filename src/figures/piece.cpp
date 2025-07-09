#include "../../include/figure.hpp"

using namespace Chess;


Piece::Piece(Color color, int x, int y, char symb): color_(color), x_(x), y_(y), symb_(symb) {}

Piece::~Piece() = default;
Color Piece::get_color() const { return color_; }
int Piece::get_x() const { return x_; } 
int Piece::get_y() const { return y_; } 
char Piece::get_symb() const { return symb_; }

void Piece::move_to(int x, int y){
    x_ = x;
    y_ = y;
}

