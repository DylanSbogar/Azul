#include <iostream>

#ifndef LOAD_H
#define LOAD_H

class load {
    public:
        // constructor and deconstructor
        load();
        ~load();

        // reads file 'filname' and goes through line by line, recreating the saved game.
        void loadGame(std::string fileName);

        /* similar to loadGame, but instead of letting users continue the game, it just reads
        the save file and shows what the game looked like upon saving. */
        void testingMode();

    private:

};

#endif //LOAD_H