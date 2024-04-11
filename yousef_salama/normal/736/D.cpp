#include <bits/stdc++.h>
using namespace std;

int n, m, a[500005], b[500005];
bitset <2005> E[2005], C[2005];

int main(){
    scanf("%d %d", &n, &m);
        
    for(int e = 0; e < m; e++){
        scanf("%d %d", &a[e], &b[e]);
        
        a[e]--;
        b[e]--;
        
        E[a[e]][b[e]] = 1;
    }
    
    for(int i = 0; i < n; i++)
        C[i][i] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++)if(E[j][i]){
            swap(E[j], E[i]);
            swap(C[j], C[i]);
            
            break;
        }
            
        for(int j = 0; j < n; j++)if((i != j) && E[j][i]){
            E[j] ^= E[i];
            C[j] ^= C[i];
        }
    }
    
    for(int e = 0; e < m; e++){
        if(C[b[e]][a[e]])printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}