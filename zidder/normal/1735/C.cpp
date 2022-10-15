#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
    int n;
    cin >> n;
    string t;
    cin >> t;
    vector<int> par(26);
    for (int i=0;i<26;++i) par[i] = i;
    vector<int> sz(26, 1);
    function<int(int)> dsu =[&](int x) {
        if (x == par[x]) return x;
        return par[x] = dsu(par[x]);
    };

    auto merge = [&](int x, int y) {
        par[x] = y;
        sz[y] += sz[x];
    };

    vector<int> prv(26, -1);

    string s = "";
    for (int i=0;i<n;++i) {
        int c = t[i]-'a';
        for (int j=0;j<26;++j) {
            if (prv[j] == c) {
                s += (j + 'a');
                break;
            }
        }
        if (s.size() == i) for (int j=0;j<26;++j) {
            if (prv[j] != -1) continue;
            if (sz[dsu(j)] == 26) {
                prv[j] = c;
                s += (j + 'a');
                break;
            }
            if (dsu(c) == dsu(j)) continue;
            merge(dsu(j), dsu(c));
            prv[j] = c;
            s += (j + 'a');
            break;
        }
    }
    cout << s << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}