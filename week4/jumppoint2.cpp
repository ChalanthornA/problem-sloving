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
int status[1111];

int main(){
    int n,r,res=0,i,x,y,j,end=0,b;
    double dist;
    list<int> tmp,tmp2;
    list<int>::iterator itl1,itl2;

    cin >> n >> r; 
    vector<int> tree[n+2];
    vector<int>::iterator it1,it2;
    
    pak[0][0] = 0;
    pak[0][1] = 0;
    pak[n+1][0] = 100;
    pak[n+1][1] = 100;
    for(i = 1; i <= n; i++){
        cin >> x >> y;
        pak[i][0] = x;
        pak[i][1] = y;
        for(j = i-1; j >= 0; j--){
            dist = sqrt(pow(pak[i][0]-pak[j][0],2)+pow(pak[i][1]-pak[j][1],2));
            if(dist <= r){
                addEdge(tree,i,j);
            }
        }
    }
    for(i = 0; i<=n; i++){
        dist = sqrt(pow(pak[i][0]-pak[n+1][0],2)+pow(pak[i][1]-pak[n+1][1],2));
        if(dist <= r){
            addEdge(tree,i,n+1);
        }
    }
    tmp.push_back(0);
    status[0] = 1;
    while(1){
        if(tmp2.size() == 0){
            while(1){
                if(tmp.size() == 0){
                    break;
                }
                itl1 = tmp.begin();
                b = *(itl1);
                for(it1 = tree[b].begin(); it1 != tree[b].end(); it1++){
                    if(*it1 == n+1){
                        res += 1;
                        end = 1;
                        break;
                    }
                    if(status[*it1] == 1){
                        continue;
                    }
                    tmp2.push_back(*(it1));
                    status[*it1] = 1;
                }
                tmp.pop_front();
                if(end == 1){
                    break;
                }
            }
        }
        else{
            while(1){
                if(tmp2.size() == 0){
                    break;
                }
                itl1 = tmp2.begin();
                tmp.push_back(*itl1);
                tmp2.pop_front();
            }
            res+=1;
        }
        if(end == 1){
            break;
        }
    }
    if(end == 1){
        cout << res << endl;
    }
    else{
        cout << -1 << endl;
    }
}