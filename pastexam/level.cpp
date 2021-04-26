#include <iostream>

using namespace std;

int level[110][3];

int main(){
    int n, m, i, st1 = 0, st2 = 0, st3 = 0, sl = 1, pl1, pl2, pl3;

    cin >> n >> m;
    for(i = 1; i <= n-1; i++){
        cin >> level[i][0] >> level[i][1] >> level[i][2];
    }
    for(i = 1; i <= m; i++){
        cin >> pl1 >> pl2 >> pl3;
        if(pl1 >= level[sl][0]){
            st1 = 1;
        }
        if(pl2 >= level[sl][1]){
            st2 = 1;
        }
        if(pl3 >= level[sl][2]){
            st3 = 1;
        }
        if(st1 == 1 && st2 == 1 && st3 == 1 && sl < n){
            st1 = 0;
            st2 = 0;
            st3 = 0;
            sl += 1;
        }
        // cout << endl;
        // cout << "this" << sl << endl;
        // cout << "st" << st1 << " " << st2 << " " << st3 << endl;
    }
    cout << sl << endl;
}

/*
4 5
1000 10 0
0 0 0
0 5 10
1230 5 15
10 9 100
5 11 0
1 1 1
0 4 15
*/