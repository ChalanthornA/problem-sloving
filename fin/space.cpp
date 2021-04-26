#include <iostream>
#include <string.h>

using namespace std;

char T[200200], S[21];

int main(){
    int lT, lS, count = 0, i = 0, j = 0;
    cin >> S;
    cin >> T;
    lS = strlen(S);
    lT = strlen(T);
    for(i = 0; i <= lT - 1; i++){
        if(T[i] == S[j]){
            j++;
        }
        if(j == lS){
            count++;
            j = 0;
        }
    }
    cout << count << endl;
}