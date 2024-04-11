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
    vector<int> a(n);
    for(int &i : a) cin >> i;
    int sum = 0;
    for(int i : a) sum += i;
    if(sum == 0){
        cout << "NO\n";
        return;
    }
    sort(ALL(a));
    if(sum > 0) reverse(ALL(a));
    cout << "YES\n";
    for(int i : a) cout << i << ' ';
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