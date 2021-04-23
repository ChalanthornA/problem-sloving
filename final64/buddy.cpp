#include <iostream>
#include <vector>
#include <list>

using namespace std;

int status[100100];
vector<int> graph[100100];
list<int> q;

int main(){
    int n,m,res = 0,node1,node2,b,i,j,s;
    cin >> n;
    for(i = 1; i <= n; i++){
        cin >> s;
        graph[i].push_back(s);
    }
    for(i = 1; i <= n; i++){
        if(status[i] == 0){
            q.push_back(i);
            status[i] = 1;
            while(!q.empty()){
                b = q.front();
                q.pop_front();
                for(j = 0;j < graph[b].size(); j++){
                    if(status[graph[b][j]] != 1){
                        status[graph[b][j]] = 1;
                        q.push_back(graph[b][j]);
                    }
                }
            }
            res+=1;
        }
    }
    cout << res << endl;
}