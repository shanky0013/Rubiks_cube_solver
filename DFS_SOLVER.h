//
// Created by biswajit mahalik on 10/01/23.
//

//#include"RubiksCube.h"
#include<bits/stdc++.h>

#ifndef RUBIKS_CUBE_DFS_SOLVER_H
#define RUBIKS_CUBE_DFS_SOLVER_H

template<typename T,typename H>
class DFS_SOLVER {
private:

    vector<RubiksCube::MOVE> moves;
    int max_depth;

    bool dfs(int depth){
        if(rubiksCube.is_solved()) return true;
        if(depth>max_depth) return false;

        for (int i = 0; i < 18; ++i) {
            rubiksCube.move(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));
            if(dfs(depth+1)) return true;
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }

public:

T rubiksCube;

DFS_SOLVER(T _cube,int _max_depth=8){
    rubiksCube=_cube;
    max_depth=_max_depth;
}

vector<RubiksCube::MOVE> solve(){
    dfs(1);
    return moves;
}

T final_cube(){
    return rubiksCube;
}

};


#endif //RUBIKS_CUBE_DFS_SOLVER_H
