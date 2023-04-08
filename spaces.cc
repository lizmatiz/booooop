#include "spaces.h"

namespace main_savitch_14{

    Spaces::Spaces(){
        row1 = "       ";
        row2 = "       ";
        row3 = "       ";
        taken = 0;
    }

    void Spaces::setSpace(std::string r1, std::string r2, std::string r3){
        row1 = r1;
        row2 = r2;
        row3 = r3;
    }
    
}