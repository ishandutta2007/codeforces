#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
typedef int (*func)(int, int);


const int MOD = 1e9 + 7;

int add(int x, int y){
    int ret = x + y;
    if(ret >= MOD) ret -= MOD;
    return ret;
}
int sub(int x, int y){
    int ret = x - y;
    if(ret < 0) ret += MOD;
    return ret;
}
int mul(int x, int y){
    return (long long)x * y % MOD;
}


const int mx = 1e5 + 10;

int count(vector<int> &cnt){
    int mini = 0;
    while(cnt[mini] > 0) mini += 1;
    return mini;
}

int ya(vector<int> &a){
    for(int i = 0; i < sz(a); i++) if(a[i] != i) return 0;
    return 1;
}

void solve(int tc){
    int n;
    cin >> n;
    vector<int> a(n), ans, cnt(n + 1, 0);
    for(int &i : a) cin >> i;
    for(int i : a) cnt[i] += 1;
    while(!ya(a)){
        int mex = count(cnt);
        if(mex == n){
            int mini = n;
            for(int i = 0; i < n; i++){
                if(a[i] != i){
                    mini = min(mini, a[i]);
                }
            }
            for(int i = 0; i < n; i++){
                if(a[i] == mini){
                    cnt[a[i]] -= 1;
                    a[i] = mex;
                    cnt[a[i]] += 1;
                    ans.push_back(i + 1);
                    break;
                }
            }
            continue;
        }
        cnt[a[mex]] -= 1;
        a[mex] = mex;
        cnt[a[mex]] += 1;
        ans.push_back(mex + 1);
    }
    assert(sz(ans) <= n * 2);
    cout << sz(ans) << '\n';
    for(int i : ans) cout << i << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int tc = 0;
    while(t--){
        solve(++tc);
    }
}