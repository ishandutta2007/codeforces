#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q, x[MAXN], yi;
char c[MAXN];

int tree[2][4 * MAXN], flag[2][4 * MAXN];
void push(int idx, int i, int L, int R){
    tree[idx][i] = max(tree[idx][i], flag[idx][i]);
    
    if(2 * i < 4 * MAXN)flag[idx][2 * i] = max(flag[idx][2 * i], flag[idx][i]);
    if(2 * i + 1 < 4 * MAXN)flag[idx][2 * i + 1] = max(flag[idx][2 * i + 1], flag[idx][i]);
    
    flag[idx][i] = 0;
}
void setv(int idx, int i, int L, int R, int p, int q, int v){
    push(idx, i, L, R);
    
    if(q < L || R < p)return;
    
    if(p <= L && R <= q){
        flag[idx][i] = v;
        push(idx, i, L, R);
    }else{
        int mid = (L + R) / 2;
        
        setv(idx, 2 * i, L, mid, p, q, v);
        setv(idx, 2 * i + 1, mid + 1, R, p, q, v);
        
        tree[idx][i] = max(tree[idx][2 * i], tree[idx][2 * i + 1]);
    }
}
int findr(int idx, int i, int L, int R, int r){
    push(idx, i, L, R);
    
    if(r < L || R < r)return 0;
    if(L == R)return tree[idx][i];
    
    int mid = (L + R) / 2;
    return max(findr(idx, 2 * i, L, mid, r), findr(idx, 2 * i + 1, mid + 1, R, r));
}

int main(){
    scanf("%d %d", &n, &q);
    
    vector <int> vx;
    
    vx.push_back(1);
    vx.push_back(n);
    
    for(int i = 0; i < q; i++){
        scanf("%d %d %c", &x[i], &yi, &c[i]);
        vx.push_back(x[i]);
    }
    
    sort(vx.begin(), vx.end());
    vx.resize(unique(vx.begin(), vx.end()) - vx.begin());
    
    /*
    for(int i = 0; i < vx.size(); i++)
        cout << vx[i] << ' ';
    cout << endl;
    */
    
    setv(0, 1, 0, vx.size() - 1, 0, vx.size() - 1, 1);
    setv(1, 1, 0, vx.size() - 1, 0, vx.size() - 1, 1);
    
    set <int> marked;
    for(int i = 0; i < q; i++){
        if(marked.count(x[i])){
            printf("0\n");
            continue;
        }else marked.insert(x[i]);
        
        int cx = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin();
        
        if(c[i] == 'U'){
            int r = findr(0, 1, 0, vx.size() - 1, cx);
            
            int cy = lower_bound(vx.begin(), vx.end(), (n + 1) - r) - vx.begin();
            //cout << r << ' ' << cx << ',' << cy << endl;
            
            setv(1, 1, 0, vx.size() - 1, cx, cy, x[i] + 1);
            
            printf("%d\n", (n + 1) - x[i] - r + 1);
        }else{
            int r = findr(1, 1, 0, vx.size() - 1, cx);
            
            int cy = lower_bound(vx.begin(), vx.end(), r) - vx.begin();
            //cout << r << ' ' << cy << ',' << cx << endl;
            
            setv(0, 1, 0, vx.size() - 1, cy, cx, (n + 1) - x[i] + 1);
            
            printf("%d\n", x[i] - r + 1);
        }
    }
    
    return 0;
}