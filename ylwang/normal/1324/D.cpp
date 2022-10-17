#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n , a[N] , b[N] , c1[N] , c2[N] , pos;
long long ans;

int main(){
    scanf("%d" , &n);
    for(int i = 1; i <= n; i++) scanf("%d" , &a[i]);
    for(int i = 1; i <= n; i++) scanf("%d" , &b[i]);
    for(int i = 1; i <= n; i++)
        c1[i] = a[i] - b[i] , c2[i] = -c1[i] , ans -= (c1[i] > c2[i]);
    sort(c1 + 1 , c1 + n + 1);
    sort(c2 + 1 , c2 + n + 1);
    for(int i = 1; i <= n; i++){
        while(c1[i] > c2[pos + 1] && pos < n) pos++;
        ans += pos;
    }
    printf("%lld" , ans / 2);
    return 0;
}