#ifndef BOOP_H
#define BOOP_H

#include "game.h"
#include "spaces.h"

#include <iostream>

namespace main_savitch_14{

    class Boop:public game{

            public:
                static const int SIZE = 6;
                void display_status( ) const; // have to do this one
                void make_move(const std::string& move); // have to do this one
                void restart( );
                game* clone( ) const {}
                void compute_moves(std::queue<std::string>& moves) const {}
                int evaluate( ) const {}
                bool is_game_over( ) const {}
                bool is_legal(const std::string& move) const; // have to do this one


            protected:
                Spaces board[SIZE][SIZE]; // [row][column]
                int moves;

                int p1Kittens;
                int p1Cats;

                int p2Kittens;
                int p2Cats;
                
    };

}
#endif