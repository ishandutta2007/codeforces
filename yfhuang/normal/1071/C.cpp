#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

int n;
const int maxn = 1e5 + 5;

int a[maxn];

struct op{
    int x, y, z;
    op(int _x=0, int _y=0, int _z=0):x(_x), y(_y), z(_z){}
};

vector<op> ans;

int dis[(1 << 13) + 5];

int pre[(1 << 13) + 5];

vector<int> candop;

void init(){
    for(int i = 0;i < n;i++){
        for(int j = i + 1;j < n;j++){
            for(int k = j + 1; k < n;k++){
                if(j * 2 == i + k){
                    int trans = 0;
                    trans |= (1 << i);
                    trans |= (1 << j);
                    trans |= (1 << k);
                    candop.push_back(trans);
                }
            }
        }
    }
}

void bfs(){
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int p = q.front();q.pop();
        for(auto v : candop){
            int to = p ^ v;
            if(dis[to] > dis[p] + 1){
                dis[to] = dis[p] + 1;
                pre[to] = v;
                q.push(to);
            }
        }      
    }
}

void solve(int x, int y, int z){
    ans.emplace_back(x, y, z);
    a[x] ^= 1;
    a[y] ^= 1;
    a[z] ^= 1;
}

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    for(int i = n;i > 13;i--){
        if(a[i] == 0)
            continue;
        if(a[i - 1] == 1 and a[i - 2] == 1){
            solve(i, i - 1, i - 2);
            continue;
        }
        if(a[i - 1] == 0 and a[i - 2] == 0){
            solve(i, i - 3, i - 6);
            continue;
        }
        if(a[i - 1] == 0 and a[i - 2] == 1){
            solve(i, i - 2, i - 4);
            continue;
        }
        if(a[i - 1] == 1 and a[i - 2] == 0){
            if(a[i - 3] == 0 and a[i - 4] == 0 and a[i - 5] == 0){
                solve(i, i - 6, i - 12);
                solve(i - 1, i - 6, i - 11);
                continue;
            }
            if(a[i - 3] == 1 and a[i - 4] == 0 and a[i - 5] == 0){
                solve(i, i - 3, i - 6);
                solve(i - 1, i - 6, i - 11);
                continue;
            }
            if(a[i - 3] == 0 and a[i - 4] == 1 and a[i - 5] == 0){
                solve(i, i - 4, i - 8);
                solve(i - 1, i - 6, i - 11);
                continue;
            }
            if(a[i - 3] == 0 and a[i - 4] == 0 and a[i - 5] == 1){
                solve(i, i - 5, i - 10);
                solve(i - 1, i - 6, i - 11);
                continue;
            }
            if(a[i - 3] == 1 and a[i - 4] == 1 and a[i - 5] == 0){
                solve(i, i - 3, i - 6);
                solve(i - 1, i - 4, i - 7);
                continue;
            }
            if(a[i - 3] == 1 and a[i - 4] == 0 and a[i - 5] == 1){
                solve(i, i - 3, i - 6);
                solve(i - 1, i - 5, i - 9);
                continue;
            }
            if(a[i - 3] == 0 and a[i - 4] == 1 and a[i - 5] == 1){
                solve(i, i - 4, i - 8);
                solve(i - 1, i - 5, i - 9);
                continue;
            }
            if(a[i - 3] == 1 and a[i - 4] == 1 and a[i - 5] == 1){
                solve(i, i - 4, i - 8);
                solve(i - 1, i - 3, i - 5);
                continue;
            }
        }
    }
    n = min(n, 13);
    init();
    int dest = 0;
    for(int i = 0;i < n;i++){
        if(a[i + 1] == 1){
            dest |= (1 << i);
        }
    }
    bfs();
    if(dis[dest] == 0x3f3f3f3f){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        int cur = dest;
        while(cur > 0){
            int opt = pre[cur];
            cur = cur ^ opt;
            for(int i = 0;i < n;i++){
                for(int j = i + 1;j < n;j++){
                    for(int k = j + 1;k < n;k++){
                        int state = 0;
                        state |= (1 << i);
                        state |= (1 << j);
                        state |= (1 << k);
                        if(state == opt){
                            ans.emplace_back(i + 1, j + 1, k + 1);
                        }
                    }
                }
            }
        }
        cout << ans.size() << endl;
        for(int i = 0;i < ans.size();i++){
            printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
        }
    }
    return 0;
}