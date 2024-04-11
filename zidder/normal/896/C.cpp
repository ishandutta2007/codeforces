// https://codeforces.com/problemset/problem/896/C

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
using namespace std;
#define mp make_pair
typedef long long ll;

int n, m;
ll seed, vmax;
set<pair<int, long long> > a;
int rnd() {
	ll ret = seed;
	seed = (seed * 7 + 13) % 1000000007;
	return ret;
}

long long binpow(long long a, long long p, long long mod){
    return p?binpow(a*a%mod, p>>1, mod)*(p&1?a:1)%mod:1%mod;
}

void op3(int l, int r, int x) {
    vector<pair<long long, int> > aa;
    auto it1 = a.upper_bound(mp(l+1, 0));
    auto it2 = it1;
    it2--;
    int c;
    if (it1!=a.end()) c = it1->first;
    else c = n;
    aa.emplace_back(it2->second, min(c, r) - l);
    if (it1 != a.end() && it1->first < r){
        it1++;
        it2++;
        while (it1 != a.end() && it1->first < r){
            aa.emplace_back(it2->second, it1->first-it2->first);
            it1++;
            it2++;
        }
        aa.emplace_back(it2->second, r - it2->first);
    }	sort(aa.begin(), aa.end());
    c = 0;
    long long val = -1;
    // cout << l << " " << r << " " << x << endl;
    for (int i=0;i<aa.size();++i){
        // cout << i << " " << aa[i].first << " " << aa[i].second << endl;
        if (c + aa[i].second > x) {
            val = aa[i].first;
            break;
        }
        c += aa[i].second;
    }
    if (val == -1) throw "unknown error";
	printf("%lld\n", val);
}

void op4(int l, int r, int x, int y) {
	int sum = 0;
    auto it1 = a.upper_bound(mp(l+1, 0));
    auto it2 = it1;
    it2--;
    int c;
    if (it1!=a.end()) c = it1->first;
    else c = n;
    sum = (sum + binpow(it2->second%y, x, y) * (min(c, r) - l) % y) % y;
    if (it1 != a.end() && it1->first < r){
        it1++;
        it2++;
        while (it1 != a.end() && it1->first < r){
            sum = (sum + binpow(it2->second%y, x, y) * (it1->first-it2->first) % y) % y;
            it1++;
            it2++;
        }
        sum = (sum + binpow(it2->second%y, x, y) * (r - it2->first) % y) % y;
    }
	printf("%d\n",sum);
}

void solve(int op, int l, int r, int x, int y) {
	if (op == 1) {
        auto it = a.lower_bound(mp(l+1, 0));
        it--;
        if (it->first < l){
            a.insert(mp(l, it->second));
            it++;
        }
        long long lst = it->second;
        set<pair<int, long long> > nw;
        while (it!=a.end() && it->first < r) {
            lst = it->second;
            nw.emplace(it->first, it->second);
            it++;
        }
        for (auto &p: nw) {
            a.erase(p);
            a.emplace(p.first, p.second + x);
        }
        if (it == a.end() || it->first != r) {
            if (it != a.end() || r != n) a.insert(mp(r, lst));
        }
	}
	if (op == 2) {
        auto it = a.lower_bound(mp(l+1, 0));
        it--;
        long long lst = it->second;
        if (it->first == l){
            a.erase(it);
        }
        a.insert(mp(l, x));
        while (true){
            it = a.upper_bound(mp(l+1, 0));
            if (it == a.end() || it->first > r) {
                if (it != a.end() || r != n) a.insert(mp(r, lst));
                break;
            }
            if (it->first == r) break;
            if (it->first < r) {
                lst = it->second;
                a.erase(it);
            }
        }
	}
	if (op == 3) {
		op3(l, r, x);
	}
	if (op == 4) {
		op4(l, r, x, y);
	}
}

// vector<long long> a1;
// void solve1(int op, int l, int r, int x, int y){
//     if (op == 1){
//         for (int i=l;i<r;++i) a1[i] += x;
//     }
//     if (op == 2){
//         for (int i=l;i<r;++i) a1[i] = x;
//     }
//     if (op == 3){
//         vector<long long> aa;
//         for (int i=l;i<r;++i) aa.push_back(a1[i]);
//         sort(aa.begin(), aa.end());
//         printf("%lld\n", aa[x]);
//     }
//     if (op == 4){
//         long long sum = 0;
//         for (int i=l;i<r;++i) (sum += binpow(a1[i]%y, x, y))%=y;
//         printf("%lld\n", sum);
//     }
// }

int main() {
	cin >> n >> m >> seed >> vmax;
    // a1 = vector<long long>(n);
	for (size_t i = 0; i < n; i++) {
        int val = rnd() % vmax + 1;
        // a1[i] = val;
        a.emplace(i, val);
	}
	for (size_t i = 0; i < m; i++) {
		int op = rnd() % 4 + 1;
		int l = rnd() % n + 1;
		int r = rnd() % n + 1;
		if (l > r)
			swap(l, r);
        l--;
		int x;
		if (op == 3)
			x = rnd() % (r - l);
		else
			x = rnd() % vmax + 1;
		int y = -1;
		if (op == 4) {
			y = rnd() % vmax + 1;
		}
		solve(op, l, r, x, y);
		// solve1(op, l, r, x, y);
	}
	//system("pause");
	return 0;
}