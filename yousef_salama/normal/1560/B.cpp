#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    
    while(t--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        int n = abs(a - b);
        if(2 * n < max(max(a, b), c))printf("-1\n");
        else printf("%d\n", (c + n - 1) % (2 * n) + 1);
    }
    return 0;
}