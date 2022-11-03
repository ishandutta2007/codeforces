#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
#define all(x) ALL(x)
#define trav(i, a) for(auto &i : a)
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cerr << ", "; cetak(v...);}
 
#define debug(x...) cout<< '(' << #x << ") = ("; cetak(x) 
#define sz(x) (long long)(x.size())
#define lt(x) (long long)(x.length())

const int MOD = 1e9 + 7;
const int mx = 1e5 + 10;

typedef long long ll;

typedef vector<int> vi;
struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
        pos += 1;
		for (; pos <= sz(s); pos += pos & -pos) s[pos - 1] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
        pos += 1;
		for (; pos > 0; pos -= pos & -pos) res += s[pos-1];
        // debug(res);
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};


struct FT2 {
	vector<vi> ys; vector<FT> ft;
	FT2(int limx) : ys(limx) {}
	void fakeUpdate(int x, int y) {
        x += 1;
		for (; x <= sz(ys); x += x & -x) ys[x - 1].push_back(y);
	}
	void init() {
		trav(v, ys) sort(all(v)), v.erase(unique(all(v)), v.end()), ft.emplace_back(sz(v));
	}
	int ind(int x, int y) {
        int in = (int)(upper_bound(all(ys[x]), y) - ys[x].begin());
        in -= 1;
        // if(x == 3){
            // debug("tiga  ", y, in);
            // for(auto i : ys[x]){
            //     debug(i);
            // }
        // }
		return in; 
    }
	void update(int x, int y, ll dif) {
        // debug(x, y, dif);
        x += 1;
		for (; x <= sz(ys); x += x & -x){
            // debug(x - 1, y, ind(x - 1, y), dif);
			ft[x - 1].update(ind(x - 1, y), dif);
        }
	}
	ll query(int x, int y) {
        // debug(x, y);
		ll sum = 0;
        x += 1;
		for (; x; x -= x & -x){
            // debug(x - 1, ind(x - 1, y));
			sum += ft[x-1].query(ind(x - 1, y));
        }
		return sum;
	}
};

int n, m, a[mx], t[mx], x[mx], y[mx];
set<int> isi[mx];

void fake_del(int x, FT2 &ini){
    auto it = isi[a[x]].upper_bound(x);
    if(it != isi[a[x]].end()){
        int l = n - x - 1;
        int r = *it;
        ini.fakeUpdate(l, r);
        // kurang 
    }
    it = isi[a[x]].lower_bound(x);
    if(it != isi[a[x]].begin()){
        it--;
        int l = n - *it - 1;
        int r = x;
        ini.fakeUpdate(l, r);
        // kurang 

        auto it2 = isi[a[x]].upper_bound(x);
        if(it2 != isi[a[x]].end()){
            int l = n - *it - 1;
            int r = *it2;
            ini.fakeUpdate(l, r);
            //tambah
        }
    }
}

void del(int x, FT2 &ini){
    auto it = isi[a[x]].upper_bound(x);
    if(it != isi[a[x]].end()){
        int l = n - x - 1;
        int r = *it;
        // ini.fakeUpdate(l, r);
        // kurang 
        ini.update(l, r, -(*it - x));
    }
    it = isi[a[x]].lower_bound(x);
    if(it != isi[a[x]].begin()){
        it--;
        int l = n - *it - 1;
        int r = x;
        // ini.fakeUpdate(l, r);
        // kurang 
        ini.update(l, r, -(x - *it));
        auto it2 = isi[a[x]].upper_bound(x);
        if(it2 != isi[a[x]].end()){
            int l = n - *it - 1;
            int r = *it2;
            // ini.fakeUpdate(l, r);
            //tambah
            ini.update(l, r, *it2 - *it);
        }
    }
}

void fake_add(int x, FT2 &ini){
    auto it = isi[a[x]].upper_bound(x);
    if(it != isi[a[x]].end()){
        int l = n - x - 1;
        int r = *it;
        ini.fakeUpdate(l, r);
        // tambah 
    }
    it = isi[a[x]].lower_bound(x);
    if(it != isi[a[x]].begin()){
        it--;
        int l = n - *it - 1;
        int r = x;
        ini.fakeUpdate(l, r);
        // tambah 

        auto it2 = isi[a[x]].upper_bound(x);
        if(it2 != isi[a[x]].end()){
            int l = n - *it - 1;
            int r = *it2;
            ini.fakeUpdate(l, r);
            //kurang
        }
    }
}

void add(int x, FT2 &ini){
    auto it = isi[a[x]].upper_bound(x);
    if(it != isi[a[x]].end()){
        int l = n - x - 1;
        int r = *it;
        // ini.fakeUpdate(l, r);
        // tambah 
        ini.update(l, r, *it - x);
    }
    it = isi[a[x]].lower_bound(x);
    if(it != isi[a[x]].begin()){
        it--;
        int l = n - *it - 1;
        int r = x;
        // ini.fakeUpdate(l, r);
        // tambah 
        ini.update(l, r, x - *it);
        auto it2 = isi[a[x]].upper_bound(x);
        if(it2 != isi[a[x]].end()){
            int l = n - *it - 1;
            int r = *it2;
            // ini.fakeUpdate(l, r);
            //tambah
            ini.update(l, r, -(*it2 - *it));
        }
    }
}

int b[mx];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
        isi[a[i]].insert(i);
    }
    FT2 ini(n);
    for(int i = 0; i < n; i++){
        auto it = isi[a[i]].upper_bound(i);
        if(it != isi[a[i]].end()){
            int l = n - i - 1;
            int r = *it;
            ini.fakeUpdate(l, r);
            // tambah 
        }
    }

    for(int i = 0; i < m; i++){
        cin >> t[i] >> x[i] >> y[i];
        if(t[i] == 1){
            x[i] -= 1;
            fake_del(x[i], ini);
            isi[a[x[i]]].erase(x[i]);
            a[x[i]] = y[i];
            isi[a[x[i]]].insert(x[i]);
            fake_add(x[i], ini);
        }
        else{
            x[i] -= 1, y[i] -= 1;
            x[i] = n - x[i] - 1;
            ini.fakeUpdate(x[i], y[i]);
        }
    }
    ini.init();
    for(int i = 1; i <= n; i++) isi[i].clear();
    for(int i = 0; i < n; i++){
        // cin >> a[i];
        a[i] = b[i];
        isi[a[i]].insert(i);
    }
    for(int i = 0; i < n; i++){
        auto it = isi[a[i]].upper_bound(i);
        if(it != isi[a[i]].end()){
            int l = n - i - 1;
            int r = *it;
            // debug(i, *it);
            // ini.fakeUpdate(l, r);
            // tambah 
            ini.update(l, r, *it - i);
        }
    }

    for(int i = 0; i < m; i++){
        // cin >> t[i] >> x[i] >> y[i];
        if(t[i] == 1){
            del(x[i], ini);
            isi[a[x[i]]].erase(x[i]);
            a[x[i]] = y[i];
            isi[a[x[i]]].insert(x[i]);
            add(x[i], ini);
        }
        else{
            // debug(x[i], y[i]);
            long long jaw = ini.query(x[i], y[i]);
            cout << jaw << '\n';
        }
    }
}