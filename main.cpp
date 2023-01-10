#include "RubiksCube.cpp"
#include "DFS_SOLVER.h"

using namespace std;

int main() {
//    RubiksCube3dArray rubik1;
//    RubiksCube3dArray rubik2;



// // random shuffle
//
//    vector<RubiksCube::MOVE> all_moves = rubik1.random_shuffle_cube(1);
//    for(auto move:all_moves){
//        cout<<rubik1.getMove(move)<<"  ";
//    }
//    cout<<endl;
//
//    rubik1.print();



// // Equality and assignment of cubes
//
//    rubik1.move(RubiksCube::MOVE::U).move(RubiksCube::MOVE::U);
//
//    if(rubik1==rubik2) cout<<"matched";
//    else cout<<"not matching";
//
//    cout<<endl;
//
//    //rubik1.invert(RubiksCube::MOVE::U2);
//    rubik2=rubik1;
//
//    if(rubik1==rubik2) cout<<"matched";
//    else cout<<"not matching";
//
//    cout<<endl;
//
//    rubik2.print();



// // Unordered_map of Cubes
//
//    unordered_map<RubiksCube3dArray, bool, Hash3d> mp1;
//
//    mp1[rubik1]=true;
//    rubik2.l();
//
//    if (mp1[rubik1]) cout << "Cube1 is present";
//    else cout << "Cube1 is not present";
//
//    cout<<endl;
//
//    if (mp1[rubik2]) cout << "Cube2 is present";
//    else cout << "Cube2 is not present";
//
//    cout<<endl;
//
//    rubik1.print();
//    rubik2.print();

RubiksCube3dArray cube;

vector<RubiksCube::MOVE> moves = cube.random_shuffle_cube(4);

cube.print();

for(auto move:moves){
    cout<<cube.getMove(move)<<"  ";
}

cout<<endl;

DFS_SOLVER<RubiksCube3dArray,Hash3d> dfs_solver(cube,8);
    vector<RubiksCube::MOVE> solve_moves = dfs_solver.solve();
    for (auto move: solve_moves) cout << cube.getMove(move) <<"  ";
    cout << "\n";

    dfs_solver.rubiksCube.print();

return 0;
}
