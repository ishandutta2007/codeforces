#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef unsigned int uint;

void solve(int test_ind){
    // a, b, c, d, e
    // a, a, a, b, c
    // a, a, a, a, b
    // a, b, c, b, c
    // a, a, a, a, a

    int n, k;
    cin >> n >> k;
    vector<vector<int> > a(n, vector<int>(k));
    for (auto &row: a) for (int &i: row) scanf("%d", &i);
    vector<uint> vals(n);
    for (int i=0;i<n;++i) {
        uint v = 0;
        for (int j=0;j<k;++j) {
            v = a[i][j] + v * 3;
        }
        vals[i] = v;
    }
    map<uint, int> cnt;
    map<uint, int> example;
    for (auto i: vals) cnt[i]++;
    for (int i=0;i<n;++i) example[vals[i]] = i;

    long long ans = 0;
    for (auto it1 = cnt.begin();it1!=cnt.end();++it1) {
        int c = 0;
        for (auto it2 = cnt.begin();it2!=cnt.end();++it2) {
            if (it1 == it2) continue;
            int ind1 = example[it1->first];
            int ind2 = example[it2->first];
            uint other = 0;
            for (int i=0;i<k;++i) {
                if (a[ind1][i] == a[ind2][i]) {
                    other = other * 3 + a[ind1][i];
                } else {
                    other = other * 3 + 3 - a[ind1][i] - a[ind2][i];
                }
            }
            if (cnt.find(other) != cnt.end()) c++;
        }
        c /= 2;
        ans += c * 1ll * (c-1)/2;
    }
    cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}