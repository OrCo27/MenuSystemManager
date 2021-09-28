#include <iostream>
#include "MenuBuilder.h"
#include "IOperationItem.h"
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

ScreenStub screen;
KeyBoardStub  keyboard;
ExampleOperation exOp;
shared_ptr<Navigation> nav;

void setup()
{
    MenuBuilder mb(keyboard, screen);

    /* register all characters to required commands */
    mb.registerUpKey('W')
      .registerDownKey('S')
      .registerBackKey('B')
      .registerEnterKey('E');

    /* create all menu required */
    Menu* main = mb.addMenu("Main-Menu");
    Menu* m1 = mb.addMenu("Sub-Menu1");
    Menu* m2 = mb.addMenu("Sub-Menu2");

    /* define the initial menu */
    mb.setInitialMenu(main);

    /* add items for [Main-Menu] */
    mb.addMenuItem(main, "m1", m1);
    mb.addMenuItem(main, "m2", m2);
    mb.addOperationItem(main, "m3", &exOp);
    mb.addOperationItem(main, "m4", &exOp);
    mb.addOperationItem(main, "m5", &exOp);
    mb.addOperationItem(main, "m6", &exOp);

    /* add items for [Sub-Menu1] */
    mb.addOperationItem(m1, "m11", &exOp);
    mb.addOperationItem(m1, "m12", &exOp);

    /* add items for [Sub-Menu2] */
    mb.addStateSelectionItem(m2, "Time")
        .addState("10ms")
        .addState("20ms")
        .addState("30ms")
        .addState("40ms");
    mb.addStateSelectionItem(m2, "Option")
        .addState("Regular")
        .addState("Medium")
        .addState("Hard");

    /* get the final instance */
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
