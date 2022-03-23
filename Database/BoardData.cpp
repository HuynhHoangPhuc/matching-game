//
// Created by Phuc Huynh Hoang on 18/03/2022.
//

#include "BoardData.h"

namespace std {
    template<>
    struct [[maybe_unused]] hash<Location> {
        std::size_t operator()(const Location &id) const noexcept {
            return std::hash<int>()(id.first ^ (id.second << 16));
        }
    };
}

BoardData::BoardData(const int &numRow, const int &numColumn) {
    int n = numRow;
    data.emplace_back(std::vector<char>(numColumn + 2, ' '));
    while (n--) {
        std::vector<char> row(numColumn + 2, ' ');
        for (int i = 1; i <= numColumn; i++) row[i] = Utilities::generateLetter(numRow * numColumn - 2);
        data.emplace_back(row);
    }
    data.emplace_back(std::vector<char>(numColumn + 2, ' '));
}

BoardData::BoardData(const char **init) {
    if (init == nullptr) {
        throw std::invalid_argument("Null pointer exception.");
    }

    int numRow{static_cast<int>(sizeof(init)) / static_cast<int>(sizeof(init[0]))};
    int numColumn{static_cast<int>(sizeof(init[0])) / static_cast<int>(sizeof(init[0][0]))};

    data.emplace_back(std::vector<char>(numColumn + 2, ' '));
    for (int i{}; i < numRow; i++) {
        std::vector<char> row;
        row.emplace_back(' ');
        for (int j{}; j < numColumn; j++) {
            row.emplace_back(init[i][j]);
        }
        row.emplace_back(' ');
        data.emplace_back(row);
    }
    data.emplace_back(std::vector<char>(numColumn + 2, ' '));
}

std::tuple<bool, Path> BoardData::pathExist(const Location &start, Location end) {
    const auto n = data.size();
    const auto m = data[0].size();

    auto directions = [&n, &m](const Location &current) {
        auto[x, y] = current;

        auto notOutOfRange = [&n, &m](const int &i, const int &j) {
            return 0 <= i && i < n && 0 <= j && j < m;
        };

        std::vector<Location> result;
        if (notOutOfRange(x, y + 1)) result.emplace_back(x, y + 1);
        if (notOutOfRange(x, y - 1)) result.emplace_back(x, y - 1);
        if (notOutOfRange(x + 1, y)) result.emplace_back(x + 1, y);
        if (notOutOfRange(x - 1, y)) result.emplace_back(x - 1, y);

        return result;
    };

    auto zigzag = [](const Path &path) {
        auto current{path.front()};
        auto next{path.begin() + 1};
        int count{1};

        while (next != path.end()) {
            if (current.first != next->first && current.second != next->second) {
                count += 1;
                current = *(next - 1);
                next -= 1;
            }
            next += 1;
        }

        return count;
    };

    std::map<int, Path> paths;

    std::queue<Path> frontier;
    frontier.push({start});

    while (!frontier.empty()) {
        Path currentPath = frontier.front();
        frontier.pop();

        Location current{currentPath.back()};
        if (current == end) {
            paths[zigzag(currentPath)] = currentPath;
            continue;
        }

        for (const auto &next: directions(current)) {
            auto it_find = std::find(currentPath.begin(), currentPath.end(), next);
            if (it_find == currentPath.end()) {
                if (data[next.first][next.second] == ' ' || next == end) {
                    Path newPath{currentPath};
                    newPath.emplace_back(next);
                    frontier.push(newPath);
                }
            }
        }
    }

    if (paths.begin()->first > 3 || paths.empty()) {
        return {false, {}};
    }

    return {true, paths.begin()->second};
}

Table BoardData::getData() {
    return data;
}

BoardData::~BoardData() = default;
