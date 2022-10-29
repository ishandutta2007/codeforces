#include <bits/stdc++.h>
using namespace std;


int mp[1206][1006];

int dx[8] = {1,1,1,0,0,-1,-1,-1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};

int main () {
    int n;
    cin >> n;
    int x,y;
    cin >> x >> y;
    for (int i=0;i<8;++i) {
        for (int j=0;;++j) {
            int tx=x+j*dx[i],ty=y+j*dy[i];
            if (1 <= tx && tx <=n && 1 <= ty && ty<=n) {
                mp[tx][ty] = 1;
            }
            else {
                break;
            }
        }
    }
    queue<pair<int,int> > que;
    int sx,sy;
    cin >> sx >> sy;
    mp[sx][sy] = 2;
    int cx,cy;
    cin >> cx >> cy;
    que.push(make_pair(sx,sy));
    while (!que.empty()) {
        pair<int,int> p = que.front();
        que.pop();
        int x=p.first,y=p.second;
        for (int i=0;i<8;++i) {
            int tx=x+dx[i],ty=y+dy[i];
            if (1 <= tx && tx <= n && 1 <= ty && ty <= n && mp[tx][ty] == 0) {
                mp[tx][ty] = 2;
                que.push(make_pair(tx,ty));
            }
        }
    }
    if (mp[cx][cy] == 2) puts("YES");
    else puts("NO");
}