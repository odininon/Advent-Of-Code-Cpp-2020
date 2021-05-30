//
// Created by Michael Stengel on 5/30/21.
//

#include "WavePointNavigationInstructor.h"

void WavePointNavigationInstructor::invoke(const std::string &t_instruction) {
    auto action = t_instruction.substr(0, 1);
    auto amount = atoi(t_instruction.substr(1).c_str());

    if (action == "F") {
        m_ferry->move_to_wave_point_times(m_wave_point->get_position(), amount);
    }
    if (action == "N") {
        m_wave_point->move_north(amount);
    }
    if (action == "S") {
        m_wave_point->move_south(amount);
    }
    if (action == "E") {
        m_wave_point->move_east(amount);
    }
    if (action == "W") {
        m_wave_point->move_west(amount);
    }
    if (action == "L") {
        m_wave_point->rotate_left(amount);
        m_wave_point->normalize_to_east();
    }
    if (action == "R") {
        m_wave_point->rotate_right(amount);
        m_wave_point->normalize_to_east();
    }
}
