#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int f[100][100];
int g[100][100];

void solve_small(int n, int m){

}

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int  j = 0; j < m; j++){
            char c; cin >> c; f[i][j] = c-'0';
        }
    }
    
    vector<vector<P>> ans;
    for(int i = 0; i < n-2; i++){
        for(int j = 0; j < m; j++){
            if(i+1 >= n-1 && j+1 >= m-1) continue;
            if(f[i][j] == 1){
                vector<P> vp;
                vp.push_back(P(i, j));
                f[i][j] = 0;
                if(i+1 < n && j+1 < m){
                    vp.push_back(P(i, j+1));
                    vp.push_back(P(i+1, j+1));
                    f[i][j+1] ^= 1;
                    f[i+1][j+1] ^= 1;
                }else if(i+1 < n){
                    vp.push_back(P(i+1, j-1));
                    vp.push_back(P(i+1, j));
                    f[i+1][j] ^= 1;
                    f[i+1][j-1] ^= 1;
                }else if(j+1 < m){
                    vp.push_back(P(i, j+1));
                    vp.push_back(P(i-1, j+1));
                    f[i][j+1] ^= 1;
                    f[i-1][j+1] ^= 1;
                }
                ans.push_back(vp);
            }
        }
    }
    for(int j = 0; j < m-2; j++){
        vector<P> vp;
        if(f[n-2][j] == 1 && f[n-1][j] == 1){
            vp.push_back(P(n-2, j));
            vp.push_back(P(n-1, j));
            vp.push_back(P(n-2, j+1));
            f[n-2][j+1] ^= 1;
        }else if(f[n-2][j] == 1){
            vp.push_back(P(n-2, j));
            vp.push_back(P(n-1, j+1));
            vp.push_back(P(n-2, j+1));
            f[n-2][j+1] ^= 1;
            f[n-1][j+1] ^= 1;
        }else if(f[n-1][j] == 1){
            vp.push_back(P(n-1, j));
            vp.push_back(P(n-1, j+1));
            vp.push_back(P(n-2, j+1));
            f[n-2][j+1] ^= 1;
            f[n-1][j+1] ^= 1;
        }else{
            continue;
        }
        f[n-2][j] == 0;
        f[n-1][j] == 0;
        ans.push_back(vp);
    }
    {
        int i = n-2, j = m-2;
        vector<int> ngh, ngw;
        for(int k = 0; k < 2; k++){
            for(int l = 0; l < 2; l++){
                if(f[i+k][j+l] == 1){
                    ngh.push_back(i+k);
                    ngw.push_back(j+l);
                }
            }
        }
        if(ngw.size() == 1){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){  
                    if(ngh[0] == i+k && ngw[0] == j+l) continue;
                    vector<P> vp; 
                    for(int p = 0; p < 2; p++){
                        for(int q = 0; q < 2; q++){
                            if(k == p && l == q) continue;
                            vp.push_back(P(i+p, j+q));
                        }
                    }
                    ans.push_back(vp);
                }
            }  
        }else if(ngw.size() == 2){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){  
                    if((ngh[0] == i+k && ngw[0] == j+l) || (ngh[1] == i+k && ngw[1] == j+l)){
                        vector<P> vp; 
                        for(int p = 0; p < 2; p++){
                            for(int q = 0; q < 2; q++){
                                if(k == p && l == q) continue;
                                vp.push_back(P(i+p, j+q));
                            }
                        }
                        ans.push_back(vp);
                    }
                }
            } 
        }else if(ngw.size() == 3){
            vector<P> vp; 
            for(int p = 0; p < 3; p++){
                vp.push_back(P(ngh[p], ngw[p]));
            }
            ans.push_back(vp);
        }else if(ngw.size() == 4){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){  
                    vector<P> vp; 
                    for(int p = 0; p < 2; p++){
                        for(int q = 0; q < 2; q++){
                            if(k == p && l == q) continue;
                            vp.push_back(P(i+p, j+q));
                        }
                    }
                    ans.push_back(vp);
                }
            } 
        }
    }
    cout << ans.size() << endl;
    for(auto v : ans){
        for(P p : v){
            cout << p.first+1 << ' ' << p.second+1 << ' ';
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}