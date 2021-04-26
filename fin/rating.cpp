#include <iostream>

using namespace std;

int rating[100100], dp[100100], winner[100100];


int main(){
    int n, m, i, maxx, tmp, tmp2, j;
    cin >> n >> m;
    for(i = 1; i <= m; i++){
        cin >> rating[i];
    }
    dp[1] = 1;
    winner[1] = rating[1];
    for(i = 2; i <= m; i++){
        maxx = -100;
        for(j = i - 1;j >= i - 6; j--){
            if(i <= 0){
                continue;
            }
            if(winner[j] == rating[i]){
                tmp = dp[j]+1;
                if(maxx <= tmp){
                    maxx = tmp;
                    tmp2 = rating[i];
                }
            }
        }
        if(maxx == -100){
            dp[i] = 1;
            winner[i] = rating[i];
        }
        else{
            dp[i] = maxx;
            winner[i] = tmp2;
        }
       
        // for(j = 1; j <= m; j++){
        //     cout << winner[j] << " "; 
        // }
        // cout << endl;
    }
    maxx = -100;
    for(i = 1; i <= m; i++){
        if(maxx <= dp[i]){
            maxx = dp[i];
            tmp = i;
        }
    }
    cout << winner[tmp] << " ";
    cout << dp[tmp] << endl;
}


/*
9 19
1 1 3 2 3 3 4 4 5 2 4 3 6 7 8 9 1 2 3

5 10
3 3 3 3 1 2 2 2 2 1
*/
