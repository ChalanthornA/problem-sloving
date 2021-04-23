#include <iostream>
#include <set>

using namespace std;

int main(){
    set<int> p;
    set<int>::iterator it1;
    p.insert(10);
    p.insert(10);
    p.insert(10);
    p.insert(100);
    for(it1 = p.begin(); it1 != p.end(); it1++){
        cout << *it1 << endl;
    }
}