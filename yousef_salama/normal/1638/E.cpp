#include <bits/stdc++.h>
using namespace std;

struct interval{
    int l, r, color;

    interval(){}
    interval(int l, int r, int color): l(l), r(r), color(color){}

    bool operator <(const interval& q) const{
        return l < q.l;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector <long long> tree(n + 5, 0), color_add(n + 1, 0);

    auto add = [&](int u, long long val){
        u++;
        while(u < (int)tree.size()){
            tree[u] += val;
            u += u & (-u);
        }
    };

    auto sum = [&](int u){
        u++;

        long long ret = 0;
        while(u > 0){
            ret += tree[u];
            u -= u & (-u);
        }
        return ret;
    };

    set <interval> s;
    s.insert(interval(0, n - 1, 1));

    auto find_color = [&](int i){
        auto d = s.lower_bound(interval(i + 1, 0, 0));
        d--;

        return d->color;
    };

    auto get_first = [&](int l, int r){
        auto d = s.lower_bound(interval(l, 0, 0));
        
        if(d != s.begin() && prev(d)->r >= l)return prev(d);
        if(d->l <= r)return d;

        return s.end();
    };

    auto add_interval = [&](int l, int r, int c){
        s.insert(interval(l, r, c));

        add(l, -color_add[c]);
        add(r + 1, color_add[c]);
    };

    auto erase_interval = [&](auto p){
        add(p->l, color_add[p->color]);
        add(p->r + 1, -color_add[p->color]);
        s.erase(p);
    };

    auto update_color = [&](int l, int r, int c){
        while(true){
            auto d = get_first(l, r);
            if(d == s.end())break;

            interval p = *d;
            erase_interval(d);
            
            if(p.l < l)add_interval(p.l, l - 1, p.color);
            if(p.r > r)add_interval(r + 1, p.r, p.color);
        }
        
        add_interval(l, r, c);
    };

    while(q--){
        string opr;
        cin >> opr;

        if(opr == "Color"){
            int l, r, c;
            cin >> l >> r >> c;
            l--, r--;

            update_color(l, r, c);
        }else if(opr == "Add"){
            int c, x;
            cin >> c >> x;

            color_add[c] += x;
        }else{
            int i;
            cin >> i;
            i--;

            cout << sum(i) + color_add[find_color(i)] << '\n';
        }
    }

    return 0;
}