#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, k, x;
long long a[MAXN], pref[MAXN], suff[MAXN];

int main(){
    scanf("%d %d %d", &n, &k, &x);
    for(int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
        
    for(int i = 0; i < n; i++){
        if(i == 0)pref[i] = a[i];
        else pref[i] = a[i] | pref[i - 1];
    }
    for(int i = n - 1; i >= 0; i--){
        if(i == n - 1)suff[i] = a[i];
        else suff[i] = a[i] | suff[i + 1];
    }
    
    long long r = 0;
    for(int i = 0; i < n; i++){
        long long ai = a[i];
        for(int j = 0; j < k; j++)ai *= x;
        
        r = max(r, (i > 0 ? pref[i - 1] : 0) | ai | (i + 1 < n ? suff[i + 1] : 0));
    }
    printf("%I64d\n", r);
    
    return 0;
}