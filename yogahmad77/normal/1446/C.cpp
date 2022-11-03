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
    int ans = n - 2;
    sort(ALL(a));
    map<int, int> cnt[31];
    for(int i = 0; i <= 30; i++){
        for(int x : a){
            int sisa = x % (1 << i);
            int kiri = x - sisa;
            cnt[i][kiri] += 1;
        }
    }
    for(int x : a){
        int hit = 1;
        for(int i = 0; i <= 30; i++){
            int sisa = x % (1 << i);
            int kiri = x - sisa;
            kiri ^= (1 << i);
            if(cnt[i][kiri] > 0){
                hit += 1;
            }
        }
        ans = min(ans, n - hit);
    }
    cout << ans << '\n';

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    int tc = 0;
    while(t--){
        solve(++tc);
    }
}