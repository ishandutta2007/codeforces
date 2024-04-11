#include <bits/stdc++.h>
using namespace std;

int n, k, m, a, b;
int main(){
    scanf("%d %d", &n, &k);
    
    int r = n - 1;
    for(int i = 0; i < k; i++){
        scanf("%d", &m);
        r += m - 1;
        
        scanf("%d", &b);
        for(int j = 2; j <= m; j++){
            scanf("%d", &a);
            
            if(b == 1 && a == j)r -= 2;
        }
    }
    printf("%d\n", r);
    
    return 0;
}