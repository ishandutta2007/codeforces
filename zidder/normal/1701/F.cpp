#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#pragma GCC optimize ("trapv") 

using namespace std;

const int N = 200004;

long long ST[4 * N];

void build(int l=0, int r=N, int v=1) {
    ST[v] = 0;
    if (l + 1 == r)return;
    int mid = (l + r) / 2;
    build(l, mid, 2*v);
    build(mid, r, 2*v+1);
}

void addd(int ind, int val, int l=0, int r=N, int v=1) {
    ST[v] += val;
    if (l + 1 == r) return;
    int mid = (l + r) / 2;
    if (ind < mid) addd(ind, val, l, mid, v*2); 
    else addd(ind, val, mid, r, 1+v*2);
}

int cntt(int ql, int qr, int l=0, int r=N, int v=1) {
    if (ql >= r || qr <= l) return 0;
    if (ql <= l && qr >= r) return ST[v];
    int mid = (l + r) / 2;
    return cntt(ql, qr, l, mid, 2*v) + cntt(ql, qr, mid, r, 2*v+1);
}


pair<int, long long> STT[4 * N]; // (count, sum)
long long STT2[4 * N]; // sum^2
// a * (a-1) / 2 = sum a*a - sum a) / 2
long long lazy[4 * N];

void buildd(int l=0, int r=N, int v=1) {
    STT[v] = {0, 0};
    lazy[v] = 0;
    if (l + 1 == r)return;
    int mid = (l + r) / 2;
    buildd(l, mid, 2*v);
    buildd(mid, r, 2*v+1);
}

void pushh(int v, bool leaf) {
    STT2[v] += 2ll * lazy[v] * STT[v].second + lazy[v] * 1ll * lazy[v] * 1ll * STT[v].first;
    STT[v].second += STT[v].first * 1ll * lazy[v];
    if (2*v<4*N) {
        lazy[2*v] += lazy[v];
        lazy[2*v+1] += lazy[v];
    }
    lazy[v] = 0;
}

void adddd(int ql, int qr, int val, int l=0, int r=N, int v=1) {
    pushh(v, l + 1 == r);
    if (ql >= r || qr <= l) return;
    if (ql <= l && qr >= r) {
        lazy[v] += val;
        pushh(v, l + 1 == r);
        return;
    }
    int mid = (l + r) / 2;
    adddd(ql, qr, val, l, mid, 2*v);
    adddd(ql, qr, val, mid, r, 1+2*v);
    STT[v].second = STT[2*v].second + STT[2*v+1].second;
    STT[v].first = STT[2*v].first + STT[2*v+1].first;
    STT2[v] = STT2[2*v] + STT2[2*v+1];
}

void sett(int ind, int val, long long val2, int l=0, int r=N, int v=1) {
    pushh(v, l + 1 == r);
    if (l + 1 == r) {
        STT[v].first = val;
        STT[v].second = val2;
        STT2[v] = val2 * 1ll * val2;
        return;
    }
    int mid = (l + r) / 2;
    if (ind < mid) sett(ind, val, val2, l, mid, 2*v);
    else sett(ind, val, val2, mid, r, 1+2*v);
    pushh(2*v, ind + 1 == mid);
    pushh(2*v + 1, mid + 1 == r);
    STT[v].second = STT[2*v].second + STT[2*v+1].second;
    STT[v].first = STT[2*v].first + STT[2*v+1].first;
    STT2[v] = STT2[2*v] + STT2[2*v+1];
}

long long gettt() { 
    pushh(1, false);
    pushh(2, false);
    pushh(3, false);
    STT[1].second = STT[2].second + STT[3].second;
    STT[1].first = STT[2].first + STT[3].first;
    STT2[1] = STT2[2] + STT2[3];
    return (STT2[1] - STT[1].second) / 2;
}

void solve(int test_ind){
	int q, d;
    cin >> q >> d;
    vector<int> qs(q);
    for (int &i: qs) scanf("%d", &i);
    vector<long long> anss(q);

    // sum length - 1
    // i as mid
    {
        build();
        buildd();
        long long ans = 0;
        set<int> points;
        for (int i=0;i<q;++i) {
            if (points.count(qs[i])) {
                addd(qs[i], -1);
                points.erase(qs[i]);
                sett(qs[i], 0, 0);
                auto lit = points.lower_bound(qs[i] - d);
                if (lit != points.end() && *lit < qs[i]) {
                    // something reaches qs[i]
                    auto it = points.lower_bound(qs[i]);
                    --it;
                    adddd(*lit, qs[i], -1);
                    if (points.upper_bound(qs[i]) == points.end() || *points.upper_bound(qs[i]) > d + (*it)) {
                        sett(*it, 0, 0);
                    }
                }
            } else {
                addd(qs[i], 1);
                points.insert(qs[i]);
                int c = cntt(qs[i]+1, qs[i]+d+1);
                if (c) sett(qs[i], 1, c);
                auto lit = points.lower_bound(qs[i] - d);
                if (*lit < qs[i]) {
                    // something reaches qs[i]
                    auto it = points.lower_bound(qs[i]);
                    --it;
                    adddd(*lit, qs[i], 1);
                    if (points.upper_bound(qs[i]) == points.end() || *points.upper_bound(qs[i]) > d + (*it)) {
                        c = cntt(*it+1, *it+d+1);
                        // cout << *it << " " << qs[i] << " " << c << endl;
                        if (c) sett(*it, 1, c);
                    }
                }
            }
            anss[i] = gettt();
        }
    }
    // cout << ST[1] << " " << STT[1].first << " " << STT[1].second << " " << STT2[1] << endl;
    // 1 2 3 5 8
    // 3 2 2 1 0

    for (long long i: anss) {
        printf("%lld\n", i);
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