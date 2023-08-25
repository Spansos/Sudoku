#include <board.hpp>
#include <cstring>

bool Square::is_valid() const {
    return board->is_column_valid(x) && board->is_line_valid(y) && board->is_region_valid(x/3+y/3*3);
}

Board::Board() {
    for (int y=0; y<9; y++) {
        for (int x=0; x<9; x++) {
            squares[y][x].x = x;
            squares[y][x].y = y;
            squares[y][x].board = this;
            squares[y][x].state = 0;
        }
    }
}
int checked_num = 0;
bool Board::solve() {
    checked_num++;
    /* basecase */
    if (!this->is_valid()) {
        return false;
    } else if (this->is_solved()) {
        return true;
    }

    /* find an empty spot */
    int empty_x=0, empty_y=0;
    for (int y=0; y<9; y++) {
        for (int x=0; x<9; x++) {
            if (!this->squares[y][x].state) {
                empty_x = x;
                empty_y = y;
                goto found;
            }
        }
    }
    found:

    // std::cout << empty_x << ' ' << empty_y << '\n';
    /* call this solve function for all 9 boards made by changing that empty square */
    for (int i=1; i<10; i++) {
        Board test_board = *this;
        test_board.squares[empty_y][empty_x].state = i;
        if (test_board.solve()) {
            for (int y=0; y<9; y++) {
                for (int x=0; x<9; x++) {
                    this->squares[y][x].state = test_board.squares[y][x].state;
                }
            }
            std::cout << checked_num << '\n';
            return true;
        }
    }
    return false;
}

bool Board::is_valid() const {
    for (unsigned int i=0; i<9; i++) {
        if (!is_column_valid(i) || !is_line_valid(i) || !is_region_valid(i)) return false;
    }
    return true;
}

bool Board::is_solved() const {
    for (int y=0; y<9; y++)
        for (int x=0; x<9; x++)
            if (!this->squares[y][x].state)
                return false;
    return this->is_valid();
}

bool Board::is_line_valid(unsigned int linen) const {
    bool found_states[9] = {};
    const Square *line = squares[linen];
    int state;
    for (unsigned int i=0; i<9; i++) {
        state = line[i].state;
        if (state) {
            state--;
            if ( found_states[state] )
                return false;
            else
                found_states[state] = true;
        }
    }
    return true;
}

bool Board::is_column_valid(unsigned int columnn) const {
    bool found_states[9] = {};
    int state;
    for (unsigned int i=0; i<9; i++) {
        state = squares[i][columnn].state;
        if (state) {
            state--;
            if ( found_states[state] )
                return false;
            else
                found_states[state] = true;
        }
    }
    return true;
}

bool Board::is_region_valid(unsigned int region) const {
    bool found_states[9] = {};
    int state;
    unsigned int sy = region/3*3, sx = (region%3)*3;
    for (unsigned int y=sy; y<sy+3; y++) {
        for (unsigned int x=sx; x<sx+3; x++) {
            state = squares[y][x].state;
            if (state) {
                state--;
                if ( found_states[state] )
                    return false;
                else
                    found_states[state] = true;
            }
        }
    }
    return true;
}

std::ostream &operator<<(std::ostream &ostream, const Board &board) {
    for (unsigned int i=0; i<9; i++) {
        for (unsigned int j=0; j<9; j++) {
            ostream << +board.squares[i][j].state << ' ';
        }
        ostream << '\n';
    }
    return ostream;
}