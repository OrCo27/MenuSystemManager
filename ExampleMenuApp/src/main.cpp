#include "utils.h"

ScreenStub screen;
KeyBoardStub  keyboard;
ExampleOperation exOp;
TimeMenuMemory timeMemory;
OptionMenuMemory optionMemory;
Navigation* nav;

void setup()
{
    MenuBuilder mb(keyboard, screen);

    /* register all characters to required commands */
    mb.registerUpKey('W')
      .registerDownKey('S')
      .registerBackKey('B')
      .registerEnterKey('E');

    /* create all menu required */
    Menu* mainMenu = mb.addMenu("Main");
    Menu* operationsMenu = mb.addMenu("Actions");
    Menu* statesMenu = mb.addMenu("States");

    /* define the initial menu */
    mb.setInitialMenu(mainMenu);

    /* add items for [Main-Menu] */
    mb.addMenuItem(mainMenu, operationsMenu);
    mb.addMenuItem(mainMenu, statesMenu);

    /* add items for [Operations-Menu] */
    mb.addOperationItem(operationsMenu, "do1", &exOp);
    mb.addOperationItem(operationsMenu, "do2", &exOp);
    mb.addOperationItem(operationsMenu, "do3", &exOp);
    mb.addOperationItem(operationsMenu, "do4", &exOp);
    mb.addOperationItem(operationsMenu, "do5", &exOp);
    mb.addOperationItem(operationsMenu, "do6", &exOp);

    /* add items for [States-Menu] */
    mb.addStateSelectionItem<int>(statesMenu, "Interval", &timeMemory)
        .addState(10)
        .addState(20)
        .addState(30)
        .addState(40)
        .addState(50)
        .addState(60)
        .addState(70)
        .addState(80)
        .addState(90)
        .addState(100);

    mb.addStateSelectionItem<std::string>(statesMenu, "Option", &optionMemory)
        .addState("Reg")
        .addState("Med")
        .addState("Hard");

    /* get the final instance */
    nav = mb.getInstance();
}

int main() 
{
    setup();

    while (1)
    {
        nav->navigate();
    }
    
    return 0;
}
