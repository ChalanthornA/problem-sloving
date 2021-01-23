#include <iostream>
#include <map>

using namespace std;

long status[110000];

int main(){
    long n,max=0,maxn=0,i,tmp,j = 1,tmp2;
    map<long,long> res;
    cin >> n;
    for(i = 0; i<n; i++){
        cin >> tmp;
        if(res[tmp] == 0){
            res[tmp] = j;
            status[j] += 1;
            if(max < status[j]){
                max = status[j];
                maxn = tmp;
            }
            else if(max == status[j]){
                maxn = tmp;
            }
            j++;
        }
        else{
            tmp2 = res[tmp];
            status[tmp2] += 1;
            if(max < status[tmp2]){
                max = status[tmp2];
                maxn = tmp;
            }
            else if(max == status[tmp2]){
                maxn = tmp;
            }
        }
        cout << maxn <<endl;
    }
}