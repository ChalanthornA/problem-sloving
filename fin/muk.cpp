#include <iostream>
#include <string.h>

using namespace std;

char name[110], word[100010];

int main(){
    int count = 0, i = 0, lname, lword ,tmp = 0;
    cin >> name;
    cin >> word;
    lname = strlen(name) - 1;
    lword = strlen(word);
    for(i = 0; i < lword; i++){
        if(word[i] == name[tmp]){
            if(tmp == lname){
                count += 1;
                tmp = 0;
            }
            else{
                tmp += 1;
            }
        }
    }
    cout << count << endl;
}