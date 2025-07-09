#pragma once

#include "figure.hpp"

#include <vector>
#include <iostream>



namespace Chess{

using int_pair = std::pair<int, int>;

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
    Piece* get_piece() const;

    bool is_empty() const;
    bool is_marked() const;
    void set_marked();
    void set_busy();
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

    bool is_empty(int x, int y) const;
    bool is_marked(int x, int y) const;
    
    Color get_color(int x, int y) const;
    void show_moves(int x, int y);
    void clear();
    void print() const;
    void replace_piece(int_pair from, int_pair to);
private:
    void init_pawns();
    void init_pieces();
};

}
