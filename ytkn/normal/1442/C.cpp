#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

const ll INF = 1e+15;

typedef pair<int, int> Pii;
typedef pair<ll, int> Pli;
typedef pair<ll, Pii> P;
typedef pair<Pli, Pii> PP;
typedef pair<Pii, Pii> PPi;

const ll MOD = 998244353;

class ModInt{
    public:
    ll v;
    ModInt(ll _v = 0){
        v = _v;
    }
    ModInt operator+(ll n){
        return ModInt((v+n)%MOD);
    }
    ModInt operator-(ll n){
        return ModInt((v-n+MOD)%MOD);
    }
    ModInt operator*(ll n){
        return ModInt((v*n)%MOD);
    }
    ModInt operator/(ll n){
        return ModInt((ModInt(n).inv()*v).v%MOD);
    }

    void operator+=(ll n){
        v = (v+n)%MOD;
    }
    void operator-=(ll n){
        v = (v-n+MOD)%MOD;
    }
    void operator*=(ll n){
        v = (v*n)%MOD;
    }
    
    
    ModInt operator+(ModInt n){
        return ModInt((v+n.v)%MOD);
    }
    ModInt operator-(ModInt n){
        return ModInt((v-n.v+MOD)%MOD);
    }
    ModInt operator*(ModInt n){
        return ModInt((v*n.v)%MOD);
    }
    ModInt operator/(ModInt n){
        return ModInt((n.inv()*v).v%MOD);
    }

    void operator+=(ModInt n){
        v = (v+n.v)%MOD;
    }
    void operator-=(ModInt n){
        v = (v-n.v+MOD)%MOD;
    }
    void operator*=(ModInt n){
        v = (v*n.v)%MOD;
    }

    void operator=(ModInt n){
        v = n.v;
    }
    void operator=(ll n){
        v = n;
    }

    ModInt inv(){
        if(v == 1) return ModInt(1);
        else return ModInt(MOD-ModInt(MOD%v).inv().v*(MOD/v)%MOD);
    }
};

ostream& operator<<(ostream& os, const ModInt& m){
    os << m.v;
    return os;
}

istream & operator >> (istream &in,  ModInt &m){
    in >> m.v;
    return in;
}

ModInt pow(ModInt a, ll n) {
	ModInt ans = 1;
	ModInt tmp = a;
	for (int i = 0; i <= 60; i++) {
		ll m = (ll)1 << i;
		if (m & n) {
		ans *= tmp;
		}
		tmp *= tmp;
	}
	return ans;
}

int n, m;
int u[200000], v[200000];
vector<int> G[200000];
vector<int> G_inv[200000];
ll dist_trans[200000][2];



void calc_dist_trans(){
    priority_queue<P, vector<P>, greater<P>> que;
    for(int i = 0; i < n; i++){
        dist_trans[i][0] = INF;
        dist_trans[i][1] = INF;
    }
    dist_trans[0][0] = 0;
    que.push(P(0, Pii(0, 0)));
    while(!que.empty()){
        P p = que.top();que.pop();
        int v = p.second.first;
        int s = p.second.second;
        int d = p.first;
        if(dist_trans[v][s] < d) continue;
        if(s == 0){
            if(dist_trans[v][1] > d+1){
                dist_trans[v][1] = d+1;
                que.push(P(d+1, Pii(v, 1)));
            }
            for(int to: G[v]){
                if(dist_trans[to][0] > d){
                    dist_trans[to][0] = d;
                    que.push(P(d, Pii(to, 0)));
                }
            }
        }else{
            if(dist_trans[v][0] > d+1){
                dist_trans[v][0] = d+1;
                que.push(P(d+1, Pii(v, 0)));
            }
            for(int to: G_inv[v]){
                if(dist_trans[to][1] > d){
                    dist_trans[to][1] = d;
                    que.push(P(d, Pii(to, 1)));
                }
            }
        }
    }
}

void input(){
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
        G[u[i]].push_back(v[i]);
        G_inv[v[i]].push_back(u[i]);
    }
}


