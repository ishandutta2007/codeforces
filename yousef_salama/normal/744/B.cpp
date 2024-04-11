#include <bits/stdc++.h>
using namespace std;

int n, ri, res[1005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)res[i] = 1 << 30;
    
    for(int k = 0; (1 << k) <= n; k++){
        vector <int> v, w;
        for(int i = 1; i <= n; i++){
            if(i & (1 << k))v.push_back(i);
            else w.push_back(i);
        }
        
        printf("%d\n", v.size());
        fflush(stdout);
        
        for(int j = 0; j < v.size(); j++){
            if(j > 0)printf(" ");
            printf("%d", v[j]);
        }
        printf("\n");
        fflush(stdout);
        
        for(int i = 0; i < n; i++){
            scanf("%d", &ri);
            if(!((i + 1) & (1 << k)))res[i] = min(res[i], ri);
        }
        
        printf("%d\n", w.size());
        fflush(stdout);
        
        for(int j = 0; j < w.size(); j++){
            if(j > 0)printf(" ");
            printf("%d", w[j]);
        }
        printf("\n");
        fflush(stdout);
        
        for(int i = 0; i < n; i++){
            scanf("%d", &ri);
            if((i + 1) & (1 << k))res[i] = min(res[i], ri);
        }
    }
    
    printf("-1\n");
    fflush(stdout);
    
    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
    fflush(stdout);
    
    return 0;
}