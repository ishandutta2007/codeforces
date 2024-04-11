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

int t;

const int maxn = 1e6 + 6;

vector<int> pdiv[maxn];
bool prime[maxn];
int n;
int a[maxn];
int q;
int e[maxn], o[maxn];
int cnt[maxn];

void init(){
    memset(prime, 0, sizeof(prime)); 
    prime[1] = 1;
    for(int i = 2;i <= 1000000;i++){
        if(!prime[i]){
            for(int j = i * 2;j <= 1000000;j += i){
                prime[j] = 1;
                pdiv[j].push_back(i);
            }
            pdiv[i].push_back(i);
        }
    }
    for(int i = 1;i <= 1000000;i++){
        int tmp = i;
        int tmp1 = 1;
        for(auto d : pdiv[i]){
            int cnt = 0;
            while(tmp % d == 0){
                tmp /= d;
                cnt++;
            }
            if(cnt & 1)
                o[i] = 1;
            if(cnt & 1)
                tmp1 *= d;
        }
        e[i] = tmp1;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
            a[i] = e[a[i]];
            cnt[a[i]]++;
        }
        vector<pair<int, int>> num;
        for(int i = 1;i <= n;i++){
            if(cnt[a[i]] == 0)
                continue;
            num.push_back(mp(a[i], cnt[a[i]]));
            cnt[a[i]] = 0;
        }
        int ans = 0;
        for(auto p : num){
            ans = max(ans, p.se);
        }
        int ans1 = 0;
        int sum = 0;
        for(auto p : num){
            if(o[p.fi]){
                if(p.se & 1){
                    ans1 = max(ans, p.se);
                }else{
                    sum += p.se;
                } 
            }else{
                sum += p.se;
            }
        }
        ans1 = max(ans1, sum);
        cin >> q;
        for(int i = 1;i <= q;i++){
            ll w;
            cin >> w;
            if(w == 0){
                cout << ans << endl;
            }else{
                cout << ans1 << endl;
            }
        }
    }
    return 0;
}