//
// Created by Michael Stengel on 5/30/21.
//

#include <vector>
#include <fstream>
#include "Day12.h"
#include "NavigationInstructor.h"
#include "WavePointNavigationInstructor.h"

using Instruction = std::string;

int get_manhattan_distance(int t_x, int t_y) {
    return abs(t_x) + abs(t_y);
}

std::vector<Instruction> get_instructions_from_file(const std::string &t_file_name) {
    std::vector<Instruction> instructions = {};

    std::ifstream file(t_file_name);
    std::string str;

    while (std::getline(file, str)) {
        instructions.push_back(str);
    }

    return instructions;
}

void run_instructions(const std::vector<Instruction> &instructions, NavigationInstructor *t_instructor) {
    for (const auto &instruction: instructions) {
        t_instructor->invoke(instruction);
    }

    auto[x, y] = t_instructor->get_position();

    auto distance = get_manhattan_distance(x, y);

    printf("Ferry position: (%i, %i) Distance: %i\n", x, y, distance);
}

void part1(const std::vector<Instruction> &instructions) {
    auto ferry = std::make_shared<Ferry>();
    auto instructor = std::make_shared<NavigationInstructor>(ferry);

    run_instructions(instructions, instructor.get());
}

void part2(const std::vector<Instruction> &instructions) {
    auto wave_point = std::make_shared<Ferry>(10, 1);
    auto ferry = std::make_shared<Ferry>();

    auto instructor = std::make_shared<WavePointNavigationInstructor>(ferry, wave_point);

    run_instructions(instructions, instructor.get());
}

void Day12::solve() {
    auto instructions = get_instructions_from_file("../inputs/day12");
    printf("=====Day 12=====\n");

    part1(instructions);
    part2(instructions);
}
