#include "../../include/board.hpp"
#include "../../include/figure.hpp"

#include <iostream>

using namespace Chess;

Cell::Cell(int x, int y): x_(x), y_(y), piece_(nullptr), busy_(false), marked_(false){
    int sum = (x_ + y_) % 2;
    if(sum == 0){
        color_ = Color::White;
    }
    else{
        color_ = Color::Black;
    }
}

int Cell::get_x() const { return x_; }
int Cell::get_y() const { return y_; }

bool Cell::is_empty() const { return busy_ == false; } 
bool Cell::is_marked() const { return marked_; }

void Cell::set_piece(Piece* piece){
    if(is_empty()){
        piece_ = piece;
    }
}

Piece* Cell::remove_piece(){
    Piece* tmp = piece_;
    piece_ = nullptr;
    return tmp;
}

Color Cell::get_color() const { return color_; }

Board::Board() : size_(8), base_() {
    base_.resize(size_);
    for (auto& row : base_) {
        row.reserve(size_);
        for (int y = 0; y < size_; ++y) {
            row.emplace_back(&row - &base_[0], y);
        }
    }
    init_pieces();
}

Board::~Board(){
    Board::clear();
}

bool Board::is_empty(int x, int y){
    return base_[x][y].is_empty();
}

bool Board::is_marked(int x, int y){
    return base_[x][y].is_marked();
}

void Board::clear(){
    for(size_t x = 0; x < size_; x++){
        for(size_t y = 0; y < size_; y++){  
            delete base_[x][y].remove_piece();
        }
    }
        
}

void Board::init_pieces() {
    std::cout << "init peaces\n";
}

void Board::show_moves(int x, int y){
    std::cout << "moves are shown" << x << y << "\n";
}

void Board::print(){
    for(size_t x = 0; x < size_; x++){
        for(size_t y = 0; y < size_; y++){
            Color color = base_[x][y].get_color();
            char smb = (color == Color::White) ? 'w' : 'b';
            std::cout << smb;
        }
        std::cout<< "\n";
    }
}

