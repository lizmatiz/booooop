#include "game.h"
#include "boop.h"
#include "spaces.h"

#include <iostream>

namespace main_savitch_14{

    void Boop::restart( ){
        p1Kittens = 8;
        p2Kittens = 8;

        p1Cats = 0;
        p2Cats = 0;

        moves = 0;
    }

    void Boop::display_status() const{
        char letter = 'a';
        std::cout << "    1       2       3       4       5       6    " << std::endl;
        for(int i = 0; i < 6; i++){
            std::cout << "-------------------------------------------------" << std::endl;
            for(int l = 0; l < 6; l++){
                std::cout << "|";
                std::cout << board[i][l].getRow1();
                if(l == 5){
                    std::cout << "|";
                }
            }
            std::cout << std::endl;
            for(int l = 0; l < 6; l++){
                std::cout << "|";
                std::cout << board[i][l].getRow2();
                if(l == 5){
                        std::cout << "|  " << letter++;
                }
            }
            std::cout << std::endl;
            for(int l = 0; l < 6; l++){
                std::cout << "|";
                std::cout << board[i][l].getRow3();
                if(l == 5){
                    std::cout << "|";
                }
            }
            std::cout << std::endl;
        }
        std::cout << "-------------------------------------------------" << std::endl;
    }

    bool Boop::is_legal(const std::string& move) const { // k1a
        char type;
        int column;
        char row;
        int rowNum;
        int columnNum;

        if(move.length() != 3){
            return false;
        }
        if(move[0] == 'K' || move[0] == 'k' || move[0] == 'C' || move[0] == 'c'){
            type = move[0];
        }
        else{
            return false;
        }
        if(move[1] == '1' || move[1] == '2' || move[1] == '3' || move[1] == '4' || move[1] == '5' || move[1] == '6'){
            column = move[1];
        }
        else{
            return false;
        }
        if(move[2] == 'a' || move[2] == 'b' || move[2] == 'c' || move[2] == 'd' || move[2] == 'e' || move[2] == 'f'){
            row = move[2];
        }
        else{
            return false;
        }

        switch (column){
            case '1':
                columnNum = 0;
                break;
            case '2':
                columnNum = 1;
                break;
            case '3':
                columnNum = 2;
                break;
            case '4':
                columnNum = 3;
                break;
            case '5':
                columnNum = 4;
                break;
            case '6':
                columnNum = 5;
                break;
        }
        
        switch (row){
            case 'a':
                rowNum = 0;
                break;
            case 'b':
                rowNum = 1;
                break;
            case 'c':
                rowNum = 2;
                break;
            case 'd':
                rowNum = 3;
                break;
            case 'e':
                rowNum = 4;
                break;
            case 'f':
                rowNum = 5;
                break;
        }
        
        if(moves % 2 == 0){
            if(type == 'K' || type == 'k'){
                if(p1Kittens == 0){
                    return false;
                }
            }
            if(type == 'C' || type == 'c'){
                if(p1Cats == 0){
                    return false;
                }
            }
        }
        else{
            if(type == 'K' || type == 'k'){
                if(p2Kittens == 0){
                    return false;
                }
            }
            if(type == 'C' || type == 'c'){
                if(p2Cats == 0){
                    return false;
                }
            }
        }
        
        int i = board[rowNum][columnNum].getTaken();
        if(i == 0){
            return true;
        }
        else{
            return false;
        }
    }

    void Boop::make_move(const std::string& move){
        char type = move[0];
        char column = move[1];
        char row = move[2];

        int columnNum;
        int rowNum;

        switch (column){
            case '1':
                columnNum = 0;
                break;
            case '2':
                columnNum = 1;
                break;
            case '3':
                columnNum = 2;
                break;
            case '4':
                columnNum = 3;
                break;
            case '5':
                columnNum = 4;
                break;
            case '6':
                columnNum = 5;
                break;
        }
        
        switch (row){
            case 'a':
                rowNum = 0;
                break;
            case 'b':
                rowNum = 1;
                break;
            case 'c':
                rowNum = 2;
                break;
            case 'd':
                rowNum = 3;
                break;
            case 'e':
                rowNum = 4;
                break;
            case 'f':
                rowNum = 5;
                break;
        }

        if(type == 'C' || type == 'c'){
            board[rowNum][columnNum].setSpace(" /\\_/\\ ", "( o.o )", " > ^ < ");
        }
        else{
            board[rowNum][columnNum].setSpace("       ", " =^..^=", "       ");
        }

    }

}