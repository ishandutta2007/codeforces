#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 300003;

int h[N], b[N];
int n;

int hT[4 * N]={}; // min segment tree
long long dT[4 * N]={0}; // max segment tree

void buildH(int l, int r, int v=1){
    if (l+1 ==r){
        hT[v] = h[l];
        return;
    }
    int m = (l+r)>>1;
    buildH(l, m, 2*v);
    buildH(m, r, 2*v+1);
    hT[v] = min(hT[v*2], hT[2*v+1]);
}

int leftmosth(int qr, int l=0, int r=-1, int v=1){ // left most h > h[qr]
    if (r==-1)
        r=n;
    int m = (l + r) >> 1;
    if (l == m){
        if (h[l] < h[qr])
            return r;
        return l;
    }
    if (m >= qr)
        return leftmosth(qr, l, m, 2*v);
    if (r <= qr){
        if (hT[v] > h[qr])
            return l;
    }
    int rgt = leftmosth(qr, m, r, 2*v+1);
    if (rgt == m)
        return leftmosth(qr, l, m, 2*v);
    return rgt;
}

void build(){
    buildH(0, n);
}

void sett(int ind, long long val, int l=0, int r=-1, int v=1){
    if (r==-1)
        r=n;
    if (l+1==r){
        dT[v] = val;
        return;
    }
    int m = (l+r)>>1;
    if (m > ind)
        sett(ind, val, l, m, 2*v);
    else
        sett(ind, val, m, r, 2*v+1);
    dT[v] = max(dT[2*v], dT[2*v+1]);
}

long long getd(int ind, int l=0, int r=-1, int v=1){
    if (r==-1)
        r = n;
    if (l+1==r)
        return dT[v];
    int m = (l+r)>>1;
    if (m>ind)
        return getd(ind, l, m, v*2);
    return getd(ind, m, r, v*2+1);
}

const long long INF = -100000000 * 1ll * 1000000000; // 10^16

long long maxd(int ql, int qr, int l=0, int r=-1, int v=1){
    if(r==-1)r=n;
    if (l >= qr || r <= ql) return INF;
    if (l >= ql && r <= qr) return dT[v];
    int m = (l+r)>>1;
    return max(maxd(ql, qr, l, m, 2*v), maxd(ql, qr, m, r, 2*v+1));
}

void solve(int test_ind){
    cin >> n;
    for (int i=0;i<n;++i)
        scanf("%d", &h[i]);
    for (int i=0;i<n;++i)
        scanf("%d", &b[i]);
    sett(0, b[0]);
    build();
    long long ns;
    for (int i=1;i<n;++i){
        int l = leftmosth(i);
        // >= l
        ns = max(maxd(l, i), getd(i-1)) + (b[i] + 0ll);
        // <  l
        if (l)
            ns = max(ns, getd(l-1));
        else
            ns = max(ns, b[i]+0ll);
        sett(i, ns);
    }
    cout << getd(n-1) << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}