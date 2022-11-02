#include <bits/stdc++.h>
using namespace std;

int n, m;
int g, r;
const int maxn = 1e4 + 5;
typedef pair<int, int> pi;
int d[maxn];

vector<int> G[maxn];

int dis[maxn][1005];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        cin >> d[i];
    }
    sort(d + 1, d + 1 + m);
    memset(dis, 0x3f, sizeof(dis));
    cin >> g >> r;
    dis[1][0] = 0;
    deque<pi> q;
    q.push_back({1, 0});
    while(!q.empty()){
        pi p = q.front();q.pop_front();
        int id = p.first;
        int val = p.second;
        if(id > 1){
            if(d[id] - d[id - 1] + val <= g){
                int val1 = (val + d[id] - d[id - 1]) % g;
                int mode = (val1 == 0);
                if(dis[id - 1][val1] > dis[id][val] + mode){
                    dis[id - 1][val1] = dis[id][val] + mode;
                    if(mode == 1)
                        q.push_back({id - 1, val1});
                    else
                        q.push_front({id - 1, val1});
                }
            }  
        }
        if(id < m){
            if(d[id + 1] - d[id] + val <= g){
                int val1 = (val + d[id + 1] - d[id]) % g;
                int mode = (val1 == 0);
                if(dis[id + 1][val1] > dis[id][val] + mode){
                    dis[id + 1][val1] = dis[id][val] + mode;
                    if(mode == 1)
                        q.push_back({id + 1, val1});
                    else
                        q.push_front({id + 1, val1});
                }
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for(int i = 0;i < g;i++){
        if(dis[m][i] != 0x3f3f3f3f){
            if(i > 0)
                ans = min(ans, dis[m][i] * (g + r) + i); 
            else
                ans = min(ans, dis[m][i] * (g + r) - r);
        }
    }
    if(ans == 0x3f3f3f3f){
        cout << -1 << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}