//
// Created by Michael Stengel on 5/30/21.
//

#ifndef AOC2020_WAVEPOINTNAVIGATIONINSTRUCTOR_H
#define AOC2020_WAVEPOINTNAVIGATIONINSTRUCTOR_H


#include "NavigationInstructor.h"

class WavePointNavigationInstructor : public NavigationInstructor {

public :
    WavePointNavigationInstructor(std::shared_ptr<Ferry> t_ferry, std::shared_ptr<Ferry> t_wave_point)
            : NavigationInstructor(t_ferry), m_wave_point(t_wave_point) {}

    void invoke(const std::string &t_instruction) override;

private:
    std::shared_ptr<Ferry> m_wave_point;
};


#endif //AOC2020_WAVEPOINTNAVIGATIONINSTRUCTOR_H
