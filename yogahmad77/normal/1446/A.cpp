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




const int mx = 1e5 + 10;


void solve(int tc){
    int n;
    long long w;
    cin >> n >> w;
    vector<long long> a(n);
    for(auto &i : a) cin >> i;
    vector<int> ans;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > w) continue;
        if(a[i] + a[i] >= w){
            cout << 1 << '\n' << i + 1 << '\n';
            return;
        }
        else if(sum + sum < w){
            sum += a[i];
            ans.push_back(i + 1);
        }
    }
    if(sum + sum >= w){
        cout << sz(ans) << '\n';
        for(auto x : ans) cout << x << ' ';
        cout << '\n';
        return;
    }
    cout << -1 << '\n';
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