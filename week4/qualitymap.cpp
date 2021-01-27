#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

int visited[33][33], directx[5] = {0,0,1,-1}, directy[5] = {1,-1,0,0};
char mappa[33][33];
list<int> queue;

int main(){
    int n,m,i,j,high = 0, med = 0,b,qua = 0,tmp = 0,dot=0,tmpi,tmpj,k,count=0,din = 0,rar = 0,tmp5,tmp6;
    char line[33];
    map<int, int> mapi,mapj;

    cin >> n >> m;
    for(i = 1; i <= n; i++){
        cin >> line;
        for(j = 1; j <= m; j++){
            mappa[i][j] = line[j-1];
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(visited[i][j] != 1 && mappa[i][j] != '#'){
                tmp++;
                visited[i][j] = 1;
                mapi[tmp] = i;
                mapj[tmp] = j;
                queue.push_back(tmp);
                dot = 0;
                while(!queue.empty()){
                    b = queue.front();
                    queue.pop_front();
                    tmpi = mapi[b];
                    tmpj = mapj[b];
                    if(mappa[tmpi][tmpj] == '*'){
                        din = 1;
                    }
                    else if(mappa[tmpi][tmpj] == '$'){
                        rar = 1;
                    }
                    dot += 1;
                    for(k = 0; k<4; k++){
                        if(tmpi+directx[k] >= 1 && tmpi+directx[k] <= n && tmpj+directy[k] >= 1 && tmpj+directy[k] <= m && visited[tmpi+directx[k]][tmpj+directy[k]] != 1){
                            if(mappa[tmpi+directx[k]][tmpj+directy[k]] != '#'){
                                tmp++;
                                visited[tmpi+directx[k]][tmpj+directy[k]] = 1;
                                queue.push_back(tmp);
                                mapi[tmp] = tmpi+directx[k];
                                mapj[tmp] = tmpj+directy[k];
                            }
                        }
                    }
                }
                if(din == 1 && rar == 1){
                    high += dot;
                    dot = 0;
                    din = 0;
                    rar = 0;
                }
                else if(din == 0 && rar == 0){
                    dot = 0;
                }
                else{
                    med += dot;
                    dot = 0;
                    din = 0;
                    rar = 0;
                }
            }
        }
    }
    cout << high << " " << med << endl;
}