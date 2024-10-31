#ifndef USERINPUT_H
#define USERINPUT_H
#include <iostream>

class UserInput
{
    public:
        UserInput() = default;
        ~UserInput() = default;

        int getNumberOfPlayers() {
            int numberOfPlayers;
            std::cout << "Enter number of players: ";
            std::cin >> numberOfPlayers;
            return numberOfPlayers;
        }
};

#endif // USERINPUT_H
