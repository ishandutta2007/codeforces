#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define sz(a) ((int)a.size())
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define gmid (l + r >> 1)
typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5;
const int inf = 0x3f3f3f3f;

int a[maxn];
int n, q;

struct SegTree{

    int mn[maxn << 2], mn2[maxn << 2], cov[maxn << 2], num[maxn << 2];
    ll sum[maxn << 2];
    void pushUp(int rt){

        sum[rt] = sum[lson] + sum[rson];
        if(mn[lson] == mn[rson]){

            mn[rt] = mn[lson], num[rt] = num[lson] + num[rson];
            mn2[rt] = min(mn2[lson], mn2[rson]);
        }
        else if(mn[lson] < mn[rson]){

            mn[rt] = mn[lson], num[rt] = num[lson];
            mn2[rt] = min(mn2[lson], mn[rson]);
        }
        else{

            mn[rt] = mn[rson], num[rt] = num[rson];
            mn2[rt] = min(mn[lson], mn2[rson]);
        }
    }
    void build(int l, int r, int rt){

        cov[rt] = -1;
        if(l == r){

            mn[rt] = a[l], mn2[rt] = inf, sum[rt] = a[l], num[rt] = 1;
            return;
        }
        int mid = gmid;
        build(l, mid, lson);
        build(mid + 1, r, rson);
        pushUp(rt);
    }
    void pushDown2(int rt, int son){

        if(cov[rt] <= mn[son]) return;
        sum[son] += num[son] * 1ll * (cov[rt] - mn[son]);
        mn[son] = cov[son] = cov[rt];
    }
    void pushDown(int rt){

        if(cov[rt] != -1){

            pushDown2(rt, lson);
            pushDown2(rt, rson);
            cov[rt] = -1;
        }
    }
    void update(int l, int r, int rt, int L, int R, int val){

        if(val <= mn[rt]) return;
        if(l >= L && r <= R && val < mn2[rt]){

            cov[0] = val;
            pushDown2(0, rt);
            return;
        }
        int mid = gmid;
        pushDown(rt);
        if(L <= mid) update(l, mid, lson, L, R, val);
        if(R > mid) update(mid + 1, r, rson, L, R, val);
        pushUp(rt);
    }
    pii queryFirLE(int l, int r, int rt, int L, int R, int val){

        if(l >= L && r <= R && mn[rt] > val) return {0, 0};
        if(l == r) return mn[rt] <= val ? make_pair(mn[rt], l) : make_pair(0, 0);
        int mid = gmid; pii ret = {0, 0};
        pushDown(rt);
        if(L <= mid){

            ret = queryFirLE(l, mid, lson, L, R, val);
            if(ret.second) return ret;
        }
        if(R > mid){

            ret = queryFirLE(mid + 1, r, rson, L, R, val);
            if(ret.second) return ret;
        }
        return ret;
    }
    int queryFirG(int l, int r, int rt, int L, int R, int &res){

        // cout << l << " " << r << " " << L << " " << R << " " << sum[rt] << " " << res << endl;
        if(l >= L && r <= R && res >= sum[rt]){

            res -= sum[rt];
            return 0;
        }
        if(l == r) return l;
        int mid = gmid, ret = 0;
        pushDown(rt);
        if(L <= mid){

            ret = queryFirG(l, mid, lson, L, R, res);
            if(ret) return ret;
        }
        if(R > mid){

            ret = queryFirG(mid + 1, r, rson, L, R, res);
            if(ret) return ret;
        }
        return ret;
    }
} tr;

int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){

        cin >> a[i];
    }
    a[++n] = inf;
    tr.build(1, n, 1);
    while(q--){

        int opt, x, y; cin >> opt >> x >> y;
        if(opt == 1){

            tr.update(1, n, 1, 1, x, y);
        }
        else{

            int ret = 0, cur = x, res = y;
            while(1){

                pii tmp = tr.queryFirLE(1, n, 1, cur, n, res);
                int nxt = tmp.second;
                // cout << "fir " << cur << " " << nxt << " " << tmp.first << endl;
                if(!nxt) break;
                cur = nxt;
                nxt = tr.queryFirG(1, n, 1, cur, n, res);
                // cout << "sec " << cur << " " << nxt << " " << res << endl;
                ret += nxt - cur;
                cur = nxt;
                if(cur >= n) break;
                // break;
            }
            cout << ret << "\n";
        }
    }
    return 0;
}