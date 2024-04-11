#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
#define MAXN 100005
using namespace std;
int n, a[MAXN], t[MAXN], ls[MAXN], rs[MAXN];
long long k, inv;
void add(int *tree, int ind, int v){
    while(ind < MAXN){
        tree[ind] += v;
        ind += ind & -(ind);
    }
}
int sum(int *tree, int ind){
    int ret = 0;
    while(ind > 0){
        ret += tree[ind];
        ind -= ind & -(ind);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        t[i] = a[i];
    }
    sort(t, t + n);
    for(int i = 0; i < n; i++)
        a[i] = lower_bound(t, t + n, a[i]) - t + 1;
    for(int i = 0; i < n; i++){
        inv += i - sum(rs, a[i]);
        add(rs, a[i], 1);
    }
    if(inv <= k){
        long long s = n;
        cout << s * (s - 1) / 2 << endl;
    }else{
        long long ans = 0;
        add(rs, a[0], -1);
        inv -= sum(rs, a[0] - 1);
        for(int L = 0, R = 1; L < (n - 1); L++){
            inv += sum(rs, a[L] - 1) + (L - sum(ls, a[L]));
            add(ls, a[L], 1);
            
            assert(L < R);
            while(R < n && inv > k){
                inv -= ((L + 1) - sum(ls, a[R])) + sum(rs, a[R] - 1);
                add(rs, a[R], -1);
                R++;
            }
            
            ans += n - R;
        }
        cout << ans << endl;
    }
    return 0;
}