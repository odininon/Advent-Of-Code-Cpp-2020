//
// Created by Michael Stengel on 5/30/21.
//

#include "Ferry.h"

void Ferry::move_forward(int t_amount) {
    move_direction(m_direction, t_amount);
}

void Ferry::move_direction(Direction::Direction t_direction, int t_amount) {
    switch (t_direction) {
        case Direction::East:
            x_position += t_amount;
            break;
        case Direction::West:
            x_position -= t_amount;
            break;
        case Direction::North:
            y_position += t_amount;
            break;
        case Direction::South:
            y_position -= t_amount;
            break;
    }
}

std::tuple<int, int> Ferry::get_position() {
    return std::tuple<int, int>(x_position, y_position);
}

void Ferry::move_north(int t_amount) {
    move_direction(Direction::North, t_amount);
}

void Ferry::move_south(int t_amount) {
    move_direction(Direction::South, t_amount);
}

void Ferry::move_east(int t_amount) {
    move_direction(Direction::East, t_amount);
}

void Ferry::move_west(int t_amount) {
    move_direction(Direction::West, t_amount);
}

void Ferry::rotate_left(int t_amount) {
    rotate_direction(Direction::direction_as_bering(m_direction), -t_amount);
}

void Ferry::rotate_right(int t_amount) {
    rotate_direction(Direction::direction_as_bering(m_direction), t_amount);
}

void Ferry::rotate_direction(int t_bearing, int t_amount) {
    auto new_bearing = (t_bearing + t_amount) % 360;

    if (new_bearing < 0) {
        new_bearing += 360;
    }

    m_direction = Direction::bearing_as_direction(new_bearing);
}

void Ferry::move_to_wave_point_times(std::tuple<int, int> t_position, int t_amount) {
    auto[x, y] = t_position;
    for (auto i = 0; i < t_amount; ++i) {
        x_position += x;
        y_position += y;
    }
}

void Ferry::normalize_to_east() {
    switch (m_direction) {
        case Direction::North: {
            auto c = y_position;
            y_position = x_position;
            x_position = c;

            x_position *= -1;
        }
            break;
        case Direction::South: {
            auto c = y_position;
            y_position = x_position;
            x_position = c;

            y_position *= -1;
        }
            break;
        case Direction::West:
            x_position *= -1;
            y_position *= -1;
            break;
        case Direction::East:
            break;
    }

    m_direction = Direction::East;
}

