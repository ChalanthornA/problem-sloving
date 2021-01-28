#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

int visited[33][33], directx[5] = {0,0,1,-1}, directy[5] = {1,-1,0,0};
char mappa[33][33];
list<int> queue;
char line[33];

int main(){
    int n,m,i,tmp = 0,j,tmpi,tmpj,end = 0,k,b,tmp5,tmp6;
    map<int, int> mapi,mapj;

    cin >> n >> m;
    for(i = 1; i <= n; i++){
        cin >> line;
        for(j = 1; j <= m; j++){
            mappa[i][j] = line[j-1];
        }
    }
    for(i = 1; i <= 1; i++){
        for(j = 1; j <= m; j++){
            if(visited[i][j] != 1 && mappa[i][j] != '#'){
                // cout << i << " " << j << endl;
                tmp++;
                visited[i][j] = 1;
                mapi[tmp] = i;
                mapj[tmp] = j;
                queue.push_back(tmp);
                while(!queue.empty()){
                    b = queue.front();
                    queue.pop_front();
                    tmpi = mapi[b];
                    tmpj = mapj[b];
                    if(tmpj+1 <= m && tmpi+1 <= n){
                        // cout << "YYYY" <<endl;
                        if(mappa[tmpi][tmpj+1] != '#' && mappa[tmpi+1][tmpj] != '#' && mappa[tmpi][tmpj] != '#' && mappa[tmpi+1][tmpj+1] != '#'){
                            for(k = 0; k<4; k++){
                                if(tmpi+directx[k] >= 1 && tmpi+directx[k] <= n && tmpj+directy[k] >= 1 && tmpj+directy[k] <= m && visited[tmpi+directx[k]][tmpj+directy[k]] != 1){
                                    if(mappa[tmpi+directx[k]][tmpj+directy[k]] != '#'){
                                        tmp++;
                                        visited[tmpi+directx[k]][tmpj+directy[k]] = 1;
                                        queue.push_back(tmp);
                                        mapi[tmp] = tmpi+directx[k];
                                        mapj[tmp] = tmpj+directy[k];
                                        mappa[tmpi][tmpj] = 's';
                                        // for(tmp5 = 1; tmp5 <= n; tmp5++){
                                        //     for(tmp6 = 1; tmp6 <=m; tmp6++){
                                        //         cout << mappa[tmp5][tmp6];
                                        //     }
                                        //     cout << endl;
                                        // }
                                        // cout << "YYYY" << endl;
                                        if(tmpi == n-1){
                                            end = 1;
                                            break;
                                        }
                                    }
                                }
                                if(end == 1){
                                    break;
                                }
                            }
                        }
                    }
                    if(end == 1){
                        break;
                    }
                }
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