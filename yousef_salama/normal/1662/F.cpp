#include <bits/stdc++.h>
using namespace std;

struct segtree{
    vector <long long> tree;
    int n;

    segtree(int n): n(n){
        tree.resize(4 * n + 20, -(1 << 30));
    }

    void update(int i, int L, int R, int u, int val){
        if(u < L || R < u)return;

        if(L == R){
            tree[i] = val;
            return;
        }

        int mid = (L + R) / 2;

        update(2 * i, L, mid, u, val);
        update(2 * i + 1, mid + 1, R, u, val);

        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    void add_to_queue(int i, int L, int R, int u, int v, int a, queue <int>& q, vector <int>& dist, int d){
        if(v < L || R < u || tree[i] < a)return;

        if(L == R){
            if(dist[L] == -1){
                q.push(L);
                dist[L] = d;
            }
            tree[i] = -(1 << 30);

            return;
        }

        int mid = (L + R) / 2;

        add_to_queue(2 * i, L, mid, u, v, a, q, dist, d);
        add_to_queue(2 * i + 1, mid + 1, R, u, v, a, q, dist, d);
        
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
};

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);
        a--, b--;

        vector <int> p(n);
        for(int i = 0; i < n; i++)
            scanf("%d", &p[i]);

        segtree tree_left{n}, tree_right{n};
        for(int i = 0; i < n; i++)if(i != a){
            tree_left.update(1, 0, n - 1, i, p[i] + i);
            tree_right.update(1, 0, n - 1, i, p[i] - i);
        }

        queue <int> q;
        vector <int> dist(n, -1);
        q.push(a);
        dist[a] = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
        
            if(u > 0)tree_left.add_to_queue(1, 0, n - 1, max(0, u - p[u]), u - 1, u, q, dist, dist[u] + 1);
            if(u + 1 < n)tree_right.add_to_queue(1, 0, n - 1, u + 1, min(n - 1, u + p[u]), -u, q, dist, dist[u] + 1);
        }

        printf("%d\n", dist[b]);
    }

    return 0;
}