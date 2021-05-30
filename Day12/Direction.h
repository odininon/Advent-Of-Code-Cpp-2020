//
// Created by Michael Stengel on 5/30/21.
//

#ifndef AOC2020_DIRECTION_H
#define AOC2020_DIRECTION_H

namespace Direction {
    enum Direction {
        North = 0,
        South = 180,
        East = 90,
        West = 270
    };

    constexpr int direction_as_bering(Direction t_direction) {
        return static_cast<int>(t_direction);
    }

    constexpr Direction bearing_as_direction(int t_bearing) {
        return static_cast<Direction>(t_bearing);
    }
}

#endif //AOC2020_DIRECTION_H
