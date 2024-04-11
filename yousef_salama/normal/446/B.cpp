#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXK = 1000005;

int n, m, k, p, a[MAXN][MAXN], r[MAXN], c[MAXN];
long long sr[MAXK], sc[MAXK];

int main(){
    scanf("%d %d %d %d", &n, &m, &k, &p);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++){
        scanf("%d", &a[i][j]);
        
        r[i] += a[i][j];
        c[j] += a[i][j];
    }
    
    priority_queue <long long> q;
    for(int i = 0; i < n; i++)q.push(r[i]);
    
    sr[0] = 0;
    for(int t = 1; t <= k; t++){
        long long x = q.top();
        q.pop();
        
        sr[t] = sr[t - 1] + x;
        q.push(x - p * m);
    }
    
    while(!q.empty())q.pop();
    for(int i = 0; i < m; i++)q.push(c[i]);
    
    sc[0] = 0;
    for(int t = 1; t <= k; t++){
        long long x = q.top();
        q.pop();
        
        sc[t] = sc[t - 1] + x;
        q.push(x - p * n);
    }
    
    long long res = -1LL << 60;
    for(int t = 0; t <= k; t++)
        res = max(res, sr[t] + sc[k - t] - 1LL * t * (k - t) * p);
    printf("%I64d\n", res);
    
    return 0;
}