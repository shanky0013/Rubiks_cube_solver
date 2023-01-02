//
// Created by biswajit mahalik on 28/12/22.
//

#include "RubiksCube.h"

class Rubik : public RubiksCube{
private:
public:
    char cube[6][3][3]{};
    Rubik(){
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    cube[i][j][k] = getColorLetter(COLOR(i));
                }
            }
        }
    }



    bool is_solved() const override{
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if(cube[i][j][k]!=getColorLetter(COLOR(i)))
                        return false;
                }
            }
        }
        return true;
    }

    COLOR get_color(FACE face, unsigned row, unsigned col) const override{
        char color=cube[int(face)][row][col];
        switch (color) {
            case 'W':
                return COLOR::WHITE;
            case 'G':
                return COLOR::GREEN;
            case 'R':
                return COLOR::RED;
            case 'B':
                return COLOR::BLUE;
            case 'O':
                return COLOR::ORANGE;
            default:
                return COLOR::YELLOW;
        }
    }

    void rotate_face(int face){
        char temp[3][3]{};
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                temp[i][j]=cube[face][i][j];
            }
        }

        for (int i = 0; i < 3; ++i) cube[face][0][i]=temp[2-i][0];
        for (int i = 0; i < 3; ++i) cube[face][i][2]=temp[0][i];
        for (int i = 0; i < 3; ++i) cube[face][2][2-i]=temp[i][2];
        for (int i = 0; i < 3; ++i) cube[face][2-i][0]=temp[2][2-i];

    }

    void print() const override{
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 6; ++j) {
                if(j<=2){
                    cout<<"  ";
                }
                else cout<<" "<<cube[0][i][j%3];
            }
            cout<<endl;
        }
        cout<<endl;

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout<<cube[1][i][j%3]<<" ";
            }
            cout<<" ";
            for (int j = 0; j < 3; ++j) {
                cout<<cube[2][i][j%3]<<" ";
            }
            cout<<" ";
            for (int j = 0; j < 3; ++j) {
                cout<<cube[3][i][j%3]<<" ";
            }
            cout<<" ";
            for (int j = 0; j < 3; ++j) {
                cout<<cube[4][i][j%3]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 6; ++j) {
                if(j<=2){
                    cout<<"  ";
                }
                else cout<<" "<<cube[5][i][j%3];
            }
            cout<<endl;
        }
    }

    vector<MOVE> random_shuffle_cube(unsigned int times){
        vector<MOVE> moves;
        srand(time(0));
        for (int i = 0; i < times; ++i) {
            int temp=rand()%18;
            moves.push_back(MOVE(temp));

            switch(MOVE(times)){
                case MOVE::L:
                    this->l();

                case MOVE::L_PRIME:
                    this->l_prime();

                case MOVE::L2:
                    this->l2();

                case MOVE::R:
                    this->r();

                case MOVE::R_PRIME:
                    this->r_prime();

                case MOVE::R2:
                    this->r2();

                case MOVE::U:
                    this->u();

                case MOVE::U_PRIME:
                    this->u_prime();

                case MOVE::U2:
                    this->u2();

                case MOVE::D:
                    this->d();

                case MOVE::D_PRIME:
                    this->d_prime();

                case MOVE::D2:
                    this->d2();

                case MOVE::F:
                    this->f();

                case MOVE::F_PRIME:
                    this->f_prime();

                case MOVE::F2:
                    this->f2();

                case MOVE::B:
                    this->b();

                case MOVE::B_PRIME:
                    this->b_prime();
                default:
                    this->b2();
            }
        }
        return moves;
    }

    RubiksCube &l() override{
        this->rotate_face(1);

        char temp_arr[3] = {};
        for (int i = 0; i < 3; i++) temp_arr[i] = cube[0][i][0];
        for (int i = 0; i < 3; i++) cube[0][i][0] = cube[4][2 - i][2];
        for (int i = 0; i < 3; i++) cube[4][2 - i][2] = cube[5][i][0];
        for (int i = 0; i < 3; i++) cube[5][i][0] = cube[2][i][0];
        for (int i = 0; i < 3; i++) cube[2][i][0] = temp_arr[i];

        return *this;
    }

    RubiksCube &l_prime() override{
        this->l();
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &l2() override{
        this->l();
        this->l();

        return *this;
    }

    RubiksCube &r() override{
        this->rotate_face(3);

        char temp[3]{};
        for (int i = 0; i < 3; ++i) temp[i]=cube[0][i][2];
        for (int i = 0; i < 3; ++i) cube[0][i][2]=cube[2][i][2];
        for (int i = 0; i < 3; ++i) cube[2][i][2]=cube[5][i][2];
        for (int i = 0; i < 3; ++i) cube[5][i][2]=cube[4][2-i][0];
        for (int i = 0; i < 3; ++i) cube[4][2-i][0]=temp[i];

        return *this;
    }

    RubiksCube &r_prime()override{
        this->r();
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &r2() override{
        this->r();
        this->r();

        return *this;
    }

    RubiksCube &u()override{
        this->rotate_face(0);

        char temp[3]{};
        for (int i = 0; i < 3; i++) temp[i] = cube[4][0][2 - i];
        for (int i = 0; i < 3; i++) cube[4][0][2 - i] = cube[1][0][2 - i];
        for (int i = 0; i < 3; i++) cube[1][0][2 - i] = cube[2][0][2 - i];
        for (int i = 0; i < 3; i++) cube[2][0][2 - i] = cube[3][0][2 - i];
        for (int i = 0; i < 3; i++) cube[3][0][2 - i] = temp[i];

        return *this;
    }

    RubiksCube &u_prime() override {
        this->u();
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &u2() override {
        this->u();
        this->u();

        return *this;
    }

    RubiksCube &d() override {
        this->rotate_face(5);

        char temp[3]{};
        for (int i = 0; i < 3; i++) temp[i] = cube[2][2][i];
        for (int i = 0; i < 3; i++) cube[2][2][i] = cube[1][2][i];
        for (int i = 0; i < 3; i++) cube[1][2][i] = cube[4][2][i];
        for (int i = 0; i < 3; i++) cube[4][2][i] = cube[3][2][i];
        for (int i = 0; i < 3; i++) cube[3][2][i] = temp[i];

        return *this;
    }

    RubiksCube &d_prime() override {
        this->d();
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &d2() override {
        this->d();
        this->d();

        return *this;
    }

    RubiksCube &f() override {
        this->rotate_face(2);

        char temp[3]{};
        for (int i = 0; i < 3; i++) temp[i] = cube[0][2][i];
        for (int i = 0; i < 3; i++) cube[0][2][i] = cube[1][2 - i][2];
        for (int i = 0; i < 3; i++) cube[1][2 - i][2] = cube[5][0][2 - i];
        for (int i = 0; i < 3; i++) cube[5][0][2 - i] = cube[3][i][0];
        for (int i = 0; i < 3; i++) cube[3][i][0] = temp[i];

        return *this;
    }

    RubiksCube &f_prime() override {
        this->f();
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &f2() override {
        this->f();
        this->f();

        return *this;
    }

    RubiksCube &b() override {
        this->rotate_face(4);

        char temp[3]{};
        for (int i = 0; i < 3; i++) temp[i] = cube[0][0][2 - i];
        for (int i = 0; i < 3; i++) cube[0][0][2 - i] = cube[3][2 - i][2];
        for (int i = 0; i < 3; i++) cube[3][2 - i][2] = cube[5][2][i];
        for (int i = 0; i < 3; i++) cube[5][2][i] = cube[1][i][0];
        for (int i = 0; i < 3; i++) cube[1][i][0] = temp[i];

        return *this;
    }

    RubiksCube &b_prime() override {
        this->b();
        this->b();
        this->b();

        return *this;
    }

    RubiksCube &b2() override {
        this->b();
        this->b();

        return *this;
    }


};