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
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())

const long long MOD = 1e9 + 7;
const long long mx = 15;

long long k, sum[mx], rata, val[(1 << 15) + 10];
vector<long long> ve[mx], apa[(1 << 15) + 10];
vector<pair<long long, long long>> ans[(1 << 15) + 10];
map<long long, long long> di;



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    for(long long i = 0; i < k; i++){
        long long x, y;
        cin >> x;
        while(x--){
            cin >> y;
            ve[i].pb(y);
            di[y] = i;
            sum[i] += y;
        }
        sort(ALL(ve[i]));
    }
    long long tot = 0;
    for(long long i = 0; i < k; i++) tot += sum[i];
    if(tot % k != 0){
        cout << "No\n";
        return 0;
    }
    rata = tot / k;
    for(long long i = 0; i < k; i++){
        for(long long j : ve[i]){
            long long butuh = rata - (sum[i] - j);
            long long ya = 1;
            set<long long> udah;
            vector<pair<long long, long long>> isi;
            udah.insert(i);
            isi.pb({i, j});
            while(1){
                if(!di.count(butuh)){
                    ya = 0;
                    break;
                }
                long long x = di[butuh];
                if(x == i && butuh != j){
                    ya = 0;
                    break;
                }
                if(x == i) break;
                if(udah.count(x)){
                    ya = 0;
                    break;
                }
                udah.insert(x);
                isi.pb({x, butuh});
                butuh = rata - (sum[x] - butuh);
            }
            if(!ya) continue;
            long long mask = 0;
            // debug(k);
            for(auto j : isi){
                mask |= 1 << j.f;
                // debug(j.f, j.s);
            }
            if(val[mask] == 1) continue;
            val[mask] = 1;
            ans[mask] = isi;
            apa[mask].pb(mask);
        }
    }
    val[0] = 1;
    for(long long i = 0; i < 1 << k; i++){
        if(val[i]) continue;
        for(long long j = i; j > 0; j = i & (j - 1)){
            if(j == i) continue;
            long long x = i ^ j;
            if(val[x] && val[j]){
                val[i] = 1;
                for(long long a : apa[j]) apa[i].pb(a);
                for(long long a : apa[x]) apa[i].pb(a);
                break;
            }
        }
    }
    if(val[(1 << k) - 1] == 0) cout << "No\n";
    else{
        cout << "Yes\n";
        vector<pair<int, int>> jaw(k);
        for(long long i : apa[(1 << k) - 1]){
            // debug(i);
            for(long long j = 0; j < sz(ans[i]); j++){
                long long x = (j + 1) % sz(ans[i]);
                // debug(ans[i][j].f, ans[i][j].s);
                jaw[ans[i][x].f] =  {ans[i][x].s, ans[i][j].f + 1};
                // cout << ans[i][x].s << ' ' << ans[i][j].f + 1<< '\n';
            }
        }
        for(auto i : jaw) cout << i.f << ' ' << i.s << endl;
    }
}