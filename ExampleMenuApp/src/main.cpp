#include <iostream>
#include "MenuBuilder.h"
#include "IOperationItem.h"
#include "ScreenStub.h"
#include "KeyBoardStub.h"

class Operation : public IOperationItem
{
public:
    void doAction() override
    {
        std::cout << "do something!" << std::endl;
    }
};

ScreenStub screen;
KeyBoardStub  keyboard;

shared_ptr<Navigation> nav;
Operation op1;

void setup()
{
    MenuBuilder mb(keyboard, screen);
    mb.registerUpKey('W')
        .registerDownKey('S')
        .registerBackKey('B')
        .registerEnterKey('E');

    Menu* main = mb.addMenu("Main-Menu");
    Menu* m1 = mb.addMenu("Sub-Menu1");
    Menu* m2 = mb.addMenu("Sub-Menu2");

    mb.setInitialMenu(main);

    mb.addMenuItem(main, "m1", m1);
    mb.addMenuItem(main, "m2", m2);
    mb.addOperationItem(main, "m3", &op1);
    mb.addOperationItem(main, "m4", &op1);
    mb.addOperationItem(main, "m5", &op1);
    mb.addOperationItem(main, "m6", &op1);

    mb.addOperationItem(m1, "m11", &op1);
    mb.addOperationItem(m1, "m12", &op1);

    mb.addStateSelectionItem(m2, "Time")
        .addState("10ms")
        .addState("20ms")
        .addState("30ms")
        .addState("40ms");

    mb.addStateSelectionItem(m2, "Option")
        .addState("Regular")
        .addState("Medium")
        .addState("Hard");

    nav = mb.getInstance();
}

int main() 
{
    setup();

    while (1)
    {
        nav->nav();
    }
    
    return 0;
}
