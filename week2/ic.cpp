#include <iostream>
#include <list>
#include <string.h>

using namespace std;

int main(){
    int m,i,n,tmp;
    char command[3];
    list<int> l;
    list<int>::iterator l1;

    cin >> m;
    for(i=0; i<m; i++){
        cin >> command;
        if(strcmp(command,"li") == 0){
            cin >> n;
            l.push_front(n);
        }
        else if(strcmp(command,"ri") == 0){
            cin >> n;
            l.push_back(n);
        }
        else if(strcmp(command,"lr") == 0){
            tmp = *(l.begin());
            l.push_back(tmp);
            l.pop_front();
        }
        else if(strcmp(command,"rr") == 0){
            l1 = l.end();
            l1--;
            l.push_front(*l1);
            l.pop_back();
        }
    }
    for(l1 = l.begin(); l1 != l.end();l1++){
        cout << *l1 << endl;
    }
}