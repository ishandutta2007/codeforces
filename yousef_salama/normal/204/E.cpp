#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MAXM = 400010;

int n, k;
string s[MAXN];


int G[MAXM][27], suflink[MAXM], len[MAXM], sz, p;
vector <int> GTree[MAXM];
set <int> S[MAXM];

void init(){
    memset(G[0], -1, sizeof G[0]);
    len[0] = 0;
    suflink[0] = -1;
    p = 0;
    
    sz++;
}
void extend(char c, int si){
    int cur = sz++;
    
    memset(G[cur], -1, sizeof G[cur]);
    len[cur] = len[p] + 1;
    S[cur].insert(si);
    
    while((p >= 0) && (G[p][c] == -1)){
        G[p][c] = cur;
        p = suflink[p];
    }
    
    if(p == -1){
        suflink[cur] = 0;
    }else{
        int q = G[p][c];
        if(len[p] + 1 == len[q]){
            suflink[cur] = q;
        }else{
            int q_ = sz++;
            
            memcpy(G[q_], G[q], sizeof G[q]);
            len[q_] = len[p] + 1;
            
            suflink[q_] = suflink[q];
            suflink[q] = q_;
            suflink[cur] = q_;
            
            while((p >= 0) && (G[p][c] == q)){
                G[p][c] = q_;
                p = suflink[p];
            }
        }
    }
    p = cur;
}

int C[MAXM];
void build(int v){
    for(int u : GTree[v]){
        build(u);
        
        if(S[u].size() > S[v].size())swap(S[u], S[v]);
        for(int x : S[u])S[v].insert(x);
    }
    C[v] = S[v].size();
}

int main(){
    ios::sync_with_stdio(false);
    cin >> n >> k;
    
    init();
    for(int i = 0; i < n; i++){
        cin >> s[i];
        for(char c : s[i])
            extend(c - 'a', i);
        extend(26, i);
    }
    
    for(int i = 0; i < sz; i++)
        if(suflink[i] != -1)GTree[suflink[i]].push_back(i);
    build(0);
    
    for(int i = 0; i < n; i++){
        if(i > 0)cout << ' ';
        
        if(k > n){
            cout << 0;
            continue;
        }
        int r = 0, clen = 0;
        long long res = 0;
        
        for(int j = 0; s[i][j]; j++){
            r = G[r][s[i][j] - 'a'];
            clen++;
            
            while(C[r] < k){
                r = suflink[r];
                clen = len[r];
            }
            res += clen;
        }
        cout << res;
    }
    cout << endl;
}