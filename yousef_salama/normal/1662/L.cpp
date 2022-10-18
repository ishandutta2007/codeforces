#include <bits/stdc++.h>
using namespace std;

struct segtree{
    vector <int> tree;
    int n;

    segtree(int n): n(n){
        tree.resize(2 * n, 0);
    }

    void update(int i, int val){
        for(i += n; i > 0; i >>= 1)tree[i] = max(tree[i], val);
    }

    int query(int l, int r){
        int ret = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1){
            if(l & 1)ret = max(ret, tree[l++]);
            if(r & 1)ret = max(ret, tree[--r]);
        }
        return ret;
    }
};

int main(){
    int n, v;
    scanf("%d %d", &n, &v);

    vector < pair <long long, long long> > p(n);
    
    for(int i = 0; i < n; i++)
        scanf("%lld", &p[i].first);

    vector <long long> vy;
    for(int i = 0; i < n; i++){
        scanf("%lld", &p[i].second);

        p[i] = make_pair(v * p[i].first - p[i].second, v * p[i].first + p[i].second);
        vy.push_back(p[i].second);
    }
    p.push_back(make_pair(0, 0));
    sort(p.begin(), p.end());

    vy.push_back(0);
    sort(vy.begin(), vy.end());
    vy.resize(unique(vy.begin(), vy.end()) - vy.begin());

    segtree tree(vy.size());

    for(int i = (int)p.size() - 1; i >= 0; i--){
        int y = lower_bound(vy.begin(), vy.end(), p[i].second) - vy.begin();
        int r = tree.query(y, (int)vy.size());

        if(p[i] == make_pair(0LL, 0LL)){
            printf("%d\n", r);
            break;
        }else{
            tree.update(y, r + 1);
        }
    }


    return 0;
}