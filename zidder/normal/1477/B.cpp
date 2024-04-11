#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


const int N = 2 * 100000;

int ST[4 * N]; // 0 count
int n, q;

void build(string &f, int l=0, int r=-1, int v=1){
    if (r==-1)
        r = n;
    if (l + 1 == r){
        ST[v] = f[l] == '0';
        return;
    }
    int m = (l + r) >> 1;
    build(f, l, m, v * 2);
    build(f, m, r, v * 2 + 1);
    ST[v] = ST[v * 2] + ST[v * 2 + 1];
}

int gett(int x, int l=0, int r=-1, int v=1){
    if (r == -1)
        r = n;
    if (l + 1 == r)
        return ST[v] == 0 ? 49 : 48;
    int m = (l + r) >> 1;
    if (ST[v] == 0){
        ST[2 * v] = 0;
        ST[2 * v+1] = 0;
    }
    if (ST[v] == r-l){
        ST[2*v] = m-l;
        ST[2*v+1] = r-m;
    }
    if (x < m)
        return gett(x, l, m, v * 2);
    return gett(x, m, r, v * 2 + 1);
}

int get(int ql, int qr, int l=0, int r=-1, int v=1){
    if (r == -1)
        r = n;
    if (qr <= l || ql >= r)
        return 0;
    if (ql <= l && qr >= r)
        return ST[v];
    int m = (l + r) >> 1;
    if (ST[v] == 0){
        ST[2 * v] = 0;
        ST[2 * v + 1] = 0;
    }
    if (ST[v] == r-l){
        ST[2*v] = m-l;
        ST[2*v+1] = r-m;
    }
    return get(ql, qr, l, m, v * 2) + get(ql, qr, m, r, v * 2 + 1);
}

void upd(int ql, int qr, bool toz, int l=0, int r=-1, int v=1){
    if (r==-1)
        r=n;
    if (qr <= l || ql >= r){
        return;
    }
    if (ql <= l && qr >= r){
        ST[v] = toz ? r-l: 0;
        return;
    }
    int m = (l + r) >> 1;
    if (ST[v] == 0){
        ST[2 * v] = 0;
        ST[2 * v+1] = 0;
    }
    if (ST[v] == r-l){
        ST[2*v] = m-l;
        ST[2*v+1] = r-m;
    }
    upd(ql, qr, toz, l, m, v * 2);
    upd(ql, qr, toz, m, r, v * 2 + 1);
    ST[v] = ST[v * 2] + ST[v * 2 + 1];
}


void solve(int test_ind){
    cin >> n >> q;
    string s, f;
    cin >> s >> f;
    vector<pair<int, int> > lr(q);
    for (int i=0;i<q;++i){
        scanf("%d%d", &lr[i].first, &lr[i].second);
    }
    build(f);
    for (int i=q-1;i>=0;i--){
        int ln = lr[i].second - lr[i].first + 1;
        int cnt = get(lr[i].first - 1, lr[i].second);
        if (ln == cnt * 2){
            cout << "NO" << endl;
            return;
        }
        if (ln > cnt * 2)
            upd(lr[i].first-1, lr[i].second, false);
        else
            upd(lr[i].first-1, lr[i].second, true);
    }
    for (int i=0;i<n;++i)
        if (gett(i) != s[i]){
            cout << "NO" << endl;
            return;
        }
    cout << "YES" << endl;
    return;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}