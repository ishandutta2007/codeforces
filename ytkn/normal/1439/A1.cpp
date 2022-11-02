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

void solve(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int  j = 0; j < m; j++){
            char c; cin >> c; f[i][j] = c-'0';
        }
    }
    vector<vector<P>> ans;
    for(int i = 0; i+1 < n; i++){
        for(int  j = 0; j+1 < m; j++){
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
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    f[i+k][j+l] = 0;
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