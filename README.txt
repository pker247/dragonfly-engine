Hope Wallace (hwallace)

Platform: Windows, Visual Studio 2015

File Path: I'm very sorry I can't figure out how to set relative paths. If this helps at all, the project is set to look for the SFML library in the same folder as the dragonfly-engine folder.

Files: I'm writing what is different from the book about each file (for testing purposes)

game.cpp - Test program. main() has two function calls in it, but only run one at a time (comment out the other one). So you build the project with one commented out and run it, and then build after uncommenting the first one and commenting the other one and run it again. All output is to the dragonfly.log file in the dragonfly-engine folder (\dragonfly-engine\dragonfly.log).
The test code is commented to tell what functions are being tested and any notes you should know about the code.

WorldManager.cpp - insertObject() and removeObject() write to the log file every time they are called.

GameManager.cpp - Game loop runs for a total of 165 loops (about 5 seconds) and then calls setGameOver().

ObjectList.h - MAX_OBJECTS is set to 3 to test isFull().

Saucer.cpp & Saucer.h - Created this object that inherits from the Object class for testing the inheritance

All other files are the same as in the book.


