#include <iostream>

using namespace std;
int tora[100100], taro[100100], dp[1000][1000];

int main(){
    int c, n, k, i, j, l, m, minn;

    cin >> c;
    for(i = 0; i < c; i++){
        cin >> n >> k;
        for(j = 1; j <= n; j++){
            cin >> taro[j] >> tora[j];
        }
        minn = 99999999;
        for(j = 0; j <= n; j++){
            for(l = 0; l <= n ; l++){
                if(j == 0 && l == 0){
                    // cout << "A";
                    dp[j][l] = 0;
                }
                else if(j-l > k || l-j > k){
                    // cout << "B";
                    dp[j][l] = -100;
                }
                else if(j == 0 && l != 0){
                    // cout << "C";
                    dp[j][l] = dp[j][l-1] + taro[l];
                }
                else if(l == 0 && j != 0){
                    // cout << "D";
                    dp[j][l] = dp[j-1][l] + tora[j];
                }
                else if(dp[j][l-1] == -100){
                    // cout << "E";
                    dp[j][l] = dp[j-1][l] + tora[j+l];
                }
                else if(dp[j-1][l] == -100){
                    // cout << "F";
                    dp[j][l] = dp[j][l-1] + taro[j+l];
                }
                else{
                    // cout << "G";
                    dp[j][l] = min(dp[j-1][l] + tora[j+l], dp[j][l-1] + taro[j+l]);
                    // cout << dp[j-1][l] << tora[j+l] << "and" << dp[l][j-1] << taro[j+l] << " ";
                }
                // cout << dp[j][l] << " ";
                if(j+l == n && minn > dp[j][l] && dp[j][l] != -100){
                    minn = dp[j][l];
                }
            }
            // cout << endl;
        }
        cout << minn << endl;
        for(j = 0; j <= n; j++){
            taro[j] = 0;
            tora[j] = 0;
            for(l = 0; l <= n ; l++){
                dp[j][l] = 0;
            }
        }
    }
}