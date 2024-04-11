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
int n, tree[MAXN], ind[MAXN];
vector < pair <long long, int> > v;
long long k, a[MAXN];
void add(int i, int val){
    i++;
    while(i < MAXN){
        tree[i] += val;
        i += i & (-i);
    }
}
int sum(int i){
    i++;
    
    int ret = 0;
    while(i > 0){
        ret += tree[i];
        i -= i & (-i);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for(int i = 0; i <= n; i++)v.push_back(make_pair(a[i], i));
    sort(v.begin(), v.end());
    
    for(int i = 0; i <= n; i++)
        ind[v[i].second] = i;
    
    long long L = -1LL << 60, R = 1LL << 60;
    while(L < R){
        long long mid = (L + R + 1) / 2;
        
        memset(tree, 0, sizeof tree);
        add(ind[0], 1);
        
        long long cnt = 0;
        for(int en = 1; en <= n; en++){
            //a[en] - a[st] >= mid
            //-a[st] >= mid - a[en]
            //a[st] <= a[en] - mid
            int Left = 0, Right = n;
            while(Left < Right){
                int m = (Left + Right + 1) / 2;
                if(v[m].first <= a[en] - mid)Left = m;
                else Right = m - 1;
            }
            
            if(v[Left].first <= a[en] - mid)cnt += sum(Left);
            add(ind[en], 1);
        }

        if(cnt >= k)L = mid;
        else R = mid - 1;
    }
    cout << L << endl;
    return 0;
}