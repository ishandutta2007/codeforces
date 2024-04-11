#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXQ = 5005;

int N, q, a[MAXN], L[MAXQ], R[MAXQ];
double P[MAXQ];

vector <int> G[MAXQ];
int V[MAXQ];

set < pair <int, int> > S;
void buildV(int u){
    for(int j : G[u])buildV(j);
    
    auto d = S.lower_bound({L[u], -1 << 30});
    stack < pair <int, int> > toremove;
    while(d != S.end()){
        if(d->first > R[u])break;
        
        V[u] = max(V[u], d->second);
        toremove.push(*d);
        
        d++;
    }
    
    while(!toremove.empty()){
        S.erase(toremove.top());
        toremove.pop();
    }
}

double dp[MAXQ][2 * MAXQ];
double solve(int i, int j){
    if(dp[i][j] == dp[i][j])return dp[i][j];
    if(V[i] > j)return 0;
    
    double rq = 1.0 - P[i], rp = 0.0;
    for(int u : G[i])
        rq *= solve(u, j);
        
    if(V[i] + 1 <= j){
        rp = P[i];
        for(int u : G[i])
            rp *= solve(u, j - 1);
    }
    
    return dp[i][j] = rq + rp;
}

int main(){
    scanf("%d %d", &N, &q);
    for(int i = 0; i < N; i++)scanf("%d", &a[i]);

    for(int i = 0; i < q; i++){
        scanf("%d %d %lf", &L[i], &R[i], &P[i]);
        L[i]--, R[i]--;
    }
    
    L[q] = 0, R[q] = N - 1, P[q] = 1.0;
    q++;
    
    int MX = 0;
    for(int i = 0; i < N; i++)MX = max(MX, a[i]);
    for(int i = 0; i < N; i++)a[i] -= MX - (q + 1);
    
    int root = -1;
    for(int i = 0; i < q; i++){
        int p = -1;
        for(int j = 0; j < q; j++)if(i != j){
            if((L[i] == L[j]) && (R[i] == R[j])){
                if(j < i)continue;
            }
            
            if((L[j] <= L[i]) && (R[i] <= R[j])){
                if(p == -1){
                    p = j;
                }else{
                    if((R[j] - L[j]) < (R[p] - L[p]))p = j;
                }
            }
        }
        
        if(p != -1)G[p].push_back(i);
        else root = i;
        
        V[i] = -1 << 30;
    }
    /*
    for(int i = 0; i < N; i++)
        cout << a[i] << ' ';
    cout << endl;
    
    for(int i = 0; i < q; i++){
        cout << i << ':';
        for(int j : G[i])cout << j << ' ';
        cout << endl;
    }*/
    
    for(int i = 0; i < N; i++)S.insert({i, a[i]});
    buildV(root);
    
    memset(dp, -1, sizeof dp);
    
    double r = 0.0;
    for(int i = q + 1; i <= 2 * q + 1; i++)
        r += (solve(root, i) - solve(root, i - 1)) * i;
    printf("%.12f\n", r + MX - (q + 1) - 1);
    
    return 0;
}