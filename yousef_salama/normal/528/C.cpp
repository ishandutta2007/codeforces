#include <stdio.h>
#include <vector>

using namespace std;

const int MAXN = 100005;
const int MAXM = 500005;

int n, m, ai, bi, deg[MAXN], st[MAXN];
vector < pair <int, int> > g[MAXN];

bool removed[MAXM];
vector <int> tour;

void find_tour(int u){
    for( ; st[u] < g[u].size(); st[u]++){
        int v = g[u][st[u]].first;
        if(removed[g[u][st[u]].second])continue;
        
        removed[g[u][st[u]].second] = true;
        find_tour(v);
    }
    tour.push_back(u);
}

int main(){
    scanf("%d %d", &n, &m);
    
    int edge_n = 0;
    while(m--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        g[ai].push_back(make_pair(bi, edge_n));
        g[bi].push_back(make_pair(ai, edge_n));

        deg[ai]++;
        deg[bi]++;
        
        edge_n++;
    }
    
    vector <int> odd;
    for(int i = 0; i < n; i++)
        if((deg[i] % 2) != 0)odd.push_back(i);
    for(int i = 0; i < (odd.size()); i += 2){
        g[odd[i]].push_back(make_pair(odd[i + 1], edge_n));
        g[odd[i + 1]].push_back(make_pair(odd[i], edge_n));
        
        edge_n++;
    }
    
    if((edge_n % 2) != 0){
        g[0].push_back(make_pair(0, edge_n));
        
        edge_n++;
    }
    
    find_tour(0);
    
    printf("%d\n", edge_n);
    for(int i = 0; (i + 1) < tour.size(); i++){
        if((i % 2) == 0)printf("%d %d\n", tour[i] + 1, tour[i + 1] + 1);
        else printf("%d %d\n", tour[i + 1] + 1, tour[i] + 1);   
    }
    
    return 0;
}