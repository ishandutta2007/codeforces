#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 200005;

int ST[4*N];

int m;
void build(vector<int> &a, int l=0, int r=-1, int v=1) {
    if (r == -1) r = m;
    if (l + 1 == r) {
        ST[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(a, l, m, 2*v);
    build(a, m, r, 2*v+1);
    ST[v] = max(ST[2*v], ST[1+2*v]);
}

int get_max(int ql, int qr, int l=0, int r=-1, int v=1){
    if (r == -1) r = m;
    if (ql >= r || qr <= l) return 0;
    if (ql <= l && qr >= r) return ST[v];
    int m = (l + r) / 2;
    return max(get_max(ql, qr, l, m, 2*v), get_max(ql, qr, m, r, 2*v+1));
}

void solve(int test_ind){
	int n;
    cin >> n;
    cin >> m;
    vector<int> a(m);
    for (int &i: a) scanf("%d", &i);
    build(a);

    int q;
    cin >> q;
    for (int i=0;i<q;++i) {
        int rs, cs, rt, ct, k;
        scanf("%d%d%d%d%d", &rs, &cs, &rt, &ct, &k);
        rs = n + 1 - rs;
        rt = n + 1 - rt;
        if (abs(rs - rt) % k || abs(cs - ct) % k) {
            printf("NO\n");
            continue;
        }
        rs %= k;
        if (rs == 0) rs += k;
        if (cs == ct) {
            printf("YES\n");
            continue;
        }
        if (cs > ct) swap(cs, ct);
        cs--;
        if (get_max(cs, ct) + rs > n) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
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