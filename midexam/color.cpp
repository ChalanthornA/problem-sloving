#include <iostream>
#include <vector>
#include <list>


using namespace std;

vector<int> graphb[50050],graphr[50050];
int visitedb[50050],visitedr[50050],distb[50050],distr[50050];
list<int> queueb,queuer;

int main(){
    int n,m,s,t,i,tmp1,tmp2,c,res,b,end = 0;;

    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(i = 1; i <= m; i++){
        cin >> tmp1 >> tmp2 >> c;
        if(c == 0){
            graphb[tmp1].push_back(tmp2);
            graphb[tmp2].push_back(tmp1);
            graphr[tmp1].push_back(tmp2);
            graphr[tmp2].push_back(tmp1);
        }
        else if(c == 1){
            graphr[tmp1].push_back(tmp2);
            graphr[tmp2].push_back(tmp1);
        }
        else if(c == 2){
            graphb[tmp1].push_back(tmp2);
            graphb[tmp2].push_back(tmp1);
        }
    }   
    queueb.push_back(s);
    visitedb[s] = 1;
    distb[s] = 0;
    while(!queueb.empty()){
        b = queueb.front();
        queueb.pop_front();
        for(i = 0; i < graphb[b].size(); i++){
            if(visitedb[graphb[b][i]] == 0){
                visitedb[graphb[b][i]] = 1;
                distb[graphb[b][i]] = distb[b] + 1;
                queueb.push_back(graphb[b][i]);
                if(graphb[b][i] == t){
                    res = distb[t];
                    end = 1;
                    break;
                }
            }
        }
        if(end == 1){
            break;
        }
    }
    end = 0;
    queuer.push_back(s);
    visitedr[s] = 1;
    distr[s] = 0;
    while(!queuer.empty()){
        b = queuer.front();
        queuer.pop_front();
        for(i = 0; i < graphr[b].size(); i++){
            if(visitedr[graphr[b][i]] == 0){
                visitedr[graphr[b][i]] = 1;
                distr[graphr[b][i]] = distr[b] + 1;
                queuer.push_back(graphr[b][i]);
                if(graphr[b][i] == t){
                    if(res > distr[t]){
                        res = distr[t];
                    }
                    end = 1;
                    break;
                }
            }
        }
        if(end == 1){
            break;
        }
    }
    if(res == 0){
        res = -1;
    }
    cout << res << endl;
}