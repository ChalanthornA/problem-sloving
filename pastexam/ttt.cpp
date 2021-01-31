#include <iostream>
#include <vector>
#include <list>

using namespace std;

vector<int> graph[1010];
list<int> queue;
int color[1010],status[1010];

int main(){
    int b,n,m,i,j,k,tmp1,tmp2,count=0,v,itmp = 1,num = 2,res = 1;

    cin >> n >> m;
    for(i = 0; i < m; i++){
        cin >> tmp1 >> tmp2;
        graph[tmp1].push_back(tmp2);
        graph[tmp2].push_back(tmp1);
    }
    for(i = 1; i <= n; i++){
        for(j = 0; j < graph[i].size();j++){
            itmp = i;
            num = graph[i][j];
            for(k = 1; k <= n; k++){
                color[k] = -1;
                status[k] = 0;
            }
            while(!queue.empty()){
                queue.pop_front();
            }
            res = 1;
            for(k = 1; k <= n; k++){
                if(status[k] == 0){
                    queue.push_back(k);
                    color[k] = 1;
                    status[k] = 1;
                    while(!queue.empty()){
                        b = queue.front();
                        queue.pop_front();
                        for(v = 0; v < graph[b].size(); v++){
                            if((b == itmp && graph[b][v] == num) || (b == num && graph[b][v] == itmp)){
                                continue;
                            }
                            if(color[graph[b][v]] == -1){
                                status[graph[b][v]] = 1;
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
                }
                if(res == 0){
                    break;
                }
            }
            if(res == 1){
                cout << itmp << " " << num << endl;
                break;
            }
        }
        if(res == 1){
            break;
        }
    }
}