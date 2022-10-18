#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#define Trvi(it, c) for(__typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
using namespace std;
struct tri{
    int a, b, c;
    tri(int i, int j, int k){
        a = i;
        b = j;
        c = k;
    }
};
struct state{
    int cur, per, cost;
    state(int i, int j, int k){
        cur = i;
        per = j;
        cost = k;
    }
};
int N, M, K, a, b, c;
vector <int> g[3005];
set <tri> forb;
bool operator <(tri a, tri b){
    if(a.a != b.a)return a.a < b.a;
    if(a.b != b.b)return a.b < b.b;
    return a.c < b.c;
}
int main(){
    scanf("%d %d %d", &N, &M, &K);
    while(M--){
        scanf("%d %d", &a, &b);
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }
    while(K--){
        scanf("%d %d %d", &a, &b, &c);
        forb.insert(tri(a - 1, b - 1, c - 1));
    }
    int p[N][N];
    memset(p, -1, sizeof p);
    p[0][0] = 0;
    queue <state> q;
    q.push(state(0, 0, 0));
    while(!q.empty()){
        state s = q.front();
        q.pop();
        if(s.cur == N - 1){
            printf("%d\n", s.cost);
            int cur = s.cur, per = s.per, temp;
            stack <int> path;
            while(cur != 0){
                path.push(cur);
                temp = cur;
                cur = per; per = p[temp][per];
            }
            printf("1 ");
            while(!path.empty()){
                printf("%d ", path.top() + 1);
                path.pop();
            }
            printf("\n");
            return 0;
        }
        Trvi(next, g[s.cur]){
            if(!forb.count(tri(s.per, s.cur, *next)) && p[*next][s.cur] == -1){
                p[*next][s.cur] = s.per;
                q.push(state(*next, s.cur, s.cost + 1));
            }
        }
    }
    printf("-1\n");
    return 0;
}