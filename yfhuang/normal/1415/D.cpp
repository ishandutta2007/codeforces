#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n;
const int maxn = 1e5 + 5;
int a[maxn];
int b[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        b[i] = 31 - __builtin_clz(a[i]);
    }
    for(int i = 1;i + 2 <= n;i++){
        if(b[i] == b[i + 1] and b[i + 1] == b[i + 2]){
            cout << 1 << endl;
            return 0;
        }
    }
    bool flag = false;
    int ans = 1e9;
    for(int l = 1;l <= n;l++){
        int x1 = 0;
        for(int r = l;r <= n;r++){
            x1 ^= a[r];
            int x2 = 0;
            for(int m = l;m < r;m++){
                x2 ^= a[m];
                if(x2 > (x1 ^ x2)){
                    flag = true;
                    ans = min(ans, r - l - 1);
                }
            }
        } 
    }
    if(!flag){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}