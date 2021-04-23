#include <iostream>
#include <vector>

using namespace std;

typedef struct in_aray{
    int s, t, w;
}in_aray;

vector<int> des[1010];
vector<int>::iterator it1;

int dp[1010][2];
in_aray req[1010];

int main(){
    int i, j, n, maxx, tmp;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> req[i].s >> req[i].t >> req[i].w;
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    for(i = 1; i <= n; i++){
        maxx = -1;
        for(j = i-1; j >= 1; j--){
            if(maxx < dp[j][0] && dp[j][1] <= req[i].s){
                maxx = dp[j][0];
                tmp = j;
            }
        }
        if(maxx == -1){
            dp[i][0] = req[i].w;
            dp[i][1] = req[i].t;
            des[i].push_back(i);
        }
        else{
            dp[i][0] = maxx + req[i].w;
            dp[i][1] = req[i].t;
            des[i] = des[tmp];
            des[i].push_back(i);
        }
    }
    maxx = -1;
    for(i = 1; i <= n; i++){
        if(maxx < dp[i][0]){
            maxx = dp[i][0];
            tmp = i;
        }
    }
    cout << maxx << endl;
    cout << des[tmp].size() << endl;
    for(it1 = des[tmp].begin(); it1 != des[tmp].end(); it1++){
        cout << *(it1) << " "; 
    }
    cout << endl; 
    // sort(req+1, req+n+1);
    // for(i = 1; i <= n; i++){
    //     cout << req[i].s << req[i].t << req[i].w << endl;
    // }
}