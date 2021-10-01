#pragma once

#include "MenuBuilder.h"
#include "ScreenStub.h"
#include "KeyBoardStub.h"

class ExampleOperation : public IOperationItem
{
public:
    void doAction() override
    {
        std::cout << "do something!" << std::endl;
    }
};

class TimeMenuMemory : public IExternalMemory<int>
{
public:
    int currTime;

    void save(const int& state)
    {
        currTime = state;
    }

    int getState()
    {
        return currTime;
    }
};

class OptionMenuMemory : public IExternalMemory<std::string>
{
public:
    std::string currOption;

    void save(const std::string& state)
    {
        currOption = state;
    }

    std::string getState()
    {
        return currOption;
    }
};
