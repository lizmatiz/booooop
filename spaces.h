#ifndef SPACES_H
#define SPACES_H
#include <string>
#include <iostream>

namespace main_savitch_14{

    class Spaces{
        public:
            Spaces();

            void setSpace(std::string r1, std::string r2, std::string r3);

            void setTaken(int t) {taken = t;}

            std::string getRow1() const {return row1;}
            std::string getRow2() const {return row2;}
            std::string getRow3() const {return row3;}
            int getTaken() const {std::cout << "right before return" << std::endl; return taken;}

        private:
            std::string row1;
            std::string row2;
            std::string row3;
            int taken;
    };

}

#endif