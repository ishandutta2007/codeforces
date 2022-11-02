#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int n;

int main(){
    cin >> n;
    int w = 0, h = 0;
    for(int i = 1;i <= n;i++){
        char s[3];
        scanf("%s", s);
        if(s[0] == '+'){
           int x, y;
           scanf("%d%d", &x,&y);
           if(x > y){
               swap(x, y);
           } 
           w = max(w, x);
           h = max(h, y);
        }
        else{
            int x, y;
            scanf("%d%d", &x, &y);
           if(x > y){
               swap(x, y);
           } 
           if(x >= w && y >= h){
               puts("YES");
           }else{
               puts("NO");
           }
        }
    }
    return 0;
}