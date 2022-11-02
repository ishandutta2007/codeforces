#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T;
int n, m;
const int maxn = 3e5 + 5;
int p[maxn];
int pos[maxn];
int cnt[maxn];
int fa[maxn];
vector<int> ans;

int Find(int x){
    return x == fa[x] ? x : fa[x] = Find(fa[x]);
}

bool check(int v){
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        fa[i] = i;
        pos[p[i]] = i;
    }
    for(int i = 1;i <= n;i++){
        int to = (i + v - 1) % n + 1;
        int fx = Find(to);
        int fy = Find(pos[i]);
        if(fx != fy){
            fa[fx] = fy;
            cnt++;
        }
    }
    return cnt <= m;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
       cin >> n >> m; 
       for(int i = 0;i < n;i++){
           cnt[i] = 0;
       }
       for(int i = 1;i <= n;i++){
           cin >> p[i];
           int shift = (i - p[i]) % n;
           if(shift < 0){
               shift = (n + shift % n) % n;
           }
           cnt[shift]++;
       }
       ans.clear();
       for(int i = 0;i < n;i++){
           if(cnt[i] + 2 * m >= n){
               if(check(i))
                   ans.push_back(i);
           }
       }
       cout << ans.size();
       for(int i = 0;i < ans.size();i++){
           cout << " " << ans[i];
       }
       cout << endl;
    }
    return 0;
}