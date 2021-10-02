# Menu System Manager
- Simple menu creator integrated with an external keyboard and screen.
- Build the menu pages on setup stage with all different items belongs.
- Can easy navigate between the different items and menu pages using navigator keys.

This library built to integrate menu pages into Embedded projects based on micro-processors such as Arduino.<br />
You can simple integrate your own screen and keyboard that connected as external devices for controlling the menu and display it.<br />
All you need to do is to implement **IScreen** and **IKeyBoard** interfaces, as implemented as an example on **ScreenStub.h** and **KeyBoardStub.h**

## Item Types
- **Menu item**<br />
  This item navigate to another menu page, when it selected
- **Operational Item**<br />
  This item perform an action defined on setup stage, when it selected.
- **State Item**<br />
  This item include all possible states that the user can navigate.<br />
  All the states defined on setup stage.
  
 ## Keys Commands
 - **Up**<br />
   Allow scrolling up on the current menu each time you pressed on 'Up' key.
- **Down**<br />
   Allow scrolling down on the current menu each time you pressed on 'Down' key.
- **Back**<br />
   Back to previous menu page
- **Enter**<br />
   Click on current item for perform the appropriate action:
   - **Menu Item:** move to relevant menu page.<br />
     need to inject the reference for the next menu page into the item builder.
   - **Operational Item:** perform an custom action that registered to this item.<br />
     need to implement **IOperationItem** interface and inject reference into the item builder.
   - **State Item:** change the current state belongs to this item.<br />
     there is an option to save current state into external object, need to implement **IExternalMemory** interface and inject reference into the item builder.
   
## Usages
Simple usage example shown on **ExampleMenuApp** project on **main.cpp** file.<br />
By using **MenuBuilder** class, you can simple build the menu with all components needed.<br />
The final object that get from **getInstance()** is pointer to **Navigation** which allow us to naviagte between menu pages and items, and display them.
```c++
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
```

You must call **navigate()** method every cycle for getting inputs from keyboard for navigation,<br />
and for displaying the current menu with all its items as following:
```c++
nav->navigate();
```

