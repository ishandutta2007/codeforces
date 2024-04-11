#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, m, res[MAXN];
long long li[MAXN], ri[MAXN], x[MAXN], y[MAXN];
pair <long long, int> a[MAXN];

vector < pair <long long, pair <int, int> > > events;

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%I64d %I64d", &li[i], &ri[i]);
    
    for(int i = 0; i < m; i++){
        scanf("%I64d", &a[i].first);
        a[i].second = i;
    }
    sort(a, a + m);
        
    for(int i = 1; i < n; i++){
        x[i - 1] = li[i] - ri[i - 1];
        y[i - 1] = ri[i] - li[i - 1];
        
        events.push_back({x[i - 1], {i - 1, 0}});
        events.push_back({y[i - 1] + 1, {i - 1, 1}});
    }
    sort(events.rbegin(), events.rend());
    
    memset(res, -1, sizeof res);
    set < pair <long long, int> > S;
    
    for(int i = 0; i < m; i++){
        while(!events.empty() && events.back().first <= a[i].first){
            pair <int, int> event = events.back().second;
            
            if(event.second == 0)S.insert({y[event.first], event.first});
            else if(S.count({y[event.first], event.first}))S.erase({y[event.first], event.first});
            
            events.pop_back();
        }
        
        if(!S.empty()){
            pair <long long, int> d = *S.begin();
            res[d.second] = a[i].second + 1;
            S.erase(d);
        }
    }
    
    for(int i = 0; i < n - 1; i++)if(res[i] == -1){
        printf("No\n");
        return 0;
    }
    
    printf("Yes\n");
    for(int i = 0; i < n - 1; i++){
        if(i > 0)printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
    
    return 0;
}