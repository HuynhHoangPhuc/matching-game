//
// Created by Phuc Huynh Hoang on 19/03/2022.
//

#ifndef MATCHINGGAME_GAMEPLAY_H
#define MATCHINGGAME_GAMEPLAY_H

#include "Database/BoardData.h"

struct GamePlay {
private:
    BoardData data;
public:
    /*
     * Looking change of the objects
     * Default is false
     * When FixedUpdate invoke, isChange will change
     * */
    static bool isChange;

    /*
     * Awake will call only once when the GameObject is initialized
     * */
    static void Awake();

    /*
     * Start will call if GameObject's data change
     * */
    static void Start();

    /*
     * Update will call per frame to define the logic
     * that runs continuously, like animations, render objects
     * */
    static void Update();

    /*
     * FixedUpdate when you want to do physics work
     * Get input and calculate the change, after that
     * isChange = true
     * */
    static void FixedUpdate();

    /*
     * LateUpdate will call at the end of the frame
     * When the objects change, this function will re-render
     * */
    static void LateUpdate();
};


#endif //MATCHINGGAME_GAMEPLAY_H
