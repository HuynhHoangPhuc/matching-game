//#include "GamePlay.h"
//#include <exception>
//
//int main() {
//    GamePlay::Awake();
//
//    while (true) {
//        GamePlay::Start();
//
//        GamePlay::Update();
//
//        try {
//            GamePlay::FixedUpdate();
//        } catch (std::exception &e) {
//            break;
//        }
//
//        if (GamePlay::isChange) {
//            GamePlay::LateUpdate();
//        }
//    }
//
//    return 0;
//}

#include <iostream>
#include "Utility/Collections/List/List.h"

int main() {
    auto *list = new List<int>;
    for (int i = 0; i < 10; i++) {
        list->push_back(i);
    }
    std::cout << list->index_of(5) << std::endl;
    return 0;
}