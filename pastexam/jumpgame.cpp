#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

int visited[22][22], directx[5] = {0,0,1,-1}, directy[5] = {1,-1,0,0};
int mappa[22][22];
list<int> queue;
map<int, int> mapi,mapj;

int main(){
    int k,n,i,j,tmp1,b,tmpi,tmpj,power,end = 0,tmp5,tmp6,z;

    cin >> n >> z;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            cin >> tmp1;
            mappa[i][j] = tmp1;
        }
    }
    tmp1 = 1;
    visited[1][1] = 1;
    mapi[tmp1] = 1;
    mapj[tmp1] = 1;
    queue.push_back(tmp1);
    while(!queue.empty()){
        b = queue.front();
        queue.pop_front();
        tmpi = mapi[b];
        tmpj = mapj[b];
        power = mappa[tmpi][tmpj];
        for(k = 0; k < 4; k++){
            if(tmpi+directx[k] >= 1 && tmpi+directx[k] <= n && tmpj+directy[k] >= 1 && tmpj+directy[k] <= n && visited[tmpi+directx[k]][tmpj+directy[k]] == 0){
                if(mappa[tmpi+directx[k]][tmpj+directy[k]] <= power+z){
                    tmp1++;
                    visited[tmpi+directx[k]][tmpj+directy[k]] = 1;
                    queue.push_back(tmp1);
                    mapi[tmp1] = tmpi+directx[k];
                    mapj[tmp1] = tmpj+directy[k];
                    if(mapi[tmp1] == n && mapj[tmp1] == n){
                        end = 1;
                        break;
                    }
                }
            }
            if(end == 1){
                break;
            }
        }
        if(end == 1){
            break;
        }
    }
    if(end == 1){ 
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }
}