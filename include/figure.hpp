#pragma once

#include <vector>


namespace Chess{

class Board;
enum class Color { Black, White };

class Piece{
protected:
    int x_;
    int y_;
private:
    Color color_;
    char symb_;

public:
    Piece(Color color, int x, int y, char symb);
    virtual ~Piece();
    
    int get_x() const;
    int get_y() const;
    char get_symb() const;

    virtual void move_to(int x, int y);

    virtual std::vector<std::pair<int, int>> get_moves(const Board& board) const = 0;
    Color get_color() const;
};

class Pawn: public Piece{
public:
    Pawn(Color color, int x, int y);

    std::vector<std::pair<int, int>> get_moves(const Board& board) const override;
    
};

class King: public Piece{
public:
    King(Color color, int x, int y);

    std::vector<std::pair<int, int>> get_moves(const Board& board) const override;
};

class Knight: public Piece{
public:
    Knight(Color color, int x, int y);

    std::vector<std::pair<int, int>> get_moves(const Board& board) const override;
};

class Rook: public Piece{
public:
    Rook(Color color, int x, int y);

    std::vector<std::pair<int, int>> get_moves(const Board& board) const override;
};

class Bishop: public Piece{
public:
    Bishop(Color color, int x, int y);

    std::vector<std::pair<int, int>> get_moves(const Board& board) const override;
};

class Queen: public Piece{
    Rook rook_part_;
    Bishop bishop_part_;
public:
    Queen(Color color, int x, int y);
    void move_to(int x, int y) override;
    std::vector<std::pair<int, int>> get_moves(const Board& board) const override;
};
}
