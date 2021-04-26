#include <iostream>

using namespace std;

int score[110][2];

int main(){
    int n, m, i, a, s, res = 0;
    cin >> n >> m;
    for(i = 0; i < m; i++){
        cin >> a >> s;
        if(s > score[a][0]){
            score[a][0] = s;
        }
        score[a][1] += 1;
    }
    for(i = 1; i <= n; i++){
        if(score[i][1] > 5){
            continue;
        }
        res += score[i][0];
    }
    cout << res << endl;
}

/*
3 10 
1 9
2 8 
1 3 
1 4 
3 8 
3 7 
1 1 
1 9 
1 10 
2 9
*/