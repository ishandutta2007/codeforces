#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <memory.h>
#include <sstream>
#include <stack>
#include <fstream>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <list>
#include <stdlib.h>
#include <queue>
#include <set>
using namespace std;

/*
*/

const int mod = 1000000007;

long long pw(long long a, long long p)
{
    if (p == 0) return 1;
    long long r = pw(a, p/2);
    r = r*r;
    r %= mod;
    if (p%2==1)
    {
        return (a*r)%mod;
    }
    return r;
}

struct S
{
    long long val, lazy; // can store
    S()
    {
        val = 0;
        lazy = 1;
    }
};

    S tree[1000000];
    
    
    S join(S L, S R)
    {
        S res;
        res.val = L.val + R.val;
        res.val %= mod;
        res.lazy = 1;
        return res;
    }

    void mul(int i, int l, int r, int a, int b, long long s)
    {
        if (l > r)
        {
            tree[i] = S(); //null value
            return;
        }
        if (a > r || b < l)
        {
            return; // old unaffected value for parent update
        }
        if (l >= a && b >= r)
        {
            tree[i].val *= s;
            tree[i].val %= mod;
            tree[i].lazy *= s;
            tree[i].lazy %= mod;
            return;
        }
        if (tree[i].lazy > 1)
        {
            mul(i*2+1, l, (l+r)/2, l, (l+r)/2, tree[i].lazy);
            mul(i*2+2, (l+r)/2+1, r, (l+r)/2+1, r, tree[i].lazy);           
            tree[i].lazy = 1;
        }
        
        mul(i*2+1, l, (l+r)/2, a, b, s);
        mul(i*2+2, (l+r)/2+1, r, a, b, s);
        tree[i] = join(tree[i*2+1],tree[i*2+2]);
        
    }
    S add(int i, int l, int r, int x, long long val)
    {
        if (l > r)
        {
            tree[i] = S(); //null value
            return tree[i];
        }
        if (x > r || x < l)
        {
            return tree[i]; // old unaffected value for parent update
        }
        if (l == r)
        {
            tree[i].val = tree[i].lazy*val;
            tree[i].val %= mod;
            return tree[i];
        }
        if (tree[i].lazy > 1)
        {
            mul(i*2+1, l, (l+r)/2, l, (l+r)/2, tree[i].lazy);
            mul(i*2+2, (l+r)/2+1, r, (l+r)/2+1, r, tree[i].lazy);   
            tree[i].lazy = 1;       
        }
    
        S L = add(i*2+1, l, (l+r)/2, x, val);
        S R = add(i*2+2, (l+r)/2+1, r, x, val);
        tree[i] = join(L, R);
        return tree[i];
    }

    S get(int i, int l, int r, int a, int b)
    {
        if (l >= a && r <= b)
        {
            return tree[i];
        }
        if (l > b || r < a)
        {
            S ret; //null value (node range out of query range)
            return ret;
        }
        if (tree[i].lazy > 1)
        {
            mul(i*2+1, l, (l+r)/2, l, (l+r)/2, tree[i].lazy);
            mul(i*2+2, (l+r)/2+1, r, (l+r)/2+1, r, tree[i].lazy);       
            tree[i].lazy = 1;   
        }
        S L = get(i*2+1, l, (l+r)/2, a, b);
        S R = get(i*2+2, (l+r)/2+1, r, a, b);
        S ret = join(L, R);
        return ret;
    }

    S getMul(int i, int l, int r, int a)
    {
        if (l > a || r < a)
        {
            S ret; //null value (node range out of query range)
            return ret;
        }
        if (l == r)
        {
            return tree[i];
        }
        if (tree[i].lazy > 1)
        {
            mul(i*2+1, l, (l+r)/2, l, (l+r)/2, tree[i].lazy);
            mul(i*2+2, (l+r)/2+1, r, (l+r)/2+1, r, tree[i].lazy);   
            tree[i].lazy = 1;       
        }
        if (a <= (l+r)/2) return getMul(i*2+1, l, (l+r)/2, a);
        return getMul(i*2+2, (l+r)/2+1, r, a);
    }


int v[200005];
int in[200005];
int out[200005];
int n;
vector<int> tr[200005];
int ch[200005];
int par[200005];

struct qu
{
    int com, u;
};
int T;

void dfs(int i)
{
    in[i] = T;
    T++;
    for (int j = 0; j < tr[i].size(); j++)
    {
        dfs(tr[i][j]);
    }
    out[i] = T-1;
}

qu queries[200005];
int main()
{
    n = 1;
    int q;
    scanf("%d %d", &v[0], &q);
    memset(ch, 0, sizeof(ch));

    for (int i = 0; i < q; i++)
    {
        int com;
        scanf("%d", &com);
        if (com == 1)
        {
            int u, val;
            scanf("%d %d", &u, &val);
            u--;
            queries[i].com = com;
            queries[i].u = u;
            
            tr[u].push_back(n++);
            v[n-1] = val;
            par[n-1] = u;
        }
        else
        {
            int u;
            scanf("%d", &u);
            u--;
            queries[i].com = com;
            queries[i].u = u;
        }
    }
    
    for (int i = 0; i < n; i++)
        ch[i] = 1;
    T = 0;
    dfs(0);
    mul(0, 0, n-1, in[0], out[0], 1);
    add(0, 0, n-1, in[0], v[0]);
    int n2 = 1;
    for (int i = 0; i < q; i++)
    {
        if (queries[i].com == 1)
        {
            int u = queries[i].u;
            //cout << u << ' ' << in[u] << ' ' << out[u] << ' ' << ch[u] << endl;
            mul(0, 0, n-1, in[queries[i].u], out[queries[i].u], pw(ch[u], mod-2));
            mul(0, 0, n-1, in[queries[i].u], out[queries[i].u], ++ch[u]);
            add(0, 0, n-1, in[n2], v[n2]);
            
            n2++;
        }
        else
        {
            //cout << queries[i].u << endl;
            long long res = get(0, 0, n-1, in[queries[i].u], out[queries[i].u]).val;
            long long ml;
            if (queries[i].u > 0){
                ml = get(0, 0, n-1, in[par[queries[i].u]], in[par[queries[i].u]]).val;
                ml *= pw(v[par[queries[i].u]], mod - 2);
                ml %= mod;
            }else ml = 1;
            
            res *= pw(ml, mod-2);
            res %= mod;
            int ans = res;
            
            printf("%d\n", ans);
        }
    }
}