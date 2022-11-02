#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, q;
const int maxn = (1 << 18) + 5;

int a[maxn];

struct node{
    ll sumv, maxv, pref, surf;
    node(const node& l, const node& r){
        sumv = l.sumv + r.sumv;
        pref = max(l.pref, l.sumv + r.pref);
        surf = max(r.surf, r.sumv + l.surf);
        maxv = max(max(l.maxv, r.maxv), l.surf + r.pref);
    }
    node(int x = 0){
        sumv = x;
        maxv = pref = surf = max(x, 0);
    }
};

vector<node> tree[maxn << 2];

void build(int o, int l, int r){
    tree[o].resize(r - l + 1);
    if(l == r){
        tree[o][0] = node(a[l]);
        return;
    }
    int mid = (l + r) / 2;
#define lson o*2, l, mid
#define rson o*2+1, mid+1, r
    build(lson);
    build(rson);
    int len = r - l + 1;
    for(int i = 0;i < len;i++){
        if(i < len / 2){
            tree[o][i] = node(tree[o*2][i], tree[o*2+1][i]);
        }else{
            tree[o][i] = node(tree[o*2+1][i-len/2], tree[o*2][i-len/2]);
        }
    } 
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int N = (1 << n);
    for(int i = 1;i <= N;i++){
        cin >> a[i]; 
    }
    build(1, 1, N);
    cin >> q;
    int cur = 0;
    for(int i = 1;i <= q;i++){
        int k;
        cin >> k;
        cur ^= (1 << k);
        cout << tree[1][cur].maxv << endl;
    }
    return 0;
}