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
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string ss;
        cin >> ss;
        int n = sz(ss);
        vector<int> ans, hapus(n, 0);
        for(int i = 0; i < n - 2; i++){
            int ya = 1;
            string aa = "twone";
            if(i >= n - 4) ya = 0;
            for(int j = 0; j < 5 && i < n - 4; j++){
                if(ss[i + j] != aa[j])
                    ya = 0;
            }
            if(ya){
                hapus[i + 2] = 1;
                ans.push_back(i + 2);
                i += 4;
                continue;
            }
            ya = 1;
            aa = "two";
            for(int j = 0; j < 3; j++){
                if(ss[i + j] != aa[j])
                    ya = 0;
            }
            if(ya){
                hapus[i + 1] = 1;
                ans.push_back(i + 1);
                i += 2;
                continue;
            }
            ya = 1;
            aa = "one";
            for(int j = 0; j < 3; j++){
                if(ss[i + j] != aa[j])
                    ya = 0;
            }
            if(ya){
                hapus[i + 1] = 1;
                ans.push_back(i + 1);
                i += 2;
                continue;
            }
        }
        cout << sz(ans) << '\n';
        for(int i : ans) cout << i + 1 << ' ';
        cout << '\n';
    }
}