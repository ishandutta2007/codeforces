#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
using namespace std;

int n, m;
const int maxn = 1e5 + 5;
const int maxm = 45;
int type[maxn];
string s[maxn];
map<string, int> mp;
long long nei[maxm];
const int maxs = (1 << 20) + 5;
int ans[maxs];
map<long long, int> a;
int solve(long long mask){
    if(mask < maxs && ans[mask] != -1)
        return ans[mask];
    if(mask == 0)
        return ans[mask] = 0;
    long long highbit = (1LL << 39);
    for(int i = 39;i >= 0;i--){
        if(mask & highbit)
            break;
        highbit >>= 1;
    }
    int tmp1 = solve(mask ^ highbit);
    int tmp2 = solve(mask & nei[a[highbit]]) + 1;
    if(mask < maxs){
        ans[mask] = max(tmp1, tmp2);
    }
    return max(tmp1, tmp2);
}
bool vis[45];
int main(){
    memset(ans, -1, sizeof(ans));
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int cnt = 0;
    long long p2 = 1;
    for(int j = 0;j <= 40;j++){
        a[p2] = j;
        p2 <<= 1;
    }
    for(int i = 1;i <= n;i++){
        cin >> type[i];
        if(type[i] == 2){
            cin >> s[i];
            if(mp.count(s[i]) == 0){
                mp[s[i]] = cnt++;
            }
        }
    } 
    memset(nei, 0, sizeof(nei));
    for(int i = 1;i <= n;){
        if(type[i] == 1){
            memset(vis, 0, sizeof(vis));
            i++;
            continue;
        }else{
            int j = i;
            while(j < n && type[j + 1] == 2)
                j++;
            for(int k = i;k <= j;k++){
                vis[mp[s[k]]] = 1;
            }
            long long st = 0;
            for(int l = 0;l < 40;l++){
                if(vis[l])
                    st |= (1LL << l);
            }
            for(int l = 0;l < 40;l++){
                if(vis[l]){
                    nei[l] |= (st ^ (1LL << l));
                }
            }
            i = j + 1;
        }
    } 
    for(int i = 0;i < m;i++){
        nei[i] = ((1LL << m) - 1) ^ nei[i] ^ (1LL << i);
    }
    solve((1LL << (m / 2)) - 1);
    cout << solve((1LL << m) - 1) << endl; 
    return 0;
}