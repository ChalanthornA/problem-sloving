#include <iostream>

using namespace std;

int dp[1000][1000], taro[100100], tora[100100];

int main(){
    int c, n, k, i, j, l;

    cin >> c;
    for(i = 0; i < c; i++){
        cin >> n >> k;
        for(j = 1; j <= n; j++){
            cin >> taro[j] >> tora[j];
        }
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        for(j = 1; j <= n; j++){
            if(dp[j-1][1] - dp[j-1][2] > -k && dp[j-1][1] - dp[j-1][2] < k){
                if(taro[j] < tora[j]){
                    dp[j][0] = dp[j-1][0] + taro[j];
                    dp[j][1] = dp[j-1][1] + 1;
                }
                else{
                    dp[j][0] = dp[j-1][0] + tora[j];
                    dp[j][2] = dp[j-1][2] + 1;
                }
            }
            else if(dp[j-1][1] - dp[j-1][2] >= k || dp[j-1][1] - dp[j-1][2] <= -k){
                if(dp[j-1][1] > dp[j-1][2]){
                    dp[j][0] = dp[j-1][0] + tora[j];
                    dp[j][2] = dp[j-1][2] + 1;
                }
                else{
                    dp[j][0] = dp[j-1][0] + taro[j];
                    dp[j][1] = dp[j-1][1] + 1;
                }
            }
        }
        cout << dp[n][0] << endl;
        for(j = 1; j <= n; j++){
            taro[j] = 0;
            tora[j] = 0;
            dp[j][0] = 0;
            dp[j][1] = 0;
            dp[j][2] = 0;
        }
    }
}

/*
4 2
1 2
1 2
1 2
1 2
4 2
5 2
2 5
5 2
2 5
*/