#include <bits/stdc++.h>
using namespace std;

struct segment_tree{
    vector <int> tree, flag;
    segment_tree(int n){
        tree.resize(4 * n, 0);
        flag.resize(4 * n, 0);
    }
    void push(int i, int l, int r){
        if(l < r){
            flag[2 * i] += flag[i];
            flag[2 * i + 1] += flag[i];
        }
        tree[i] += flag[i];
        flag[i] = 0;
    }
    void update(int i, int l, int r, int u, int v, int val){
        push(i, l, r);
        if(r < u || v < l)return;
        if(u <= l && r <= v){
            flag[i] += val;
            push(i, l, r);
            return;
        }

        int mid = (l + r) / 2;
        
        update(2 * i, l, mid, u, v, val);
        update(2 * i + 1, mid + 1, r, u, v, val);
        
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
};
int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        int n;
        scanf("%d", &n);

        segment_tree t_lower(2 * n), t_higher(2 * n);

        vector <bool> mark(2 * n, false);
        for(int i = 0; i < n; i++){
            int b;
            scanf("%d", &b);
            b--;

            mark[b] = true;
        }

        vector <int> a, b;
        for(int i = 0; i < 2 * n; i++){
            if(mark[i])a.push_back(i);
            else b.push_back(i);
        }

        for(int x : a){
            t_lower.update(1, 0, 2 * n - 1, 0, x, 1);
        }
        for(int x : b){
            t_lower.update(1, 0, 2 * n - 1, 0, x, -1);
        }

        int cnt = 0;
        for(int x = 0; x <= n; x++){
            if(t_lower.tree[1] >= 0 && t_higher.tree[1] >= 0)cnt++;

            if(x + 1 <= n){
                t_lower.update(1, 0, 2 * n - 1, 0, a[x], -1);
                t_higher.update(1, 0, 2 * n - 1, a[x], 2 * n - 1, 1);

                t_lower.update(1, 0, 2 * n - 1, 0, b[n - 1 - x], 1);
                t_higher.update(1, 0, 2 * n - 1, b[n - 1 - x], 2 * n - 1, -1);
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}