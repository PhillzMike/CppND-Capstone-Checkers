//
// Created by phill on 05/03/2022.
//

#include <string>
#include "ConsoleUI.h"
#include <iostream>
#include <sstream>
#include <tuple>
#include <algorithm>

using std::pair;
using std::string;

ConsoleUI::ConsoleUI(Board &board) : UI(board) {}

pair<int, int> getCoordinates(string coordinateString) {
    string x, y;
    std::stringstream stream;

    std::replace(coordinateString.begin(), coordinateString.end(), ',', ' ');
    stream.str(coordinateString);

    stream >> x >> y;
    return std::make_pair(std::stoi(x), std::stoi(y));
}

Move ConsoleUI::getMove() const{
    std::string from;
    std::string to;
    bool notValid = true;
    Move move = {};

    while (notValid) {
        std::cin >> from >> to;
        try {
            auto fromCoordinates = getCoordinates(from);
            auto toCoordinates = getCoordinates(to);

            move = {.source={fromCoordinates.first, fromCoordinates.second}, .destination={toCoordinates.first, toCoordinates.second}};
            notValid = false;
        } catch(std::exception e) {
            std::cout << "The input entered is wrong , please follow this format 'fromX,fromY toX,toY' e.g 1,2 1,4 in order to move something (1,2) to (1,4)" << std::endl;

        }
    }

    return move;
}

void ConsoleUI::showError(std::string error) const {
    showMsg(error);
}

void ConsoleUI::showMsg(std::string msg) const {
    std::cout << msg << std::endl;
}

std::string printCell(Cell &cell) {
    switch (cell.getState()) {
        case P1:
            return " o ";
        case P2:
            return " x ";
        default:
            return "   ";
    }
}

void printRow(vector<Cell> row, int rowNumber) {
    std::cout << rowNumber << "\t|";
    for (auto &cell: row) {
        std::cout << printCell(cell) << "|";
    }
    std::cout << std::endl;
}

std::string multiply(std::string str, int times) {
    std::string finalStr = "";
    for (int i = 0; i < times; i++) {
        finalStr += str;
    }
    return finalStr;
}

void printDivider(int size) {
    std::cout << "\t" << multiply("+---", size) << "+" << std::endl;
}

void printColumnCoordinates(int size) {
    std::cout << "\t";
    for (int coordinate; coordinate < size; coordinate++) {
        std::cout << "  " << coordinate << " ";
    }
    std::cout << std::endl;
}

void printBoard(const Board &board) {
    printDivider(board.getSize());
    printColumnCoordinates(board.getSize());
    printDivider(board.getSize());
    for (int i = 0; i < board.getSize(); i++) {
        printRow(board.getBoard()[i], i);
        printDivider(board.getSize());
    }

}

void ConsoleUI::updateBoard() {
    printBoard(board_);
}