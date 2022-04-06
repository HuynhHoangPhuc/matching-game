//
// Created by Phuc Huynh Hoang on 18/03/2022.
//

#ifndef MATCHINGGAME_BOARDDATA_H
#define MATCHINGGAME_BOARDDATA_H

#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
#include <stdexcept>
#include <algorithm>

#include "../Utility/Utilities.h"

using Location = std::pair<int, int>;
using Table = std::vector<std::vector<char>>;
using Path = std::vector<int>;

struct BoardData {
private:
    Table data;

    int numRows;

    int numColumns;

    void generateData();

public:
    BoardData(const int &numRows, const int &numColumns);

    explicit BoardData(char **init);

    Table getData();

    std::vector<Path> findPaths(const int &start, const int &end);

    bool pathExist(const Location &start, const Location &end);

    bool pathExist(const int &start, const int &end);

    [[nodiscard]] Location toLocation(const int &point) const;

    [[nodiscard]] int toPoint(const Location &location) const;

    ~BoardData();
};


#endif //MATCHINGGAME_BOARDDATA_H
