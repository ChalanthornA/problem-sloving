#include <iostream>
#include <list>

using namespace std;

int main(){
    long i,j,k,n,max=0;
    char command;
    list<long> chala[100000];
    list<long>::iterator it;

    cin >> n;
    for(k = 0;k<n;k++){
        cin >> command >> i >> j;
        if(command == 'N'){
            chala[j].push_back(i);
        }
        else{
            it = chala[j].end();
            chala[j].splice(it,chala[i]);
        }
    }
    for(k = 0; k<100000; k++){
        if(chala[k].size() == 0){
            continue;
        }
        for(it = chala[k].begin(); it != chala[k].end();it++){
            cout << *(it) << "\n";
        }
    }
}