#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <unordered_map>
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
const int maxn = 3e5 + 5;
int a[maxn];

unordered_map<int, int> cnt;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    ll b = 0;
    ll x = 0;
    for(int i = 0;i < 30;i++){
        ll opp = 0;
        ll same = 0;
        cnt.clear();
        for(int j = 1;j <= n;j++){
            if(a[j] & 1){
                opp += cnt[a[j] ^ 1];
            }else{
                same += cnt[a[j] ^ 1];
            }
            cnt[a[j]]++;
        }
        for(int j = 1;j <= n;j++){
            a[j] >>= 1;
        }
        if(same <= opp){
            b += same;
        }else{
            b += opp;
            x |= (1 << i);
        }
    }
    cout << b << " " << x << endl;
    return 0;
}