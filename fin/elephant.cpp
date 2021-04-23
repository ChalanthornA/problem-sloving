#include <iostream>

using namespace std;

int dp[100100], point[100100];

int main(){
    int n, i, maxx;

    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> point[i];
    }
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 0;
    maxx = 0;
    for(i = 3; i <= n; i++){
        dp[i] = max(dp[i-1], point[i]+dp[i-3]);
        if(maxx < dp[i]){
            maxx = dp[i];
        }
    }
    cout << maxx << endl;
}

/*
12 
1
2
5
4
3
0 
6 
1 
2 
7 
2 
1
*/