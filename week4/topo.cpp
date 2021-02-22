#include <iostream>
#include <vector>
#include <list>

using namespace std;

list<int> q;
vector<int> graph[100100];
int visited[100100], degin[100100],res[100100];

int main(){
    int n,m,i,j,tmp1,tmp2,b,numres = 0;

    cin >> n >> m;
    for(i = 0; i < m; i++){
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        degin[tmp2] += 1;
    }
    for(i = 1; i <= n; i++){
        if(degin[i] == 0){
            q.push_back(i);
        }
    }
    while(!q.empty()){
        b = q.front();
        q.pop_front();
        numres+=1;
        res[numres] = b;
        for(j = 0;j < graph[b].size(); j++){
            degin[graph[b][j]]--;
            if(degin[graph[b][j]] == 0){
                q.push_back(graph[b][j]);
            }
        }
    }
    if(numres != n){
        cout << "no" << endl;
    }
    else{
        for(i = 1; i <= numres; i++){
            cout << res[i] << endl;
        }
    }
} 