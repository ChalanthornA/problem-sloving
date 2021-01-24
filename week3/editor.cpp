#include <iostream>
#include <list>
using namespace std;

list<string> word;
list<string>::iterator it,it2;
char command,w[100];

int main(){
    int n,i;

    cin >> n;
    it = word.begin();

    for(i = 0; i<n; i++){
        cin >> command;
        if(command == 'i'){
            cin >> w;
            it = word.insert(it,w);
            it++;
        }
       else if(command == 'l'){
            if(it == word.begin()){
                continue;
            }
            it--;
        }
        else if(command == 'r'){
            if(it == word.end()){
                continue;
            }
            it++;
        }
        else if(command == 'b'){
            if(it == word.begin()){
                continue;
            }
            it--;
            it2 = it;
            it--;
            word.erase(it2);
            it++;
        }
        else if(command == 'd'){
            if(it == word.end()){
                continue;
            }
            it2 = it;
            it--;
            word.erase(it2);
            it++;
        }
        // cout << "ttttttt" << endl;
        // for(it2 = word.begin();it2 != word.end();it2++){
        //     cout << *it2 << " ";
        // }
        // cout << endl;
    }
    for(it = word.begin();it!=word.end();it++){
        cout << *it << " ";
    }
    cout << endl;
}