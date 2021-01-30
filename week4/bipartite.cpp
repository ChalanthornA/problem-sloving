#include <iostream>
#include <vector>
#include <list>

using namespace std;

int color[100100];
list<int> queue;
vector<int> graph[100100];

int main(){
    int k,n,m,i,j,tmp1,tmp2,b,v,res = 1;
     
    cin >> k;
    for(i = 0 ; i < k; i++){
        res = 1;
        cin >> n >> m;
        for(j = 1; j <= n; j++){
            color[j] = -1;
        }
        for(j = 0; j < m; j++){
            cin >> tmp1 >> tmp2;
            graph[tmp1].push_back(tmp2);
            graph[tmp2].push_back(tmp1);
        }
        queue.push_back(1);
        color[1] = 1;
        while(!queue.empty()){
            b = queue.front();
            queue.pop_front();
            for(v = 0; v < graph[b].size(); v++){
                if(color[graph[b][v]] == -1){
                    queue.push_back(graph[b][v]);
                    color[graph[b][v]] = 1 - color[b];
                }
                else if(color[graph[b][v]] == color[b]){
                    res = 0;
                    break;
                }
            }
            if(res == 0){
                break;
            }
        } 
        if(res == 1){
            cout << "yes" << endl;
        }
        else{
            cout << "no" << endl;
        }
        for(j = 1; j <= n; j++){
            color[j] = -1;
            graph[j].clear();
        }
        while(!queue.empty()){
            queue.pop_front();
        }
    }
}