#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int a1, a2, a3;
        scanf("%d %d %d", &a1, &a2, &a3);

        int s = abs(a1 + a3 - 2 * a2);
        if(s % 3 == 0)printf("0\n");
        else printf("1\n");
    }
    return 0;
}