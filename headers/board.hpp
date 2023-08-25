#pragma once

#include <iostream>
#include <cstdint>

class Board;

class Square {
public:
    bool is_valid() const;
    Board *board;
    uint8_t state;
    int x, y;
};

class Board {
public:
    Board();
    bool solve();
    bool is_valid() const;
    bool is_solved() const;
    bool is_line_valid(unsigned int line) const;
    bool is_column_valid(unsigned int column) const;
    bool is_region_valid(unsigned int region) const;
    friend std::ostream &operator<<(std::ostream &ostream, const Board &board);
    Square squares[9][9];
};