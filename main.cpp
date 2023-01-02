#include "RubiksCube.cpp"

using namespace std;
int main() {
    Rubik rubik;
    rubik.random_shuffle_cube(1);
//    vector<RubiksCube::MOVE> all_moves = rubik.random_shuffle_cube(3);
//    for(auto move:all_moves){
//        cout<<rubik.getMove(move)<<"  ";
//    }
    cout<<endl;
    rubik.print();
    return 0;
}
