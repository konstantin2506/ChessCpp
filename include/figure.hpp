#pragma once

#include <vector>


namespace Chess{

class Board;
enum class Color { Black, White };

class Piece{
    Color color_;
    int x_;
    int y_;
    char symb_;

public:
    Piece(Color color, int x, int y, char symb);
    virtual ~Piece();
    
    int get_x() const;
    int get_y() const;
    char get_symb() const;

    void move_to(int x, int y);

    virtual std::vector<std::pair<int, int>> get_moves(const Board& board) const = 0;
    Color get_color() const;
};

class Pawn: public Piece{
public:
    Pawn(Color color, int x, int y);

    std::vector<std::pair<int, int>> get_moves(const Board& board) const;
    
};

class King: public Piece{
public:
    King(Color color, int x, int y);

    std::vector<std::pair<int, int>> get_moves(const Board& board) const;
};

class Knight: public Piece{
public:
    Knight(Color color, int x, int y);

    std::vector<std::pair<int, int>> get_moves(const Board& board) const;
};

}
