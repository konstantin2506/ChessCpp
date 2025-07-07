#pragma once

#include "figure.hpp"

#include <vector>
#include <iostream>

namespace Chess{

class Cell{
private:
    int x_;
    int y_;
    Piece* piece_;
    Color color_;
    bool busy_;
    bool marked_;

public:
    Cell(int x, int y);

    int get_x() const;
    int get_y() const;
    Color get_color() const;

    bool is_empty() const;
    bool is_marked() const;
    
    void set_piece(Piece* piece);
    Piece* remove_piece();
};

class Board{
private:
    size_t size_;
    std::vector<std::vector<Cell>> base_;

public:
    Board();
    ~Board();

    bool is_empty(int x, int y);
    bool is_marked(int x, int y);

    void show_moves(int x, int y);
    void init_pieces();
    void clear();
    void print();

};

}
