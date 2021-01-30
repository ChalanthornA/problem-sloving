#include <iostream>
#include <queue>
#include <list>

using namespace std;

typedef struct bottle{
    int h;
    int bottlenum;
    bool operator<(const bottle& rsh) const{
        return h < rsh.h;
    }
}bot;

int status[100100];
priority_queue<bot> height;
bot fir;

int main(){
    int n,m,i,tmp,tmp2 = 0,tmp3,res,j,k;

    scanf("%d %d",&n,&m);
    for(i = 1; i <= n; i++){
        scanf("%d",&tmp);
        fir.h = tmp;
        fir.bottlenum = i;
        height.push(fir);
    }
    for(i = 1; i <= m; i++){
        scanf("%d",&tmp);
        res = 0;
        while(!height.empty()){
            tmp2 = (height.top()).h;
            if(tmp >= tmp2){
                printf("%d\n",res);
                break;
            }
            fir = height.top();
            height.pop();
            tmp3 = fir.bottlenum;
            if(status[tmp3] == 0){
                status[tmp3] = i;
                res++;
                if(tmp3+1 <= n && status[tmp3+1] == 0){
                    status[tmp3+1] = i;
                    res++;
                }
                if(tmp3-1 >= 1 && status[tmp3-1] == 0){
                    status[tmp3-1] = i;
                    res++;
                }
            }
            else if(status[tmp3] == i){
                if(tmp3+1 <= n && status[tmp3+1] == 0){
                    status[tmp3+1] = i;
                    res++;
                }
                if(tmp3-1 >= 1 && status[tmp3-1] == 0){
                    status[tmp3-1] = i;
                    res++;
                }
            }
            // for(k = 1; k <= n; k++){
            //     cout << status[k] << " ";
            // }
            // cout << endl;
        }
        printf("%d\n",res);
    }
}