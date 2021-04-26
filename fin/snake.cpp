#include <iostream>

using namespace std;

int board[1010];


int main(){
    int n, m, i, time, start = 0;

    cin >> n >> m;
    for(i = 1; i <= n; i++){
        cin >> board[i];
    }
    for(i = 1; i <= m; i++){
        cin >> time;
        start += time;
        if(board[start] != 0){
            start += board[start];
            if(start < 0){
                start = 0;
            }
            else if(start > n){
                start = n;
            }
        }
        if(start > n){
            start = n;
        }
    }
    cout << start << endl;
}