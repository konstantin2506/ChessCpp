#include "../../include/board.hpp"
#include "../../include/figure.hpp"

#include <iostream>
#include <exception>
#include <string>
#include <memory>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

using namespace Chess;

static std::string pair_to_str(std::pair<int, int> p){
    
    std::string first(1, 'H' - p.second);
    std::string second = std::to_string(p.first + 1);
    return first + second;
}
 
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

void Cell::set_marked() { marked_ = true; }
void Cell::set_busy() { busy_ = true; }
void Cell::unset_marked() { marked_ = false; }
void Cell::unset_busy() { busy_ = false; }


void Cell::set_piece(std::unique_ptr<Piece> piece){
    if(is_empty()){
        piece_ = std::move(piece);
        busy_ = true;
    }
}

std::unique_ptr<Piece> Cell::remove_piece(){
    std::unique_ptr<Piece> tmp = std::move(piece_);
    piece_ = nullptr;
    busy_ = false;
    return tmp;
}

Color Cell::get_color() const { return color_; }
const Piece* Cell::get_piece() const { return piece_.get(); }

Board::Board() : size_(8), base_(), moves_(), moving_(false) {
    base_.resize(size_);
    for (auto& row : base_) {
        row.reserve(size_);
        for (int y = 0; y < size_; ++y) {
            row.emplace_back(&row - &base_[0], y);
        }
    }
    init_pieces();
}


bool Board::check_move(int x, int y) const {
    int_pair target = std::make_pair(x,y);
    for(auto move: moves_){
        if(move == target){
            return true;
        }
    }
    return false;

}
bool Board::is_defended(int x, int y) const{ // TODO
    return false;
}

bool Board::is_moving() const {
    return moving_;
}

bool Board::is_empty(int x, int y) const {
    return base_[x][y].is_empty();
}

bool Board::is_marked(int x, int y) const {
    return base_[x][y].is_marked();
}


void Board::set_moving(){
    moving_ = true;
}

void Board::unset_moving(){
    moving_ = false;
}

void Board::init_pieces() {
    init_pawns();
    init_kings();
    init_knights();
}

void Board::unshow_moves(){
    for(auto move: moves_){
        base_[move.first][move.second].unset_marked();
    }
    base_[marked_figure_.first][marked_figure_.second].unset_marked();
    unset_moving();
}

void Board::show_moves(int x, int y) {
    unshow_moves();

    const Piece* piece = base_[x][y].get_piece();

    if(piece == nullptr) return;
    base_[x][y].set_marked();
    marked_figure_ = std::make_pair(x,y);
    std::string from = pair_to_str(std::make_pair(x, y));
    std::cout << from + ": \n";
    moves_ = piece->get_moves(*this);
    for(auto move: moves_){
        std::cout << pair_to_str(move) << "\n";
        base_[move.first][move.second].set_marked();
    }
    set_moving();
}

void Board::print() const {
    std::cout << "  H G F E D C B A\n";
    for(size_t x = 0; x < size_; x++){
        std::cout << x+1 << " ";
        for(size_t y = 0; y < size_; y++){
            std::string symb;
            Color color;
            if(!is_empty(x, y)){
                const Piece* piece = base_[x][y].get_piece();
                symb = piece->get_symb();
                color = piece->get_color();
            }
            else{
                color = base_[x][y].get_color();
                symb = "#";
            }
            if(is_marked(x, y)){
                std::string colored_symb = RED + symb + RESET + " ";
                std::cout << colored_symb;
            }
            else{
                std::string str_color;
                if(color == Color::White){
                    str_color = WHITE;
                }
                else{
                    str_color = BLUE;
                }
                std::cout << str_color << symb << RESET << " ";
            }
        }
        std::cout<< "\n";
    }
}

Color Board::get_color(int x, int y) const { 
    const Piece* piece = base_[x][y].get_piece();
    return piece->get_color();
}

void Board::init_pawns() {
    std::vector<std::unique_ptr<Piece>> created_pieces;
    created_pieces.reserve(size_ * 2);
    try{
        for(int y = 0; y < size_; y++){
            created_pieces.emplace_back(std::make_unique<Pawn>(Color::White, 1, y));
            created_pieces.emplace_back(std::make_unique<Pawn>(Color::Black, 6, y));
        }
        for(int y = 0; y < size_; y++){
            base_[1][y].set_piece(std::move(created_pieces[y * 2]));
            base_[6][y].set_piece(std::move(created_pieces[y * 2 + 1]));
        }
    }
    catch(const std::bad_alloc& e){
        throw std::runtime_error("Memory allocation failed: " + std::string(e.what()));
    }
    catch(const std::exception& e){
        throw std::runtime_error("Failed to initialize pawns: " + std::string(e.what()));
    }
}

void Board::init_kings(){
    try{
        std::unique_ptr<Piece> w_king = std::make_unique<King>(Color::White, 0, 3);
        std::unique_ptr<Piece> b_king = std::make_unique<King>(Color::Black, 7, 3);

        base_[0][3].set_piece(std::move(w_king));
        base_[7][3].set_piece(std::move(b_king));
    }
    catch(const std::bad_alloc& e){
        throw std::runtime_error("Memory allocation failed: " + std::string(e.what()));
    }
    catch(const std::exception& e){
        throw std::runtime_error("Failed to initialize kings: " + std::string(e.what()));
    }
}

void Board::init_knights(){
    try{
        std::vector<std::unique_ptr<Piece>> knights;
        knights.reserve(4);
        knights.emplace_back(std::make_unique<Knight>(Color::White, 0, 1));
        knights.emplace_back(std::make_unique<Knight>(Color::White, 0, 6));
        knights.emplace_back(std::make_unique<Knight>(Color::Black, 7, 1));
        knights.emplace_back(std::make_unique<Knight>(Color::Black, 7, 6));

        for(int i = 0; i < 4; i++){
            base_[knights[i]->get_x()][knights[i]->get_y()].set_piece(std::move(knights[i]));
        }
    }
    catch(const std::bad_alloc& e){
        throw std::runtime_error("Memory allocation failed: " + std::string(e.what()));
    }
    catch(const std::exception& e){
        throw std::runtime_error("Failed to initialize knights: " + std::string(e.what()));
    }
}

void Board::replace_piece(int_pair from, int_pair to){
    int x_from = from.first;
    int y_from = from.second;
    int x_to = to.first;
    int y_to = to.second;

    std::unique_ptr<Piece> attacker = base_[x_from][y_from].remove_piece();
    base_[x_to][y_to].remove_piece();
    attacker->move_to(x_to, y_to);
    base_[x_to][y_to].set_piece(std::move(attacker));

}




































