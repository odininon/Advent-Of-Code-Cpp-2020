//
// Created by Michael Stengel on 5/30/21.
//

#ifndef AOC2020_FERRY_H
#define AOC2020_FERRY_H

#include <tuple>
#include "Direction.h"

class Ferry {
public:
    Ferry(int t_x, int t_y) : x_position(t_x), y_position(t_y) {}

    Ferry() = default;

    void move_forward(int t_amount);

    void move_north(int t_amount);

    void move_south(int t_amount);

    void move_east(int t_amount);

    void move_west(int t_amount);

    void rotate_left(int t_amount);

    void rotate_right(int t_amount);

    void move_to_wave_point_times(std::tuple<int, int> t_position, int t_amount);

    void normalize_to_east();

    std::tuple<int, int> get_position();

private:
    void move_direction(Direction::Direction t_direction, int t_amount);

    void rotate_direction(int t_bearing, int t_amount);

    Direction::Direction m_direction = Direction::East;
    int x_position = 0;
    int y_position = 0;
};


#endif //AOC2020_FERRY_H
