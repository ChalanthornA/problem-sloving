#include <iostream>
#include <list>

using namespace std;

list<long> l[300001];
list<long>::iterator l1,l2,lp[300001],lc[300001];

int main(){
    long n,i,x,y,tmp,tmp1,tmp2;

    cin >> n;
    for(i = 1;i <= n; i++){
        l[i].push_back(i);
        l1 = l[i].begin();
        lp[i] = l1;
        // lc[i] = l1;
    }
    for(i = 1;i<n;i++){
        cin >> x >> y;
        // l1 = lp[y];
        // l1++;
        // l[y].splice(l1,l[x]);
        // lp[x] = lp[y];
        // lc[x] = 

        if(l[x].size() == 1 && l[y].size() == 1){
            tmp = *(l[x].begin());
            l[y].push_back(tmp);
            l1 = l[y].begin();
            lp[x] = l1;
            l1++;
            l[x].clear();
            lc[x] = l1;
        }
        else{
            if(l[y].size() == 0){
                l1 = lp[y];
                l2 = lc[y];
                l2++;
                tmp = *(l1);
                l[tmp].splice(l2,l[x]);
                tmp2 = tmp;
                lp[x] = l[tmp].begin();
                lc[x] = l2;
            }
            else{
                l1 = l[y].begin();
                l1++;
                l[y].splice(l1,l[x]);
                lp[x] = l[y].begin();
                lc[x] = l1;
                tmp2 = y;
            }
            // tmp1 = 0;
            // for(int j = 1;j <= n; j++){
            //     // cout << j << "\n";
            //     if(l[j].size() == 0){
            //         continue;
            //     }
            //     for(l1 = l[j].begin(); l1 != l[j].end(); l1++){
            //         // cout << *(l1) << "\n";
            //         if(*(l1) == y){
            //             l1++;
            //             l[j].splice(l1,l[x]);
            //             tmp1 = 1;
            //             break;
            //         }
            //     }
            //     if(tmp1 == 1){
            //         tmp2 = j;
            //         break;
            //     }
            // }
        }
    }
    for(l1 = l[tmp2].begin(); l1!=l[tmp2].end();l1++){
        cout << *(l1) << " ";
    }
    cout << "\n";
}