#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

const int maxn = 4e5 + 5;
int n;
int a[maxn];

const int maxm = 1e7 + 5;
int c[maxm];

void add(int p, int d){
    for(int i = p;i < maxm;i += i & -i){
        c[i] += d;
    }
}

int sum(int p){
    if(p < 0)
        return 0;
    int res = 0;
    for(int i = p; i > 0;i -= i & -i){
        res += c[i];
    } 
    return res;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for(int j = 0;j < 30;j++){
        //cout << j << endl;
        int mask = (1 << (j + 1)) - 1;
        int mask1 = (1 << j);
        int s = 0;
        for(int k = 1;k <= n;k++){
            int b = a[k] & mask;
            //cout << b << endl;
            int l = max(0, mask1 - b);
            int r = mask - b;
            l++;
            r++;
            l = min(maxm - 1, l);
            r = min(maxm - 1, r);
            //cout << l << " " << r << endl;
            s += sum(r) - sum(l - 1);
            l = max(0, mask + 1 + mask1 - b);
            r = mask + 1 + mask - b;
            l++;
            r++;
            l = min(maxm - 1, l);
            r = min(maxm - 1, r);
            s += sum(r) - sum(l - 1);
            add(b + 1, 1);
        }
        //cout << j << " " << s << endl;
        if(s & 1){
            ans |= (1 << j);
        }
        for(int k = 1;k <= n;k++){
            int b = a[k] & mask;
            add(b + 1, -1);
        }
    }
    cout << ans << endl;
    return 0;
}