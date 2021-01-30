#include <iostream>
#include <vector>
#include <list>

using namespace std;

void addEdge(vector<int> adj[], int s, int d) {
  adj[s].push_back(d);
  adj[d].push_back(s);
}

list<int> queue;
vector<int> navi[100100];
int status[100100];

int main(){
    int b,n,m,k,i,j,tmp1,tmp2,tmp3 = 0;

    scanf("%d %d %d",&n,&m,&k);
    for (i = 0; i < m; i++){
        scanf("%d %d",&tmp1,&tmp2);
        addEdge(navi,tmp1,tmp2);
    }

    for(i = 1; i <= n; i++){
        if(status[i] == 0){
            tmp3++;
            queue.push_back(i);
            status[i] = tmp3;
        }
        while(!queue.empty()){
            b = queue.front();
            queue.pop_front();
            for(j=0; j < navi[b].size(); j++){
                if(status[navi[b][j]] == 0){
                    status[navi[b][j]] = tmp3;
                    queue.push_back(navi[b][j]);
                }
            }
        }
    }

    for(i = 1; i <= k;i++){
        scanf("%d %d",&tmp1,&tmp2);
        if(status[tmp1] == status[tmp2]){
            printf("1\n");
        }
        else{
            printf("0\n");
        }
    }
}