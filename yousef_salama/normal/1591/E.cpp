#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

struct query{
    int v, l, k, index;
    query(){}
    query(int v, int l, int k, int index): v(v), l(l), k(k), index(index){}
};

int n, a[MAXN], answer[MAXN], cnt[MAXN], sum[MAXN];
vector <int> g[MAXN];
vector <query> queries[MAXN];
set <int> values[MAXN];

void dfs(int u){
    //add
    sum[cnt[a[u]]]--;
    values[cnt[a[u]]].erase(a[u]);
    cnt[a[u]]++;
    values[cnt[a[u]]].insert(a[u]);
    
    //query
    for(query y : queries[u]){
        if(sum[n] - sum[y.l - 1] < y.k){
            answer[y.index] = -1;
            continue;
        }
        
        int L = y.l, R = n;
        while(L < R){
            int mid = (L + R) / 2;
            
            if(sum[mid] - sum[y.l - 1] >= y.k)R = mid;
            else L = mid + 1;
        }
        answer[y.index] = (*values[L].begin()) + 1;
    }
    for(int v : g[u])
        dfs(v);

    //remove
    values[cnt[a[u]]].erase(a[u]);
    cnt[a[u]]--;
    values[cnt[a[u]]].insert(a[u]);
    sum[cnt[a[u]]]++;
}

int main(){
    int t;
    scanf("%d", &t);

    while(t--){
        int q;
        scanf("%d %d", &n, &q);

        for(int i = 0; i < n; i++){
            g[i].clear();
            queries[i].clear();
            cnt[i] = 0;
        }
        
        for(int i = 0; i <= n; i++){
            values[i].clear();
            sum[i] = n;
        }
            
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            a[i]--;
        }

        for(int i = 0; i < n; i++)
            values[0].insert(i);

        for(int i = 1; i < n; i++){
            int p;
            scanf("%d", &p);
            p--;

            g[p].push_back(i);
        }

        for(int i = 0; i < q; i++){
            int v, l, k;
            scanf("%d %d %d", &v, &l, &k);
            v--;

            queries[v].push_back(query(v, l, k, i));
        }

        dfs(0);

        for(int i = 0; i < q; i++){
            if(i > 0)printf(" ");
            printf("%d", answer[i]);
        }
        printf("\n");
    }

    return 0;
}