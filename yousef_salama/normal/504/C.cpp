#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, st, a[MAXN], freq[MAXN];

long long r;
void calc(){
    int L = 0, R = n - 2 * st - 1;
    while(L < R){
        int mid = (L + R) / 2;
        
        bool ok = true;
        for(int i = (n - st - 1) - mid; i > (n - 1) / 2; i--)
            if(a[i] != a[n - i - 1])ok = false;
            
        memset(freq, 0, sizeof freq);
        for(int i = st; i < st + mid; i++)freq[a[i]]++;
        for(int i = (n - st - 1); i >= st + mid && i > (n - st - 1) - mid; i--)freq[a[i]]--;
        
        for(int i = 0; i < n; i++)if(freq[i] < 0)ok = false;
        
        if(ok)R = mid;
        else L = mid + 1;
    }
    r += 1LL * (st + 1) * (n - 2 * st - L);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i]--;
    }
    
    for(int i = 0; i < n; i++)freq[a[i]]++;
    
    int odd = 0;
    for(int i = 0; i < n; i++)
        if(freq[i] % 2 != 0)odd++;
        
    if((odd >= 2) || (odd == 1 && (n % 2) == 0)){
        printf("0\n");
        return 0;
    }
    
    bool ok = true;
    for(int i = 0; i < n; i++)
        if(a[i] != a[n - i - 1])ok = false;
        
    if(ok){
        printf("%I64d\n", 1LL * n * (n + 1) / 2);
        return 0;
    }
    
    st = 0;
    while(st < n / 2){
        if(a[st] == a[n - st - 1])st++;
        else break;
    }
    
    r = 1LL * (st + 1) * (st + 1);
    calc();
    
    reverse(a, a + n);
    calc();
    
    printf("%I64d\n", r);
    
    return 0;
}