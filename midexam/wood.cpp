#include <iostream>
#include <map>

using namespace std;

map<int, int> wood;
map<int, int>::iterator it1;
int height[100100], res[100100];

int main(){
    int i,m,tmp,count = 0,stack,j;

    scanf("%d",&m);
    for(i = 1; i <= m;i++){
        scanf("%d",&tmp);
        height[i] = tmp;
        if(tmp != 0){
            count++;
        }
    }
    tmp = 0;
    while(count != 0){
        stack = 0;
        for(i = 1; i <= m; i++){
            if(stack == 0 && height[i] == 0){
                continue;
            }
            if(height[i] == 0 && stack != 0){
                if(wood[stack] == 0){
                    tmp++;
                    wood[stack] = tmp;
                    res[tmp] += 1;
                    stack = 0;
                }
                else{
                    res[wood[stack]] += 1;
                    stack = 0;
                }
            } 
            else if(height[i] != 0){
                stack += 1;
                height[i] -= 1;
                if(height[i] == 0){
                    count--;
                }
                if(i == m){
                    if(wood[stack] == 0){
                        tmp++;
                        wood[stack] = tmp;
                        res[tmp] += 1;
                        stack = 0;
                    }
                    else{
                        res[wood[stack]] += 1;
                        stack = 0;
                    }
                }
            }
        }
        // for(j = 1; j <= m; j++){
        //     cout << height[j] << " ";
        // }
        // cout << endl;
        // for(it1 = wood.begin(); it1 != wood.end();it1++){
        //     cout << it1->first << " " << res[wood[it1->first]] << endl;
        // }
    }
    printf("%d\n",tmp);
    for(it1 = wood.begin(); it1 != wood.end();it1++){
        printf("%d %d\n",it1->first,res[wood[it1->first]]);
    }
}