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
int n, q;
const int maxn = 2e5 + 5;

ll a[maxn];

vector<int> d;
vector<ll> ans;

vector<ll> sum[maxn];
multiset<ll> s;

int prime[maxn], tot;
bool vis[maxn];

void pre(){
    tot = 0;
    vis[1] = true;
    for(int i = 2;i < maxn;i++){
        for(int j = 2 * i;j < maxn;j += i){
            vis[j] = true;
        }
    }
    for(int i = 2;i < maxn;i++){
        if(!vis[i]){
            prime[++tot] = i;
        }
    }
}

void init(){
    d.clear();
    if(!vis[n]){
        d.push_back(1);
    }
    for(int i = 2;i * i <= n;i++){
        if(n % i == 0){
            if(!vis[i]){
                d.push_back(n / i);
            }
            if(i != n / i){
                if(!vis[n / i]){
                    d.push_back(i);
                }
            }
        }
    }
    for(int i = 0;i < d.size();i++){
        sum[i].resize(d[i]);
        for(int j = 0;j < d[i];j++){
            sum[i][j] = 0;
        }
        for(int j = 1;j <= n;j++){
            sum[i][j % d[i]] += a[j];
        }
        for(int j = 0;j < d[i];j++){
            s.insert(-sum[i][j] * d[i]);
        }
    }
}

void change(int pos, ll val){
    for(int i = 0;i < d.size();i++){
        int cat = pos % d[i];
        auto it = s.find(-sum[i][cat] * d[i]);
        s.erase(it);
        sum[i][cat] -= a[pos];
        sum[i][cat] += val;
        s.insert(-sum[i][cat] * d[i]);
    }
    a[pos] = val;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    pre();
    cin >> T;
    while(T--){
        cin >> n >> q;
        ans.clear();
        s.clear();
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }
        init();
        ans.push_back(-(*s.begin()));
        for(int i = 1;i <= q;i++){
            int p, x;
            cin >> p >> x;
            change(p, x);
            ans.push_back(-(*s.begin()));
        }
        for(int i = 0;i < q + 1;i++){
            cout << ans[i] << endl;
        }
    }
    return 0;
}