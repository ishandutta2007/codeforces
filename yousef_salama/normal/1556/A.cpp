#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int c, d;
        scanf("%d %d", &c, &d);

        if((c + d) % 2 != 0){
            printf("-1\n");
            continue;
        }

        if(c == 0 && d == 0){
            printf("0\n");
        }else if(c == d){
            printf("1\n");
        }else{
            printf("2\n");
        }
    }
    return 0;
}