#include <bits/stdc++.h>
using namespace std;

int t, n;
bool isprime(int m){
    if(m == 1)return false;
    for(int j = 2; j * j <= m; j++)
        if(m % j == 0)return false;
    return true;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

        int L = n, R = n + 1;
        while(!isprime(L))L--;
        while(!isprime(R))R++;

        pair <long long, long long> p = {1LL * L * (R - 2) - 2 * ((R - 1) - n), 2LL * L * R};

        long long g = __gcd(p.first, p.second);
        p = {p.first / g, p.second / g};

        printf("%I64d/%I64d\n", p.first, p.second);
    }
    return 0;
}