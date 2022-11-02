#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 1e5 + 5;
const int maxb = 1005;
const int INF = 1e9;

struct FT {
	vector<int> s;
	FT(int n) : s(n) {}
	void update(int pos, int dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	int query(int pos) { // sum of values in [0, pos)
		int res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(int sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 16; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};


int n, q;
int a[maxn], b[maxn];
int c[maxn];
int st[maxb], ed[maxb], len[maxb];

#define lson o*2,l,mid
#define rson o*2+1,mid+1,r

vector<int> p[maxb];  

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int B = ceil(sqrt(n)) + 1;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        b[i] = (i - 1) / B + 1;
    }
    for(int i = 1;i <= n;i++){
        if(!st[b[i]]) st[b[i]] = i;
        ed[b[i]] = i;
    }
    int m = b[n];
    for(int i = 1;i <= m;i++){
        len[i] = ed[i] - st[i] + 1;
    }
    FT ft(n + 1);
    for(int i = 1;i <= n;i++){
        ft.update(i, 1);
    }
    auto build = [&](int bid){
        for(int j = st[bid];j <= ed[bid];j++){
            int &val = p[bid][j-st[bid]];
            val = max(0, ft.lower_bound(a[j])); 
            ft.update(val, 1);
        }
        for(int j = st[bid];j <= ed[bid];j++){
            int val = p[bid][j-st[bid]];
            ft.update(val, -1);
        }
        sort(p[bid].begin(), p[bid].end());
    };
    for(int i = 1;i <= m;i++){
        p[i].resize(len[i]);
        build(i);
    }
    int Q;
    cin >> Q;
    while(Q--){
        int op;
        cin >> op;
        if(op == 1){
            int i, x;
            cin >> i >> x;
            a[i] = x;
            build(b[i]);
        }else{
            int i;
            cin >> i;
            int ans = a[i];
            for(int j = i + 1;j <= ed[b[i]];j++){
                ans += (ans >= a[j]);
            }
            for(int j = b[i] + 1;j <= m;j++){
                ans += (int)(upper_bound(p[j].begin(), p[j].end(), ans) - p[j].begin());
            }
            cout << n - ans << '\n';
        }
    }
    return 0;
}