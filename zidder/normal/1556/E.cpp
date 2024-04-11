#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 100007;

pair<long long, long long> ST[4 * N];

int sz;

void build(vector<long long> &p, int l=0, int r=-1, int v=1){
    sz = p.size();
    if (r==-1)
        r=p.size();
    if (l + 1 == r){
        ST[v] = make_pair(p[l], p[l]);
        return;
    }
    int m = (l + r) / 2;
    build(p, l, m, 2 * v);
    build(p, m, r, 2 * v + 1);
    ST[v] = make_pair(min(ST[2 * v].first, ST[2 * v + 1].first), max(ST[2 * v].second, ST[2 * v + 1].second));
}

long long mn(int ql, int qr, int l=0, int r=-1, int v = 1){
    if (r == -1)
        r = sz;
    if (ql >= r || qr <= l) return ST[1].second;
    if (l >= ql && r <= qr) return ST[v].first;

    int m = (l + r) / 2;
    return min(mn(ql, qr, l, m, v * 2), mn(ql, qr, m, r, v * 2 + 1));
}

long long mx(int ql, int qr, int l=0, int r=-1, int v=1){
    if (r == -1)
        r = sz;

    if (ql >= r || qr <= l) return ST[1].first;
    if (l >= ql && r <= qr) return ST[v].second;

    int m = (l + r) / 2;
    return max(mx(ql, qr, l, m, v * 2), mx(ql, qr, m, r, v * 2 + 1));
}

void solve(int test_ind){
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)cin>>b[i];

    vector<long long> p(n+1);
    
    for (int i=0;i<n;++i){
        p[i+1] = p[i] + b[i] - a[i];
    }

    build(p);
    for (int i=0;i<q;++i){
        int l, r;
        cin >> l >> r;
        long long mnmm = mn(l, r+1);
        if (p[r] - p[l - 1] != 0 || mnmm < p[r]){
            cout << -1 << endl;
            continue;
        }
        cout << mx(l, r+1) - p[r] << endl;
    }
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}