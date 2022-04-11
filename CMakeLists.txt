cmake_minimum_required(VERSION 3.21)
project(MatchingGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(MatchingGame MatchingGame.cpp GameObject/Board.cpp GameObject/Board.h Utility/Utilities.cpp Utility/Utilities.h Database/BoardData.cpp Database/BoardData.h GamePlay.cpp GamePlay.h GameObject/Cell.cpp GameObject/Cell.h Utility/Control.cpp Utility/Control.h Utility/Collections/List/Node.h Utility/Collections/List/List.h)
