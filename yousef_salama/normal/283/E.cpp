//In the name of Allah

#include <bits/stdc++.h>
using namespace std;

int n, k, s[100005], ai, bi;
vector < pair <int, int> > evs[100005];

int tree[4 * 100005], lazy[4 * 100005];
void push(int i, int L, int R){
    if(lazy[i] == 0)return;
    
    if(2 * i < 4 * 100005)lazy[2 * i] ^= 1;
    if(2 * i + 1 < 4 * 100005)lazy[2 * i + 1] ^= 1;
    
    tree[i] = (R - L + 1) - tree[i];
    lazy[i] = 0;
}
void flip(int i, int L, int R, int p, int q){
    push(i, L, R);
    
    if((q < L) || (R < p))return;
    if((p <= L) && (R <= q)){
        lazy[i] ^= 1;
        push(i, L, R);
        
        return;
    }
    
    int mid = (L + R) / 2;

    flip(2 * i, L, mid, p, q);
    flip(2 * i + 1, mid + 1, R, p, q);

    tree[i] = tree[2 * i] + tree[2 * i + 1];
}
int find(int i, int L, int R, int k){
    push(i, L, R);
    
    if((k < L) || (R < k))return 0;
    if(L == R)return tree[i];
    
    int mid = (L + R) / 2;
    return find(2 * i, L, mid, k) + find(2 * i + 1, mid + 1, R, k);
}

int main(){
    scanf("%d %d", &n, &k);
    
    for(int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    sort(s, s + n);
    
    while(k--){
        scanf("%d %d", &ai, &bi);
        
        ai = lower_bound(s, s + n, ai) - s;
        bi = upper_bound(s, s + n, bi) - s;
        
        evs[ai].push_back(make_pair(ai, bi));
        evs[bi].push_back(make_pair(ai, bi));
    }
     
    for(int i = 0; i < n; i++)
        flip(1, 0, n - 1, i, i);
     
    long long r = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < evs[i].size(); j++)
            flip(1, 0, n - 1, evs[i][j].first, evs[i][j].second - 1);
        flip(1, 0, n - 1, i, i);
        
        int X = tree[1] - find(1, 0, n - 1, i);
        if(X > 0)r += (long long)X * (X - 1) / 2;
    }
    printf("%I64d\n", (long long)n * (n - 1) * (n - 2) / 6 - r);
    
    return 0;
}