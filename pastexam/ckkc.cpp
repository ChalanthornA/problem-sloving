#include <iostream>

using namespace std;

int main(){
    int x,tmp,m=0;

    cin >> x;
    while(1){
        cin >> tmp;
        if(tmp == 0){
            break;
        }
        x+=1;
    }
    if(x % 2 == 0){
        cout << "K" << endl;
    }
    else{
        cout << "C" << endl; 
    }
}