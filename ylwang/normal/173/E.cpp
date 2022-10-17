#define _CRT_SECURE_NO_WARNINGS
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
using namespace std;
inline int read()
{
    int num = 0; char c=' '; int flag = 1;
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num * flag;
}
#define MAXN 100005
int n, k;
struct Node {
    int A, P, id;
    bool operator < (const Node b) const {return P < b.P;}
}a[MAXN];
int l[MAXN], r[MAXN], id[MAXN], v[MAXN];
inline void init_a() {
    For(i, 1, n) v[i] = a[i].A;
    sort(v + 1, v + 1 + n);
    For(i, 1, n) a[i].A = lower_bound(v + 1, v + 1 + n, a[i].A) - v;
}
int val[MAXN]; // 
#define ls bst[rt].l
#define rs bst[rt].r
int sz = 0;
struct Banlance_Tree
{
    int l, r, val, rd, sum, key;
}bst[MAXN * 25];
struct Treap
{
    int root;

    inline void update(int rt)  {
        bst[rt].sum = max(bst[ls].sum,  max(bst[rs].sum,  bst[rt].key));
    }
    inline void insert(int &rt, int x, int key) {
        if(rt == 0) {
            rt = ++sz;
            bst[rt].val = x;
            bst[rt].key = bst[rt].sum = key;
            return;
        }
        if(bst[rt].val == x) bst[rt].key = max(key, bst[rt].key);
        else if(x < bst[rt].val)
            insert(ls, x, key);
        else
            insert(rs, x, key);
        update(rt);
    }
    inline int Get_rank(int rt, int x) {
        if(rt == 0) return -1;
        if(x == bst[rt].val) return max(bst[rs].sum, bst[rt].key);
        else if(x > bst[rt].val) return Get_rank(rs, x);
        else return max(bst[rs].sum, max(bst[rt].key, Get_rank(ls, x)));
    }
}tr[MAXN * 4];
struct SEG
{
    #define mid ((l + r) >> 1)
    inline void build(int rt, int l, int r)
    {
        For(i, l, r) tr[rt].insert(tr[rt].root, a[i].A, val[i]);
        if(l == r) return;
        build(rt << 1, l, mid);
        build(rt << 1 | 1, mid + 1, r);
    }
    inline int Get_rank(int rt, int l, int r, int x, int y, int k) {
        if(l == x && r == y) return tr[rt].Get_rank(tr[rt].root, k);
        if(y <= mid) return Get_rank(rt << 1, l, mid, x, y, k);
        else if(x > mid) return Get_rank(rt << 1 | 1, mid + 1, r, x, y, k);
        else return max(Get_rank(rt << 1, l, mid, x, mid, k), Get_rank(rt << 1 | 1, mid + 1, r, mid + 1, y, k));
    }
    #undef mid
}seg;
#undef ls
#undef rs
struct Charman_tree {
    int ls, rs, num;
}t[MAXN*25];

inline int pushup(int k) {
    t[k].num = t[t[k].ls].num + t[t[k].rs].num;
    return k;
}
int root[MAXN], tot = 0;
inline int build(int l, int r) {
    int mid = (l + r) >> 1, k = ++tot;
    if(l == r) {t[k].num = 0; return 0;}
    t[k].ls = build(l, mid);
    t[k].rs = build(mid+1, r);
    return k;
}
inline int insert(int now, int l, int r, int pos) {
    int k = ++tot, mid = (l + r) >> 1; t[k] = t[now];
    if(l == r) {t[k].num++; return k;}
    if(pos <= mid) t[k].ls = insert(t[now].ls, l, mid, pos);
    else t[k].rs = insert(t[now].rs, mid+1, r, pos);
    return pushup(k);
}
int query(int p, int q, int l, int r, int k) {
    if(l == r) return l;
    int mid = (l + r) >> 1, lnum = t[t[p].ls].num - t[t[q].ls].num;
    if(k <= lnum) return query(t[p].ls, t[q].ls, l, mid, k);
    else return query(t[p].rs, t[q].rs, mid+1, r, k - lnum);
}
signed main()
{
	
//	int T = read();
//	while(T--) {
		memset(bst, 0, sizeof(bst)); sz = 0;
		memset(tr, 0, sizeof(tr));
		mst(a, 0); mst(l, 0); mst(r, 0); mst(v, 0);
		mst(root, 0); tot = 0;
		n = read(), k = read();
	    For(i, 1, n) a[i].A = read(), a[i].id = i;
	    For(i, 1, n) a[i].P = read();
	    sort(a + 1, a + 1 + n);
	    init_a();
	    For(i, 1, n) id[a[i].id] = i;
	    root[0] = build(1, n);
	    For(i, 1, n) root[i] = insert(root[i-1], 1, n, a[i].A);
	    For(i, 1, n) {
	        Node tmp1 = a[i], tmp2 = a[i];
	        tmp1.P = a[i].P-k, tmp2.P = a[i].P+k;
	        l[i] = lower_bound(a + 1, a + 1 + n, tmp1) - a;
	        r[i] = upper_bound(a + 1, a + 1 + n, tmp2) - a - 1;
	    }
	    For(i, 1, n) {
	        int posr = r[i], posl = l[i];
	        int l = 1, r = (posr-posl+1);
	        while(l <= r) {
	            int mid = (l + r) >> 1;
	            if(query(root[posr], root[posl-1], 1, n, mid) <= a[i].A) {
	                l = mid+1;  val[i] = mid;
	            } else {
	                r = mid-1;
	            }
	        }
	    }
	    seg.build(1, 1, n);
	    int Qnum = read();
	    while(Qnum--) {
	        int x = id[read()];
	        int y = id[read()];
	        if(a[x].A < a[y].A) swap(x, y);
	        int posl = max(l[x], l[y]), posr = min(r[x], r[y]);
	        if(posr < posl) { 
	            printf("-1\n");
	            continue;
	        }
	        printf("%d\n", seg.Get_rank(1, 1, n, posl, posr, a[x].A));
	    }
//	}
    
    return 0;
}