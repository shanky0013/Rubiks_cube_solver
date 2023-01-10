//
// Created by biswajit mahalik on 28/12/22.
//

#include "RubiksCube.h"

class RubiksCube3dArray : public RubiksCube{
private:
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

public:
    char cube[6][3][3]{};
    RubiksCube3dArray(){
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

    vector<MOVE> random_shuffle_cube(unsigned int times)override{
        vector<MOVE> moves;
        srand(time(0));
        for (int i = 0; i < times; ++i) {
            int temp=rand()%18;
            moves.push_back(MOVE(temp));

            switch(MOVE(temp)){
                case MOVE::L:
                    this->l();
                    break;

                case MOVE::L_PRIME:
                    this->l_prime();
                    break;

                case MOVE::L2:
                    this->l2();
                    break;

                case MOVE::R:
                    this->r();
                    break;

                case MOVE::R_PRIME:
                    this->r_prime();
                    break;

                case MOVE::R2:
                    this->r2();
                    break;

                case MOVE::U:
                    this->u();
                    break;

                case MOVE::U_PRIME:
                    this->u_prime();
                    break;

                case MOVE::U2:
                    this->u2();
                    break;

                case MOVE::D:
                    this->d();
                    break;

                case MOVE::D_PRIME:
                    this->d_prime();
                    break;

                case MOVE::D2:
                    this->d2();
                    break;

                case MOVE::F:
                    this->f();
                    break;

                case MOVE::F_PRIME:
                    this->f_prime();
                    break;

                case MOVE::F2:
                    this->f2();
                    break;

                case MOVE::B:
                    this->b();
                    break;

                case MOVE::B_PRIME:
                    this->b_prime();
                    break;
                default:
                    this->b2();
                    break;
            }
        }
        return moves;
    }

    RubiksCube &move(MOVE temp) override{
        switch(MOVE(temp)){
            case MOVE::L:
                this->l();
                break;

            case MOVE::L_PRIME:
                this->l_prime();
                break;

            case MOVE::L2:
                this->l2();
                break;

            case MOVE::R:
                this->r();
                break;

            case MOVE::R_PRIME:
                this->r_prime();
                break;

            case MOVE::R2:
                this->r2();
                break;

            case MOVE::U:
                this->u();
                break;

            case MOVE::U_PRIME:
                this->u_prime();
                break;

            case MOVE::U2:
                this->u2();
                break;

            case MOVE::D:
                this->d();
                break;

            case MOVE::D_PRIME:
                this->d_prime();
                break;

            case MOVE::D2:
                this->d2();
                break;

            case MOVE::F:
                this->f();
                break;

            case MOVE::F_PRIME:
                this->f_prime();
                break;

            case MOVE::F2:
                this->f2();
                break;

            case MOVE::B:
                this->b();
                break;

            case MOVE::B_PRIME:
                this->b_prime();
                break;
            default:
                this->b2();
                break;
        }
        return *this;
    }

    RubiksCube &invert(MOVE temp) override{
        switch(MOVE(temp)){
            case MOVE::L:
                this->l_prime();
                break;

            case MOVE::L_PRIME:
                this->l();
                break;

            case MOVE::L2:
                this->l2();
                break;

            case MOVE::R:
                this->r_prime();
                break;

            case MOVE::R_PRIME:
                this->r();
                break;

            case MOVE::R2:
                this->r2();
                break;

            case MOVE::U:
                this->u_prime();
                break;

            case MOVE::U_PRIME:
                this->u();
                break;

            case MOVE::U2:
                this->u2();
                break;

            case MOVE::D:
                this->d_prime();
                break;

            case MOVE::D_PRIME:
                this->d();
                break;

            case MOVE::D2:
                this->d2();
                break;

            case MOVE::F:
                this->f_prime();
                break;

            case MOVE::F_PRIME:
                this->f();
                break;

            case MOVE::F2:
                this->f2();
                break;

            case MOVE::B:
                this->b_prime();
                break;

            case MOVE::B_PRIME:
                this->b();
                break;
            default:
                this->b2();
                break;
        }
        return *this;
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

    bool operator==(const RubiksCube3dArray &rc)const{
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (rc.cube[i][j][k]!= cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubiksCube3dArray &operator=(const RubiksCube3dArray &rc){
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = rc.cube[i][j][k];
                }
            }
        }
        return *this;
    }

};

struct Hash3d{
    size_t operator()(const RubiksCube3dArray &rc) const {
        string str = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    str += rc.cube[i][j][k];
                }
            }
        }
        return hash<string>()(str);
    }
};