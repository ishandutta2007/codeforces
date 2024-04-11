#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXM = 200005;

int T, N;
char s[MAXN];

int M, last, occ[MAXM], length[MAXM], link[MAXM], G[MAXM][26];
vector <int> S[MAXM];

void init(){
    memset(G, -1, sizeof G);
    
    link[0] = -1;
    length[0] = 0;
    occ[0] = 0;
    last = 0;
    M = 1;
}
void add(int c){
    int p = M++;
    length[p] = length[last] + 1;
    occ[p] = 1;
    link[p] = 0;
    while((last != -1) && (G[last][c] == -1)){
        G[last][c] = p;
        last = link[last];
    }
    
    if(last != -1){
        int r = G[last][c];
        if(length[last] + 1 == length[r]){
            link[p] = r;
        }else{
            int q = M++;
            memcpy(G[q], G[r], sizeof G[r]);
            length[q] = length[last] + 1;
            occ[q] = 0;
            link[q] = link[r];
            
            link[p] = q;
            link[r] = q;
            
            while((last != -1) && (G[last][c] == r)){
                G[last][c] = q;
                last = link[last];
            }
        }
    }
    last = p;
}
void build_occ(int i){
    for(int j : S[i]){
        build_occ(j);
        occ[i] += occ[j];
    }
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%s", s);
        N = strlen(s);
        
        init();
        for(int i = 0; i < N; i++)add(s[i] - 'a');
        
        for(int i = 0; i < M; i++)S[i].clear();
        for(int i = 1; i < M; i++)S[link[i]].push_back(i);
        build_occ(0);
        
        long long r = 0;
        for(int i = 1; i < M; i++)
            r += (long long) (length[i] - length[link[i]]) * occ[i] * occ[i];
        printf("%I64d\n", r);
    }
    return 0;
}