#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int n, k;
const int maxn = (1 << 19) + 5;

int bit[maxn];

vector<int> candx, tmp;

void init(){
    candx.push_back(0);
    candx.push_back(1);
    for(int i = 1;i < k;i++){
        tmp = candx;
        candx.clear();
        for(auto x : tmp){
            candx.push_back(x << 1 | 0);
        }
        reverse(tmp.begin(), tmp.end());
        for(auto x : tmp){
            candx.push_back(x << 1 | 1);
        }
    }
    for(int i = 0;i < k;i++){
        bit[1 << i] = i;
    }
}

struct node{
    ll l, r;
    ll len, ans;
    node(ll _l = 0, ll _r = 0, ll _len = 0, ll _ans = 0): l(_l), r(_r), len(_len), ans(_ans){}
    void print(){
        cout << l << " " << r << " " << len << " " << ans << '\n';
    }
}trie[maxn * 2];


int a[maxn];
int c[maxn];

int ls[maxn * 2], rs[maxn * 2];

#define lson o*2, l, mid
#define rson o*2+1, mid+1, r

void pushup(int o){
    trie[o].ans = min(trie[ls[o]].ans, trie[rs[o]].ans);
    trie[o].len = trie[ls[o]].len + trie[rs[o]].len;
    trie[o].l = min(trie[ls[o]].l, trie[rs[o]].l + trie[ls[o]].len);
    trie[o].r = max(trie[ls[o]].r, trie[rs[o]].r + trie[ls[o]].len);
    trie[o].ans = min(trie[o].ans, trie[rs[o]].l + trie[ls[o]].len - trie[ls[o]].r);
}

void build(int o, int l, int r){
    if(l == r){
        if(c[l] == 1){
            trie[o] = node(0, 0, 1, 2e9); 
        }else{
            trie[o] = node(1e9, -1e9, 1, 2e9); 
        }    
        return;
    }
    int mid = (l + r) / 2;
    ls[o] = o*2, rs[o] = o*2 + 1;
    build(lson);
    build(rson);
    pushup(o);
}

void swap_seg(int o, int cl, int tl){
    if(cl == tl){
        swap(ls[o], rs[o]);
        pushup(o);
        return;
    }
    swap_seg(ls[o], cl+1, tl);
    swap_seg(rs[o], cl+1, tl);
    pushup(o);
}


int ans[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    init();
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        c[a[i]] = 1;
    } 
    build(1, 0, (1 << k) - 1);
    ans[0] = trie[1].ans;
    for(int i = 1;i < (1 << k);i++){
        int diff = bit[candx[i] ^ candx[i-1]];
        swap_seg(1, 0, k - 1 - diff);
        ans[candx[i]] = trie[1].ans;
    }
    for(int i = 0;i < (1 << k);i++){
        cout << ans[i] << ((i == (1 << k) - 1) ? '\n' : ' ');
    }
    return 0;
}