#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int> > a(n);
    for (int i=0;i<n;++i) {
        int c;
        scanf("%d", &c);
        a[i].resize(c);
        for (int &j:a[i]) scanf("%d", &j);
        for (int &j:a[i]) --j;
    }
    
    vector<bool> allowed(k, true);
    vector<int> nxt(k, -1);
    vector<int> prv(k, -1);

    for (int i=0;i<n;++i) {
        for (int j=1;j<a[i].size();++j) {
            if (allowed[a[i][j-1]]) {
                if (nxt[a[i][j-1]] == -1) {
                    nxt[a[i][j-1]] = a[i][j];
                } else{
                    if (nxt[a[i][j-1]] != a[i][j]) {
                        for (int t: a[i]) allowed[t] = false;
                        break;
                    }
                }
            }
            if (allowed[a[i][j]]) {
                if (prv[a[i][j]] == -1) {
                    prv[a[i][j]] = a[i][j-1];
                } else {
                    if (prv[a[i][j]] != a[i][j-1]) {
                        for (int t: a[i]) allowed[t] = false;
                        break;
                    }
                }
            }
        }
    }

    for (int i=0;i<n;++i) {
        bool ok = true;
        for (int j: a[i]) {
            if (!allowed[j]) ok = false;
        }
        if (!ok) for (int j: a[i]) allowed[j] = false;
    }

    map<int, int> ls;

    for (int i=0;i<k;++i) {
        if (!allowed[i]) continue;
        if (prv[i] != -1) continue;
        int l = 0;
        for (int j=i;j!=-1;j=nxt[j]) {
            l++;
        }
        ls[l]++;
    }

    const int MOD = 998244353;

    vector<int> kn(m + 1);
    kn[0] = 1;
    for (int i=0;i<m;++i) {
        for (auto &p: ls) {
            if (p.first + i > m) continue;
            kn[p.first + i] = (kn[p.first + i] + p.second * 1ll * kn[i]) % MOD;
        }
    }
    cout << kn[m] << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}