#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 17;

int n, d[MAXN], s[MAXN];
int main(){
    scanf("%d", &n);
    
    queue <int> q;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &d[i], &s[i]);
        if(d[i] == 1)q.push(i);
    }
    
    vector < pair <int, int> > e;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        
        if(d[t] == 0)continue;
        e.push_back({t, s[t]});
        
        d[s[t]]--;
        s[s[t]] ^= t;
        
        if(d[s[t]] == 1)q.push(s[t]);
    }
    
    printf("%d\n", e.size());
    for(int i = 0; i < e.size(); i++)
        printf("%d %d\n", e[i].first, e[i].second);
    
    return 0;
}