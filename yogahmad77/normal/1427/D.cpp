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
    vector<int> c(n);
    for(int &i : c){
        cin >> i;
        i -= 1;
    }
    vector<vector<int>> ans;
    int x = 1;
    if(n & 1) x = 0;
    int cnt = 0;
    for(int i = n - 1; i >= 0; i--){
        int di;
        for(int j = 0; j < n; j++){
            if(c[j] == i){
                di = j;
            }
        }
        if(x == 0){
            if(di == n - 1 && i == n - 1){
                // skip
            }
            else{
                if(di == n - 1){
                    vector<int> tmp;
                    for(int i = 0; i < cnt; i++) tmp.push_back(1);
                    tmp.push_back(n - cnt);
                    ans.push_back(tmp);
                }
                else{
                    vector<int> tmp;
                    for(int i = 0; i < cnt; i++) tmp.push_back(1);
                    tmp.push_back(di - cnt + 1);
                    tmp.push_back(n - di - 1);
                    ans.push_back(tmp);
                }
            }
        }
        else{
            if(di == 0 && i == n - 1){
                // skip
            }
            else{
                vector<int> tmp;
                if(di > 0) tmp.push_back(di);
                tmp.push_back(n - di - cnt);
                for(int i = 0; i < cnt; i++) tmp.push_back(1);
                ans.push_back(tmp);
            }
        }
        if(!ans.empty()){
            vector<int> baru;
            int l = 0;
            for(int x : ans.back()){
                int r = l + x - 1;
                for(int j = r; j >= l; j--){
                    baru.push_back(c[j]);
                }
                l = r + 1;
            }
            reverse(ALL(baru));
            c = baru;
        }
        
        x ^= 1;
        cnt += 1;
    }
    cout << sz(ans) << '\n';
    for(auto x : ans){
        cout << sz(x);
        for(int i : x) cout << ' ' << i;
        cout << '\n';
    }
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