#include <bits/stdc++.h>
using namespace std;

struct node{
    int val, left, right;
    node(int val, int left, int right): val(val), left(left), right(right){}
};
vector <node> tree;

node combine(int left, int right){
    return node(max(tree[left].val, tree[right].val), left, right);
}

int build(int l, int r){
    if(l == r){
        tree.push_back(node(0, -1, -1));
        return (int)tree.size() - 1;
    }else{
        int mid = (l + r) / 2;

        int left = build(l, mid);
        int right = build(mid + 1, r);

        tree.push_back(combine(left, right));
        return (int)tree.size() - 1;
    }
}
int update(int i, int l, int r, int ind, int val){
    if(ind < l || ind > r)return i;
    if(l == r){
        if(val > tree[i].val){
            tree.push_back(node(val, -1, -1));
            return (int)tree.size() - 1;
        }else return i;
    }

    int mid = (l + r) / 2;

    int left = update(tree[i].left, l, mid, ind, val);
    int right = update(tree[i].right, mid + 1, r, ind, val);

    tree.push_back(combine(left, right));
    return (int)tree.size() - 1;
}
int query(int i, int l, int r, int p, int q){
    if(q < l || r < p)return 0;
    if(p <= l && r <= q)return tree[i].val;

    int mid = (l + r) / 2;
    return max(query(tree[i].left, l, mid, p, q), query(tree[i].right, mid + 1, r, p, q));
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);

        vector <int> a(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            a[i]--;
        }
        vector <int> trees;
        
        tree.clear();
        trees.push_back(build(0, n - 1));

        vector <int> dp(n), pre(n);
        for(int i = 0; i < n; i++){
            dp[i] = 1 + query(trees[i], 0, n - 1, 0, a[i]);

            pre[i] = i - 1;
            while(pre[i] >= 0 && a[pre[i]] < a[i])
                pre[i] = pre[pre[i]];

            if(pre[i] != -1){
                dp[i] = max(dp[i], 2 + query(trees[pre[i]], 0, n - 1, 0, a[i]));
            }

            trees.push_back(update(trees.back(), 0, n - 1, a[i], dp[i]));
        }

        printf("%d\n", *max_element(dp.begin(), dp.end()));
    }
    return 0;
}