#include <iostream>
#include <map>

using namespace std;

int main(){
    int n,i,tmp1,tmp2,tmp3;
    map<int, pair<int, int> >::iterator it1;
    map<int, pair<int, int> > test;
    
    cin >> n;
    for(i = 0; i<n; i++){
        cin >> tmp1 >> tmp2 >> tmp3;
        test[tmp1].first = tmp2;
        test[tmp1].second = tmp3;
    }
    cout << test[12].first << endl;
    for(it1 = test.begin(); it1 != test.end(); it1++){
        cout << it1->first << test[it1->first].first << test[it1->first].second << endl;
    }
}