//
// Created by Michael Stengel on 5/30/21.
//

#include "NavigationInstructor.h"

void NavigationInstructor::invoke(const std::string &t_instruction) {
    auto action = t_instruction.substr(0, 1);
    auto amount = atoi(t_instruction.substr(1).c_str());

    if (action == "F") {
        m_ferry->move_forward(amount);
    }
    if (action == "N") {
        m_ferry->move_north(amount);
    }
    if (action == "S") {
        m_ferry->move_south(amount);
    }
    if (action == "E") {
        m_ferry->move_east(amount);
    }
    if (action == "W") {
        m_ferry->move_west(amount);
    }
    if (action == "L") {
        m_ferry->rotate_left(amount);
    }
    if (action == "R") {
        m_ferry->rotate_right(amount);
    }
}

std::tuple<int, int> NavigationInstructor::get_position() {
    return m_ferry->get_position();
}
