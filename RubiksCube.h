//
// Created by biswajit mahalik on 28/12/22.
//

#ifndef RUBIKS_CUBE_RUBIKSCUBE_H
#define RUBIKS_CUBE_RUBIKSCUBE_H

#include "bits/stdc++.h"

using namespace std;

class RubiksCube {
public:
    enum class FACE{
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };
    enum class COLOR{
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };
    enum class MOVE{
        L,L_PRIME,L2,
        R,R_PRIME,R2,
        U,U_PRIME,U2,
        D,D_PRIME,D2,
        F,F_PRIME,F2,
        B,B_PRIME,B2
    };

    static char getColorLetter(COLOR color){
        switch (color) {
            case COLOR::BLUE:
                return 'B';
            case COLOR::RED:
                return 'R';
            case COLOR::GREEN:
                return 'G';
            case COLOR::ORANGE:
                return 'O';
            case COLOR::YELLOW:
                return 'Y';
            default:
                return 'W';
        }
    }

    static string getMove(MOVE ind){
        switch(ind){
            case MOVE::L:
                return "L";

            case MOVE::L_PRIME:
                return "L_PRIME";

            case MOVE::L2:
                return "L2";

            case MOVE::R:
                return "R";

            case MOVE::R_PRIME:
                return "R_PRIME";

            case MOVE::R2:
                return "R2";

            case MOVE::U:
                return "U";

            case MOVE::U_PRIME:
                return "U_PRIME";

            case MOVE::U2:
                return "U2";

            case MOVE::D:
                return "D";

            case MOVE::D_PRIME:
                return "D_PRIME";

            case MOVE::D2:
                return "D2";

            case MOVE::F:
                return "F";

            case MOVE::F_PRIME:
                return "F_PRIME";

            case MOVE::F2:
                return "F2";

            case MOVE::B:
                return "B";

            case MOVE::B_PRIME:
                return "B_PRIME";
            default:
                return "B2";
        }
    }

    virtual void print() const=0;

    virtual bool is_solved() const=0;

    virtual COLOR get_color(FACE face,unsigned row,unsigned col) const=0;

    virtual vector<MOVE> random_shuffle_cube(unsigned int times)=0;

    virtual RubiksCube &l()=0;

    virtual RubiksCube &l_prime()=0;

    virtual RubiksCube &l2()=0;

    virtual RubiksCube &r()=0;

    virtual RubiksCube &r_prime()=0;

    virtual RubiksCube &r2()=0;

    virtual RubiksCube &u()=0;

    virtual RubiksCube &u_prime()=0;

    virtual RubiksCube &u2()=0;

    virtual RubiksCube &d()=0;

    virtual RubiksCube &d_prime()=0;

    virtual RubiksCube &d2()=0;

    virtual RubiksCube &f()=0;

    virtual RubiksCube &f_prime()=0;

    virtual RubiksCube &f2()=0;

    virtual RubiksCube &b()=0;

    virtual RubiksCube &b_prime()=0;

    virtual RubiksCube &b2()=0;
};


#endif //RUBIKS_CUBE_RUBIKSCUBE_H
