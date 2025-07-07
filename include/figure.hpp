#pragma once

#include <vector>


namespace Chess{

class Board;
enum class Color { Black, White };

class Piece{
    Color color_;
    int x_;
    int y_;

public:
    Piece(Chess::Color color, int x, int y);
    virtual ~Piece() = default;
    
    int get_x() const;
    int get_y() const;

    void move_to(int x, int y);

    virtual std::vector<std::pair<int, int>> get_moves(Chess::Board& board) const;
    Color get_color() const;
};

class Pawn: public Piece{
public:
    Pawn(Color color, int x, int y);

    std::vector<std::pair<int, int>> get_moves(Chess::Board& board) const;
    
};

}
