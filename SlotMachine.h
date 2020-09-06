//
// Created by ryan on 2020-07-19.
//

#ifndef A4_40080413_SLOTMACHINE_H
#define A4_40080413_SLOTMACHINE_H

#include "Shape.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "RightTriangle.h"
#include "AcuteTriangle.h"
#include <array>
#include <cstdlib>
#include <ctime>
using namespace std;

class SlotMachine
{
public:
    array<unique_ptr<Shape>, 3> reel;
    void make_shapes();
    void make_shape(int k);
    void display();
    int calculatePayout();

public:
    SlotMachine() = default;
    SlotMachine(const SlotMachine&) = delete;
    SlotMachine(SlotMachine&&) = delete;
    SlotMachine& operator = (const SlotMachine&) = delete;
    SlotMachine& operator = (SlotMachine&&) = delete;
    virtual ~SlotMachine() = default;
    void run();

    void takeBet();
    int tokens = 10;
    int bet = 1;
    int betMultiplier;
    string caption[3];
    void winMessage();
};



#endif //A4_40080413_SLOTMACHINE_H
