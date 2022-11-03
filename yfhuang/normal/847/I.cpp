//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//#include <iostream>
//#include <vector>
//#include <cmath>
//using namespace std;
//
//const int maxn = 1e5 + 5;
//char str[maxn];
//int n;
//
//bool check(int mid){
//    for(int i = 1;i <= n;i++){
//        if(str[i] == 'P'){
//            int j = i;
//            for(;j <= i && j <= n;j++){
//                if(str[j] == 'P'){
//                    i = j + mid;
//                }
//            }
//        }else if(str[i] == '*'){
//            int j;
//            for(j = i + 1;j <= n;j++){
//                if(str[j] == 'P')
//                    break;
//            }
//            if(j == n + 1) return false;
//            if(j - i > mid) return false;
//            int k = i;
//            i = max(j,i + mid - (j - i));
//            for(;k <= i && k <= n;k++){
//                if(k == j) continue;
//                if(str[k] == 'P'){
//                    i = k + mid;
//                }
//            }
//        }
//    }
//    return true;
//}
//
//int main(){
//    cin >> n;
//    scanf("%s",str + 1);
//    int l = 1,r = 2 * n;
//    while(l < r){
//        int mid = (l + r) / 2;
//        if(check(mid)){
//            r = mid;
//        }else l = mid + 1;
//    }
//    cout << l << endl;
//    return 0;
//}

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 255;

char s[maxn][maxn];

long long val[maxn][maxn];

bool vis[maxn][maxn];

queue<pair<int,int> > q;

int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
int n,m,p,o;
bool in(int x,int y){
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

void bfs(int x,int y,int now){
    queue<pair<pair<int,int> ,int> > Q;
    Q.push(make_pair(make_pair(x,y),now));
    val[x][y] += now;
    q.push(make_pair(x,y));
    vis[x][y] = 1;
    while(!Q.empty()){
        pair<pair<int,int>,int> p = Q.front();Q.pop();
        int x = p.first.first,y = p.first.second;
        int tmp = p.second;
        for(int i = 0;i < 4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(in(nx,ny) && vis[nx][ny] == 0 && s[nx][ny] != '*'){
                int nnow = tmp / 2;
                if(nnow == 0) continue;
                Q.push(make_pair(make_pair(nx,ny),nnow));
                q.push(make_pair(nx,ny));
                vis[nx][ny] = 1;
                val[nx][ny] += nnow;
            }
        }
    }
    while(!q.empty()){
        pair<int,int> p = q.front();q.pop();
        vis[p.first][p.second] = 0;
    }
}

int main(){

    cin >> n >> m >> p >> o;
    for(int i = 1;i <= n;i++){
        scanf("%s",s[i] + 1);
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(s[i][j] == '.') continue;
            if(s[i][j] == '*') continue;
            bfs(i,j,(s[i][j] - 'A' + 1) * p);
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(val[i][j] > o) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}