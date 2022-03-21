#include "GamePlay.h"
#include <exception>

int main() {
    GamePlay::Awake();

    while (true) {
        GamePlay::Start();

        GamePlay::Update();

        try {
            GamePlay::FixedUpdate();
        } catch (std::exception &e) {
            break;
        }

        if (GamePlay::isChange) {
            GamePlay::LateUpdate();
        }
    }

    return 0;
}