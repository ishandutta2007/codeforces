#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 400002;
vector<int> divs[N];

long long ST[4*N];

void addd(int ql, int qr, long long val, int l=0, int r=N, int v=1){
    if (ql<=l && qr >= r) {
        ST[v] += val;
        return;
    }
    if (ql >= r || qr <= l) return;
    int m = (l + r) / 2;
    addd(ql, qr, val, l, m, 2*v);
    addd(ql, qr, val, m, r, 2*v+1);
}

long long gett(int x, int l=0, int r=N, int v=1){
    if (l + 1 == r) return ST[v];
    int m = (l + r) / 2;
    if (x < m) return ST[v] + gett(x, l, m, 2*v);
    else return ST[v] + gett(x, m, r, 2*v+1);
}

void solve(int test_ind){
    int q;
    cin >> q;
    vector<pair<pair<int, int> , int> > lr(q);
    for (int i=0;i<q;++i) scanf("%d%d", &lr[i].first.first, &lr[i].first.second);
    for (int i=0;i<q;++i) lr[i].second = i;
    sort(lr.begin(), lr.end());
    vector<vector<int> > rs(200002);
    for (int i=0;i<q;++i) rs[lr[i].first.second].push_back(i);
    vector<long long> ans(q);

    long long c = 0;
    for (int i=3;i<=200000;++i){
        addd(1, 2, ((long long)divs[i].size() - 2) * ((long long)divs[i].size() - 1) / 2);
        for (int divind=0;divind+1<divs[i].size();++divind) {
            // i + d1 + d2 > i
            // d1 | i, d2 | i, d1 < d2, d1, d2 >= l
            int d = divs[i].size() - 2 - divind;
            addd(divs[i][divind]+1, divs[i][divind+1]+1, d * 1ll * (d-1) / 2);
        }
        if (i > 3 && i % 3 == 0) {
            int d = (i%2==0)+(i%5==0);
            addd(1, i/3+1, d);
            // 2/3i + i + j > 2i
            // j | 2i, j >= l, j < i, j > i / 3, j != 2/3i
            // if (i%3 == 0 && i / 3 * 2 >= l)  c -= lower_bound(divs[2*i].begin(), divs[2*i].end(), i) - lower_bound(divs[2*i].begin(), divs[2*i].end(), max(l, i/3+1)) - 1;
            if (i % 10 == 0) {
                addd(i/3+1, 2*i/5+1, 2);
                addd(2*i/5+1, i/2+1, 1);
            } else {
                if (i % 5 == 0) {
                    addd(i/3+1, 2*i/5+1, 1);
                }
                if (i % 2 == 0) {
                    addd(i/3+1, i/2+1, 1);
                }
            }
        }
        for (int j: rs[i]) {
            // c += (i - l) * 1ll * (i - l - 1) / 2;
            int l = lr[j].first.first;
            int r = lr[j].first.second;
            // sum for i =l to r (i-l)* (i-l-1) / 2 
            // sum for i = 0 to r-l i * (i - 1) / 2
            // (sum for i = 0 to r-l i^2 - i) / 2
            int d = r - l;
            ans[lr[j].second] = (d * 1ll * (d + 1) * 1ll * (d - 1)) / 6;
            ans[lr[j].second] -= gett(l);
        }
    }
    for (long long i: ans) printf("%lld\n", i);
}

int main(){
    for (int i=1;i<N;++i) {
        for (int j=i;j<N;j+=i) {
            divs[j].push_back(i);
        }
    }
	int t=1;
	// cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}