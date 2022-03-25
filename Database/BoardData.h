//
// Created by Phuc Huynh Hoang on 18/03/2022.
//

#ifndef MATCHINGGAME_BOARDDATA_H
#define MATCHINGGAME_BOARDDATA_H

#include <vector>
#include <queue>
#include <map>
#include <tuple>
#include <stdexcept>
#include <algorithm>

#include "../Utility/Utilities.h"

using Location = std::pair<int, int>;
using Table = std::vector<std::vector<char>>;
using Path = std::vector<Location>;

struct BoardData {
private:
    Table data;
public:
    BoardData(const int &numRow, const int &numColumn);

    explicit BoardData(char **init);

    std::tuple<bool, Path> pathExist(const Location &start, Location end);

    Table getData();

    ~BoardData();
};


#endif //MATCHINGGAME_BOARDDATA_H