ll dist_small[200000][21][2];
void solve_small(){
    priority_queue<PP, vector<PP>, greater<PP>> que;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= 20; j++){
            dist_small[i][j][0] = INF;
            dist_small[i][j][1] = INF;
        }
    }
    dist_small[0][0][0] = 0;
    que.push(PP(Pli(0, 0), Pii(0, 0)));
    while(!que.empty()){
        PP p = que.top();que.pop();
        ll d = p.first.first;
        int v = p.first.second;
        int cnt = p.second.first;
        int s = p.second.second;
        // cout << v << ' ' << cnt << ' ' << d << endl;
        if(dist_small[v][cnt][s] < d) continue;
        if(s == 0){
            if(cnt+1 <= 20 && dist_small[v][cnt+1][1] > d+(1<<cnt)){
                dist_small[v][cnt+1][1] = d+(1<<cnt);
                que.push(PP(Pli(d+(1<<cnt), v), Pii(cnt+1, 1)));
            }
            for(int to: G[v]){
                if(dist_small[to][cnt][s] > d+1){
                    dist_small[to][cnt][s] = d+1;
                    que.push(PP(Pli(d+1, to), Pii(cnt, s)));
                }
            }
        }else{
            if(cnt+1 <= 20 && dist_small[v][cnt+1][0] > d+(1<<cnt)){
                dist_small[v][cnt+1][0] = d+(1<<cnt);
                que.push(PP(Pli(d+(1<<cnt), v), Pii(cnt+1, 0)));
            }
            for(int to: G_inv[v]){
                if(dist_small[to][cnt][s] > d+1){
                    dist_small[to][cnt][s] = d+1;
                    que.push(PP(Pli(d+1, to), Pii(cnt, s)));
                }
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i <= 20; i++){
        ans = min(ans, dist_small[n-1][i][0]);
        ans = min(ans, dist_small[n-1][i][1]);
    }
    cout << ans%MOD << endl;
}

ll dist_large[200000][2];
void solve_large(){
    priority_queue<PPi, vector<PPi>, greater<PPi>> que;
    for(int i = 0; i < n; i++){
        dist_large[i][0] = INF;
        dist_large[i][1] = INF;
    }
    dist_large[0][0] = 0;
    que.push(PPi(Pii(0, 0), Pii(0, 0)));
    while(!que.empty()){
        PPi p = que.top();que.pop();
        int cnt = p.first.first;
        int d = p.first.second;
        int v = p.second.first;
        int s = p.second.second;
        // cout << v << ' ' << s << ' ' << d  << endl;
        if(dist_large[v][s] < d) continue;
        if(s == 0){
            if(cnt+1 == dist_trans[v][1] && dist_large[v][1] > d){
                dist_large[v][1] = d;
                que.push(PPi(Pii(cnt+1, d), Pii(v, 1)));
            }
            for(int to: G[v]){
                if(cnt == dist_trans[to][s] && dist_large[to][s] > d+1){
                    dist_large[to][s] = d+1;
                    que.push(PP(Pii(cnt, d+1), Pii(to, s)));
                }
            }
        }else{
            if(cnt+1 == dist_trans[v][0] && dist_large[v][0] > d){
                dist_large[v][0] = d;
                que.push(PPi(Pii(cnt+1, d), Pii(v, 0)));
            }
            for(int to: G_inv[v]){
                if(cnt == dist_trans[to][s] && dist_large[to][s] > d+1){
                    dist_large[to][s] = d+1;
                    que.push(PP(Pii(cnt, d+1), Pii(to, s)));
                }
            }
        }
    }

    if(dist_trans[n-1][0] < dist_trans[n-1][1]){
        int d = dist_trans[n-1][0];
        cout << pow(2, d) -1 + dist_large[n-1][0] << endl;
    }else if(dist_trans[n-1][0] > dist_trans[n-1][1]){
        int d = dist_trans[n-1][1];
        cout << pow(2, d) -1 + dist_large[n-1][1] << endl;
    }else{
        int d = dist_trans[n-1][0];
        int dst = min(dist_large[n-1][0], dist_large[n-1][1]);
        cout << pow(2, d) -1 + dst << endl; 
    }
}

void solve(){
    calc_dist_trans();
    // cout << dist_trans[n-1][0] << ' ' << dist_trans[n-1][1] << endl;
    if(dist_trans[n-1][0] <= 20 || dist_trans[n-1][1] <= 20){
    // if(true){
        solve_small();
    }else{
        solve_large();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    input();
    solve();
}