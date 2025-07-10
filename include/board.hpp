#pragma once

#include "figure.hpp"

#include <vector>
#include <iostream>
#include <memory>


namespace Chess{

using int_pair = std::pair<int, int>;

class Cell{
private:
    int x_;
    int y_;
    std::unique_ptr<Piece> piece_;
    Color color_;
    bool busy_;
    bool marked_;

public:
    Cell(int x, int y);

    int get_x() const;
    int get_y() const;
    Color get_color() const;
    const Piece* get_piece() const;

    bool is_empty() const;
    bool is_marked() const;
    void set_marked();
    void set_busy();
    void unset_marked();
    void unset_busy();
    void set_piece(std::unique_ptr<Piece> piece);
    std::unique_ptr<Piece> remove_piece();
};

class Board{
private:
    size_t size_;
    std::vector<std::vector<Cell>> base_;
    std::vector<int_pair> moves_;
    int_pair marked_figure_;
    bool moving_;

public:
    Board();
    
    bool is_empty(int x, int y) const;
    bool is_marked(int x, int y) const;
    bool is_moving() const;
    
    void set_moving();
    void unset_moving();
    
    Color get_color(int x, int y) const;
    bool check_move(int x, int y) const;
    void show_moves(int x, int y);
    void unshow_moves();
    void clear();
    void print() const;
    void replace_piece(int_pair from, int_pair to);
private:
    void init_pawns();
    void init_pieces();
};

}
