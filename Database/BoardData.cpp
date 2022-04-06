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

BoardData::BoardData(const int &numRows, const int &numColumns) {
    this->numRows = numRows + 2;
    this->numColumns = numColumns + 2;

    std::vector<char> row(this->numColumns, ' ');
    for (int i{}; i < this->numRows; i++) {
        data.emplace_back(row);
    }

    generateData();
}

BoardData::BoardData(char **init) {
    if (init == nullptr) {
        throw std::invalid_argument("Null pointer exception.");
    }

    this->numRows = static_cast<int>(sizeof(init)) / static_cast<int>(sizeof(init[0]));
    this->numColumns = static_cast<int>(sizeof(init[0])) / static_cast<int>(sizeof(init[0][0]));

    data.emplace_back(std::vector<char>(numColumns + 2, ' '));
    for (int i{}; i < numRows; i++) {
        std::vector<char> row;
        row.emplace_back(' ');
        for (int j{}; j < numColumns; j++) {
            row.emplace_back(init[i][j]);
        }
        row.emplace_back(' ');
        data.emplace_back(row);
    }
    data.emplace_back(std::vector<char>(numColumns + 2, ' '));
}

Table BoardData::getData() {
    return data;
}

std::vector<Path> BoardData::findPaths(const int &start, const int &end) {
    auto neighbors = [
            &n = numRows,
            &m = numColumns](const int &current) {

        auto isBounded = [&n, &m](const int &point) {
            return point >= 0 && point < n * m;
        };

        std::vector<int> result;
        if ((current + 1) % m != 0) {
            result.emplace_back(current + 1);
        }
        if ((current) % m != 0) {
            result.emplace_back(current - 1);
        }
        if (isBounded(current + m)) {
            result.emplace_back(current);
        }
        if (isBounded(current - m)) {
            result.emplace_back(current);
        }

        return result;
    };

    auto countBranches = [](const Path &path) {
        auto current{path.begin()};
        auto next{path.begin() + 1};
        int count{1};
        int difference{*next - *current};

        while (next != path.end()) {
            if (*next - *current != difference) count += 1;
            current += 1;
            next += 1;
        }

        return count;
    };

    std::vector<Path> paths;

    std::queue<Path> frontier;
    frontier.push({start});

    while (!frontier.empty()) {
        Path currentPath = frontier.front();
        frontier.pop();

        int current{currentPath.back()};
        if (current == end && countBranches(currentPath) < 4) {
            paths.push_back(currentPath);
            continue;
        }

        for (const auto &next: neighbors(current)) {
            auto it_find = std::find(currentPath.begin(), currentPath.end(), next);
            if (it_find == currentPath.end()) {
                auto[x, y] = toLocation(next);
                if (data[x][y] == ' ' || next == end) {
                    Path newPath{currentPath};
                    newPath.emplace_back(next);
                    frontier.push(newPath);
                }
            }
        }
    }

    return paths;
}

bool BoardData::pathExist(const Location &start, const Location &end) {
    return !findPaths(toPoint(start), toPoint(end)).empty();
}

bool BoardData::pathExist(const int &start, const int &end) {
    return !findPaths(start, end).empty();
}

Location BoardData::toLocation(const int &point) const {
    const int a{static_cast<int>((point + 1.0) / numColumns - point - 1)};
    const int b{static_cast<int>(static_cast<double>(point) / numColumns - point)};

    int k{a};
    int j{point - numColumns * point - numColumns * k};
    while (k <= b && j < 0) {
        k += 1;
        j = point - numColumns * point - numColumns * k;
    }

    return {point + k, j};
}

int BoardData::toPoint(const Location &location) const {
    return numColumns * location.first + location.second;
}

void BoardData::generateData() {
    using Couple = std::pair<int, int>;
    using Cache = std::unordered_map<int, std::vector<Couple>>;

    const int range{numRows * numColumns};
    const int limit{range >> 1};

    auto randomValue = [this, &limit]() {
        const auto x{Utilities::generateNumber(1, numRows - 1)};
        const auto y{Utilities::generateNumber(1, numColumns - 1)};
        const auto i{Utilities::generateNumber(1, numRows - 1)};
        const auto j{Utilities::generateNumber(1, numColumns - 1)};
        const auto letter{Utilities::generateLetter(limit)};

        data[x][y] = letter;
        data[i][j] = letter;

        return Couple{toPoint({x, y}), toPoint({i, j})};
    };

    Couple couple{randomValue()};

    Cache cache;
    for (int i{}; i < range; i++) cache[i] = {couple};

    auto isNotSolve = [&cache, &range, &limit]() {
        for (int i{}; i < range; i++) {
            for (int j{i + 1}; j < range; j++) {
                if ((*std::prev(cache[i].end()) == *std::next(cache[j].begin()) ||
                     *std::next(cache[i].begin()) == *std::prev(cache[j].end())) &&
                    cache[i].size() + cache[j].size() - 1 - limit == 0) {
                    return false;
                }
            }
        }

        return true;
    };

    while (isNotSolve()) {
        couple = randomValue();

        for (const auto &path: findPaths(couple.first, couple.second)) {
            for (const auto &step: path) {
                cache[step].push_back(couple);
            }
        }
    }
}

BoardData::~BoardData() = default;
