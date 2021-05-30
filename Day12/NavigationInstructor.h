//
// Created by Michael Stengel on 5/30/21.
//

#ifndef AOC2020_NAVIGATIONINSTRUCTOR_H
#define AOC2020_NAVIGATIONINSTRUCTOR_H

#include <memory>
#include <string>
#include "Ferry.h"

class NavigationInstructor {

public:
    explicit NavigationInstructor(std::shared_ptr<Ferry> t_ferry) : m_ferry(t_ferry) {};

    virtual std::tuple<int, int> get_position();

    virtual void invoke(const std::string &t_instruction);

    virtual ~NavigationInstructor() = default;

protected:
    std::shared_ptr<Ferry> m_ferry;
};


#endif //AOC2020_NAVIGATIONINSTRUCTOR_H
