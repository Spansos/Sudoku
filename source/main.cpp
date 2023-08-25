#include <iostream>
#include <board.hpp>
#include <chrono>


int main() {
    Board test;
    test.squares[0][0].state = 8;
    test.squares[1][2].state = 3;
    test.squares[1][3].state = 6;
    test.squares[2][1].state = 7;
    test.squares[2][4].state = 9;
    test.squares[2][6].state = 2;
    test.squares[3][1].state = 5;
    test.squares[3][5].state = 7;
    test.squares[4][4].state = 4;
    test.squares[4][5].state = 5;
    test.squares[4][6].state = 7;
    test.squares[5][3].state = 1;
    test.squares[5][7].state = 3;
    test.squares[6][2].state = 1;
    test.squares[6][7].state = 6;
    test.squares[6][8].state = 8;
    test.squares[7][2].state = 8;
    test.squares[7][3].state = 5;
    test.squares[7][7].state = 1;
    test.squares[8][1].state = 9;
    test.squares[8][6].state = 4;

    auto start = std::chrono::high_resolution_clock::now();
    test.solve();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << test;
    std::cout << "\nsolved in: " << std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count() << "ms";
}