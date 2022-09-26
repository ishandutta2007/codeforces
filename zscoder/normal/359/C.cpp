#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long li;

const li MOD = 1000000007;

li bpow(li x, li v) 
{   
    if (v == 0)
        return 1 % MOD;

    if (v % 2 == 1)
        return (x * bpow(x, v - 1)) % MOD;

    li r = bpow(x, v / 2);

    return (r * r) % MOD;   
}

int main()
 {
    int n, x;
    cin >> n >> x;
    vector < li > a(n), b;
    li sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];    
    }
    for(int i = 0; i < n; i++)
        b.push_back(sum - a[i]);
    sort(b.rbegin(), b.rend());
                 

    while (true) {
        li v = b[b.size() - 1];
    
        int cnt = 0;
        while (b.size() > 0 && b[b.size() - 1] == v) {
            cnt ++;
            b.pop_back();
        }
        
        if (cnt % x != 0) {
                        v = min(v, sum);
            cout << bpow(x, v) << endl;
            return 0;
        }
        else {
            cnt /= x;
            for(int i = 0; i < cnt; i++) 
                b.push_back(v + 1);
        }   
    }
    return 0;
}