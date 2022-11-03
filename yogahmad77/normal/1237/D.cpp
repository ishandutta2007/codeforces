#include "bits/stdc++.h"
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())
#define MOD 1000000007 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n * 4), ans(n * 4);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        a[i + n] = a[i];
    n *= 2;
    for(int i = 0; i < n; i++)
        a[i + n] = a[i];
    set<int> ini;
    vector<int> ve(n * 2);
    iota(ALL(ve), 0);
    sort(ALL(ve), [&](int x, int y){
        return a[x] < a[y];
    });
    int now = -1;
    if(a[ve[0]] * 2 >= a[ve.back()]){
        for(int i = 0; i < n / 2; i++)
            cout << -1 << ' ';
        return 0;
    }
    for(int i : ve){
        if(i >= n)
            continue;
        while(now + 1 < sz(ve) && a[ve[now + 1]] * 2 < a[i]){
            now += 1;
            ini.insert(ve[now]);
        }
        auto it = ini.upper_bound(i);
        if(it == ini.end())
            ans[i] = n;
        else{
            ans[i] = *it - i;
        }
    }
    int cnt = 0;
    while(1){
        cnt += 1;
        // debug(cnt);
        int ubah = 0;
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1){
                if(ans[0] + 1 < ans[i]){
                    ubah = 1;
                    ans[i] = ans[0] + 1;
                }
            }
            else{
                if(ans[i + 1] + 1 < ans[i]){
                    ubah = 1;
                    ans[i] = ans[i + 1] + 1;
                }
            }
        }
        if(!ubah)
            break;
    }
    for(int i = 0; i < n / 2; i++)
        cout << ans[i] << ' ';
}