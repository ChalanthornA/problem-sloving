#include <iostream>
#include <cmath>
#include <vector>
#include <list>

using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

int pak[1010][3];
int visited[1111];
int res[1111];
vector<int> tree[1100];

int main(){
    int n,r,i,x,y,j,end = 0,b;
    double dist;
    list<int> queue;

    cin >> n >> r; 
    
    pak[0][0] = 0;
    pak[0][1] = 0;
    pak[n+1][0] = 100;
    pak[n+1][1] = 100;
    for(i = 1; i <= n; i++){
        cin >> x >> y;
        pak[i][0] = x;
        pak[i][1] = y;
    }
    for(i = 0; i <= n+1; i++){
        for(j = i+1; j <= n+1; j++){
            dist = sqrt(pow(pak[i][0]-pak[j][0],2)+pow(pak[i][1]-pak[j][1],2));
            if(dist <= r){
                addEdge(tree,i,j);
            }
        }
    }
    queue.push_back(0);
    visited[0] = 1;
    res[0] = 0;
    while(!queue.empty()){
        b = queue.front();
        queue.pop_front();
        for(i = 0;i < tree[b].size(); i++){
            if(visited[tree[b][i]] != 1){
                visited[tree[b][i]] = 1;
                res[tree[b][i]] = res[b]+1;
                queue.push_back(tree[b][i]);
            }
            if(tree[b][i] == n+1){
                end = 1;
                break;
            }
        }
        if(end == 1){
            break;
        }
    }
    if(end == 1){
        cout << res[n+1] << endl;
    }
    else{
        cout << -1 << endl;
    }
}