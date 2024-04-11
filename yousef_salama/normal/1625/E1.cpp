#include <bits/stdc++.h>
using namespace std;

void bit_add(vector <long long>& tree, int u, long long val){
    u++;

    while(u < (int)tree.size()){
        tree[u] += val;
        u += u & (-u);
    }
}
long long bit_sum(vector <long long>& tree, int u){
    u++;
    
    long long ret = 0;
    while(u > 0){
        ret += tree[u];
        u -= u & (-u);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    string s;
    cin >> n >> q >> s;

    stack <int> stk;
    vector <int> match(n + 1, -1);
    vector <int> parent(n + 1, -1);
    vector <int> cnt_children(n + 1, 0);

    vector <long long> bit_f(n + 5, 0);
    vector <long long> bit_children(n + 5, 0);
    
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == '('){
            stk.push(i);
        }else{
            if(stk.empty())continue;

            int u = stk.top();
            stk.pop();

            match[u] = i;
            match[i] = u;

            bit_add(bit_f, u, 1 + 1LL * cnt_children[u] * (cnt_children[u] - 1) / 2);
            bit_add(bit_children, u, 1 - cnt_children[u]);

            if(stk.empty()){
                parent[u] = 0;
            }else{
                parent[u] = stk.top();
            }

            cnt_children[parent[u]]++;
        }
    }

    while(q--){
        int t, l, r;
        cin >> t >> l >> r;

        if(t == 1){
            assert(match[l] == r && match[r] == l);

            bit_add(bit_f, l, -1);
            bit_add(bit_f, parent[l], 1 - cnt_children[parent[l]]);

            bit_add(bit_children, l, -1);
            bit_add(bit_children, parent[l], 1);

            cnt_children[parent[l]]--;
        }else{
            long long sum_f = bit_sum(bit_f, r) - bit_sum(bit_f, l - 1);
            long long sum_children = bit_sum(bit_children, r) - bit_sum(bit_children, l - 1);

            cout << sum_f + sum_children * (sum_children - 1) / 2 << '\n';
        }
    }

    return 0;
}