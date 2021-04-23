#include <iostream>
#include <vector>

using namespace std;
#define MxN 100000

int dp[MxN+1];
typedef struct sc{
    int x,y,w;
}sc;
sc schedule[MxN+1];
vector<int> set_sc[MxN+1];
int value(int i){
//    cout << i << "\n";
    if (i == 0)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int j = i-1;
    while(j>0 && schedule[i].x < schedule[j].y)
        j--;
    if(value(i-1) > schedule[i].w + value(j)) {
        set_sc[i] = set_sc[i-1];
        return dp[i] = value(i-1);
    }
    else{
        set_sc[i] = set_sc[j];
        set_sc[i].push_back(i);
        return dp[i] = schedule[i].w + value(j);
    }
}

int main(){
    int n;
    cin >> n;
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        cin >> schedule[i].x >> schedule[i].y >> schedule[i].w;
        dp[i] = -1;
    }
    cout << value(n) << '\n';
    cout << set_sc[n].size()<< "\n";
    for(int it:set_sc[n])
        cout << it << ' ';
    return 0;
}