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
#include <cstring>
#include <sstream>
#include <numeric>
using namespace std;
int n, a[100005];
long long k;
int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    long long sum = accumulate(a, a + n, 0LL);
    if(sum < k)cout << -1 << endl;
    else{
        long long L = 0, R = *max_element(a, a + n);
        while(L < R){
            long long mid = (L + R + 1) / 2, cur = 0;
            for(int i = 0; i < n; i++)
                cur += min(mid, (long long)a[i]);

            if(cur > k)R = mid - 1;
            else L = mid;
        }
        long long cur = k;
        for(int i = 0; i < n; i++)
            cur -= min((long long)a[i], L);
        queue < pair <int, int> > q;
        for(int i = 0; i < n; i++)
            if(a[i] - L > 0)q.push(make_pair(i, a[i] - L));

        while(cur--){
            pair <int, int> p = q.front();
            q.pop();

            if(p.second - 1 > 0)q.push(make_pair(p.first, p.second - 1));
        }
        while(!q.empty()){
            pair <int, int> p = q.front();
            q.pop();

            cout << p.first + 1 << ' ';
        }
        cout << endl;

    }
    return 0;
}