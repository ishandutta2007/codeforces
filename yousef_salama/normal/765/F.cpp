#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXM = 300005;

int n, m, a[MAXN], res[MAXM], li, ri;
vector < pair <int, int> > queries[MAXN];

int SegTree[4 * MAXN];
void updateSegTree(int i, int L, int R, int k, int v){
    if((k < L) || (R < k))return;
    
    SegTree[i] = min(SegTree[i], v);
    if(L == R)return;
    
    int mid = (L + R) / 2;
    updateSegTree(2 * i, L, mid, k, v);
    updateSegTree(2 * i + 1, mid + 1, R, k, v);
}
int querySegTree(int i, int L, int R, int p, int q){
    if((R < p) || (q < L))return 1 << 30;
    if((p <= L) && (R <= q))return SegTree[i];

    int mid = (L + R) / 2;
    return min(querySegTree(2 * i, L, mid, p, q), querySegTree(2 * i + 1, mid + 1, R, p, q));
}

int BIT[MAXN];
void updateBIT(int i, int v){
    i++;
    while(i < MAXN){
        BIT[i] = min(BIT[i], v);
        i += i & (-i);
    }
}
int queryBIT(int i){
    i++;
    
    int r = 1 << 30;
    while(i > 0){
        r = min(r, BIT[i]);
        i -= i & (-i);
    }
    return r;
}

int main(){
    vector <int> vx;
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        vx.push_back(a[i]);
    }
    
    vx.push_back(-1);
    vx.push_back(1 << 30);
    
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    
    scanf("%d", &m);
    for(int q = 0; q < m; q++){
        scanf("%d %d", &li, &ri);
        li--, ri--;
        
        queries[li].push_back({ri, q});
    }
    
    for(int i = 0; i < 4 * MAXN; i++)SegTree[i] = 1 << 30;
    for(int i = 0; i < MAXN; i++)BIT[i] = 1 << 30;
    
    for(int l = n - 1; l >= 0; l--){
        int d = 1 << 30, r = l;
        while(true){
            int p = upper_bound(vx.begin(), vx.end(), max(-1, a[l] - d))
                                                    - vx.begin();
            int q = upper_bound(vx.begin(), vx.end(), min((1 << 30) - 5, a[l] + d - 1))
                                                    - vx.begin() - 1;
            
            r = querySegTree(1, 0, vx.size() - 1, p, q);
            //cout << a[l] << ' ' << p << ',' << q << ' ' << r << endl;
            
            if(r < (1 << 30)){
                updateBIT(r, abs(a[l] - a[r]));
                d = queryBIT(r);
            }else break;
        }
        
        int k = lower_bound(vx.begin(), vx.end(), a[l]) - vx.begin();
        updateSegTree(1, 0, vx.size() - 1, k, l);
        
        for(auto q : queries[l])
            res[q.second] = queryBIT(q.first);
    }
    
    for(int i = 0; i < m; i++)
        printf("%d\n", res[i]);
    
    
    return 0;

}