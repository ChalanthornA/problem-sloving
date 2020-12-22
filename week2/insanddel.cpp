#include <iostream>
#include <list>

using namespace std;

int main(){
    int m,i,j,tmp = 0;
    long n;
    char command;
    list<long> l;
    list<long>::iterator l1;

    cin >> m;
    for(i = 0; i< m; i++){
        cin >> command >> n;
        if(command == 'I'){
            l.push_front(n);
        }
        else if(command == 'D'){
            l1 = l.begin();
            if(n > l.size())
                continue;
            for(j = 1;j<n;j++){
                if(l1 == l.end()){
                    tmp = 1;
                    break;
                }
                l1++;
            }
            if(tmp == 0){
                l.erase(l1);
            }
            tmp = 0;
        }
    }
    for(l1 = l.begin();l1 != l.end();l1++){
        cout << *l1 << endl;
    }

}