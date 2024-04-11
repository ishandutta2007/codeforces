#include <iostream>
#include <algorithm>
#include <vector>

using  namespace std;

int a[12][2000];
int f[12][12];

typedef pair<int, int> P;

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        vector<P> p;
        for(int j = 0; j < n; j++){
            int m_ = 0;
            for(int k = 0; k < m; k++){
                cin >> a[j][k];
            }
        }
        for(int j = 0; j < m; j++){
            int m_ = 0;
            for(int k = 0; k < n; k++){
                m_ = max(m_, a[k][j]);
            }
            p.push_back(P(m_, j));
        }
        sort(p.begin(), p.end(), greater<P>());
        vector<int> idx;
        int n_ = min(m, n);
        for(int j = 0; j < n_; j++){
            idx.push_back(p[j].second);
            //cout << p[j].second << ' ' << p[j].first << endl;
        }
        int bt = 1;
        for(int j = 0; j < n_; j++) bt*=n;
        int ans = 0;
        for(int j = 0; j < bt; j++){
            int j_ = j;
            for(int k = 0; k < n_; k++){
                int mv = j_%n;
                j_ -= (j_%n);
                j_ /= n;
                for(int l = 0; l < n; l++){
                    f[k][l] = a[(l+mv)%n][idx[k]];
                    //cout << f[k][l] << ' ';
                }
                //cout << endl;
            }
            int tmp = 0;
            for(int k = 0; k < n; k++){
                int mr = 0;
                for(int l = 0; l < n_; l++){
                    mr = max(mr, f[l][k]);
                }
                tmp += mr;
            }
            ans = max(ans, tmp);
        }
        cout << ans << endl;
    }
}