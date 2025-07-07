#include "../../include/figure.hpp"

using namespace Chess;


Piece::Piece(Color color, int x, int y): color_(color), x_(x), y_(y) {}

Color Piece::get_color() const { return color_; }
int Piece::get_x() const { return x_; } 
int Piece::get_y() const { return y_; } 

void Piece::move_to(int x, int y){
    x_ = x;
    y_ = y;
}

