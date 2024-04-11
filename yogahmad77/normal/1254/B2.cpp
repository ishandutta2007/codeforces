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
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }
    set<long long> faktor_prima;
    for(int i = 2; i <= 1e6; i++){
        while(sum % i == 0){
            sum /= i;
            faktor_prima.insert(i);
        }
    }
    long long jaw = 1e18;
    if(sum > 1) faktor_prima.insert(sum);
    for(auto x : faktor_prima){
        long long sisa = 0;
        long long tengah = (x + 1) / 2;
        long long di;
        auto b = a;
        for(int i = 0; i < n; i++) b[i] %= x;
        long long tot = 0;
        for(int i = 0; i < n; i++) tot += b[i];
        long long sum = 0;
        vector<pair<int, long long>> ve;
        long long ans = 0;
        // debug(x);
        for(int i = 0; i < n; i++){
            if(sum + b[i] >= x){
                // debug(i);
                long long sisa = b[i] - (x - sum);
                b[i] = sisa;
                ve.pb({i, x - sum});
                long long mid = tengah;
                long long di;
                for(auto j : ve){
                    if(mid <= j.s){
                        di = j.f;
                        break;
                    }
                    mid -= j.s;
                }
                long long kurang = 0, lebih = 0;
                long long cntl = 0, cntr = 0;
                for(auto j : ve){
                    if(j.f < di){
                        kurang += 1LL * j.f * j.s;
                        cntl += j.s;
                    }
                    if(j.f > di){
                        lebih += 1LL * j.f * j.s;
                        cntr += j.s;
                    }
                }
                // debug(di, cntl, kurang, cntr, lebih);
                ve.clear();
                ans += di * cntl - kurang;
                ans += lebih - di * cntr;
                i -= 1;   
                sum = 0;
            }
            else{
                ve.pb({i, b[i]});
                sum += b[i];
            }
        }  
        jaw = min(jaw, ans); 
    }
    if(jaw == 1e18) jaw = -1;
    cout << jaw << endl;
}