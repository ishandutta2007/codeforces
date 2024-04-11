#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct interval{
    int L, R;
    long long value;

    interval(int L, int R, long long value): L(L), R(R), value(value){}
    bool operator <(const interval& y) const{
        return L < y.L;
    }
};

struct yasser{
    set <interval> s;
    long long total, sign, add;

    yasser(){
        total = 0;
        sign = 1;
        add = 0;
    }

    long long calc(const interval& y){
        return (y.value * sign + MOD + add) % MOD * (y.R - y.L + 1) % MOD;
    }

    void insert(int x){
        if(s.empty()){
            s.insert(interval(1, x, 1));
            total = x % MOD;
            return;
        }

        long long prv = total;

        while(!s.empty() && prev(s.end())->L > x){
            total = (total - calc(*prev(s.end())) + MOD) % MOD;
            s.erase(prev(s.end()));
        }
        if(!s.empty() && prev(s.end())->R > x){
            interval c = *prev(s.end());
            total = (total - calc(c) + MOD) % MOD;
            interval d = interval(c.L, x, c.value);
            total = (total + calc(d)) % MOD;

            s.erase(prev(s.end()));
            s.insert(d);
        }
        
        int last = prev(s.end())->R + 1;
        if(last <= x){
            s.insert(interval(last, x, (MOD - sign) * add % MOD));
        }

        long long cnt = prev(s.end())->R;
        sign = -sign;
        add = (prv - add + MOD) % MOD;
        total = (prv * cnt - total + MOD) % MOD;

    }
};

int main(){
    int n;
    scanf("%d", &n);

    vector <int> a(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    yasser y;
    for(int i = 0; i < n; i++)
        y.insert(a[i]);

    printf("%lld\n", y.total);

    return 0;
}