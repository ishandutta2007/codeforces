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
int n;

const int maxn = 2e5 + 5;
char s[maxn], t[maxn];
const ll INF = 1e18;

set<int> ch[30];

bool vis[maxn];

int c[maxn];

void add(int p, int x){
    for(int i = p;i < maxn;i += i & -i){
        c[i] += x;
    }
}

int sum(int p){
    int ans = 0;
    for(int i = p;i > 0;i -= i & -i){
        ans += c[i];
    }
    return ans;
}

int main(){
    cin >> T;
    while(T--){
        scanf("%d", &n);
        scanf("%s", s + 1);
        scanf("%s", t + 1);
        for(int i = 0;i < 26;i++){
            ch[i].clear();
        }
        for(int i = 1;i <= n;i++){
            ch[s[i] - 'a'].insert(i);
            vis[i] = false;
            c[i] = 0;
        }
        ll ans = INF;
        int j = 1;
        ll op = 0;
        for(int i = 1;i <= n;i++){
            while(vis[j]){
                j++;
            }
            if(s[j] < t[i]){
                ans = min(ans, op);
                break;
            }
            else{
                auto it = ch[t[i] - 'a'].lower_bound(j);
                for(int k = 0;k < t[i] - 'a';k++){
                    auto it1 = ch[k].upper_bound(j);
                    if(it1 != ch[k].end()){
                        int r = (*it1);
                        ans = min(ans, op + r - j - sum(r) + sum(j));
                    }
                }
                if(it != ch[t[i] - 'a'].end()){
                    int r = (*it);
                    op += r - j - sum(r) + sum(j);
                    ch[t[i] - 'a'].erase(it);
                    vis[r] = true;
                    add(r, 1);
                }else{
                    break;
                }
            }
        } 
        if(ans == INF){
            ans = -1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}