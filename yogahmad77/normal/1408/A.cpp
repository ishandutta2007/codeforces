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
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    for(int &i : c) cin >> i;
    vector<int> d(n);
    d[0] = a[0];
    for(int i = 1; i < n - 1; i++){
        if(d[i - 1] != a[i]) d[i] = a[i];
        else if(d[i - 1] != b[i]) d[i] = b[i];
        else if(d[i - 1] != c[i]) d[i] = c[i];
        else assert(false);
    }
    if(a[n - 1] != d[0] && a[n - 1] != d[n - 2]) d[n - 1] = a[n - 1];
    else if(b[n - 1] != d[0] && b[n - 1] != d[n - 2]) d[n - 1] = b[n - 1];
    else if(c[n - 1] != d[0] && c[n - 1] != d[n - 2]) d[n - 1] = c[n - 1];
    for(int i : d) cout << i << ' ' ;
    cout << '\n';
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