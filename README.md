# MenuSystemManager
Simple menu creator using generic approach,
so you can build on setup stage all the menu windows with all items belongs,<br />
and can easy navigate between different items and menu windows.<br />

## Item Types
- **Menu item**<br />
  This item navigate to another menu window, when it selected
- **Operational Item**<br />
  This item perform an action defined on setup stage, when it selected.
- **State Item**<br />
  This item include all possible states that the user can navigate.<br />
  All the states defined on setup stage.

## Usages
Simple usage example shown on **ExampleMenuApp** dir on **main.cpp** file.<br />
This library built to integrate easy with Embedded projects based on micro-processors such as Arduino,<br />
so instead of using screen and keyboard stubs, you can simple create your own screen and keyboard that connected as external devices.<br />
All you need to do is to implement **IScreen** and **IKeyBoard** interfaces, as implemented as an example on **ScreenStub.h** and **KeyBoardStub.h**
