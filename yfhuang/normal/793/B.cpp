//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//const int maxn = 2e5 + 5;
//
//char s[maxn];
//int sum[maxn];
//
//int T;
//
//vector<int> G[2];
//
//int main(){
//    cin >> T;
//    while(T--){
//        int n;
//        scanf("%d",&n);
//        scanf("%s",s + 1);
//        sum[0] = 0;
//        for(int i = 1;i <= n;i++){
//            sum[i] = sum[i - 1] + (s[i] == '1');
//        }
//        int cnt1 = 0,cnt2 = 0,cnt3 = 0;
//        for(int i = 1;i <= n;i++){
//            if(s[i] == '1'){
//                cnt1 = n - i + 1;
//                break;
//            }
//        }
//        for(int i = n;i >= 1;i--){
//            if(s[i] == '1'){
//                cnt2 = i;
//                break;
//            }
//        }
//        for(int i = 1;i <= n;i++){
//            if(s[i] == '1') cnt3++;
//        }
//        long long ans = 0;
//        G[0].clear();G[1].clear();
//        G[0].push_back(0);
//        for(int i = 1;i <= n;i++){
//            int mod = sum[i] % 2;
//            ans += G[1 ^ mod].size();
//            G[mod].push_back(i);
//        }
//        cout << ans - cnt1 - cnt2 + cnt3 << endl;
//    }
//    return 0;
//}

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n,m;
const int maxn = 1005;
char s[maxn][maxn];
int d[maxn][maxn];
bool inq[maxn][maxn];


int main(){
    cin >> n >> m;
    int sx,sy,tx,ty;
    for(int i = 1;i <= n;i++){
        scanf("%s",s[i] + 1);
        for(int j = 1;j <= m;j++){
            if(s[i][j] == 'S') sx = i,sy = j;
            if(s[i][j] == 'T') tx = i,ty = j;
        }
    }
    memset(d,0x3f,sizeof(d));
    memset(inq,false,sizeof(inq));
    inq[sx][sy] = true;
    d[sx][sy] = 0;
    queue<pair<int,int> > q;
    q.push(make_pair(sx,sy));
    while(!q.empty()){
        pair<int,int> p = q.front();q.pop();
        int x = p.first;
        int y = p.second;
        inq[x][y] = false;
        if(d[x][y] >= 3) continue;
        for(int i = x - 1;i > 0;i--){
            if(s[i][y] == '*') break;
            if(d[i][y] > d[x][y] + 1){
                d[i][y] = d[x][y] + 1;
                if(!inq[i][y]){
                    q.push(make_pair(i,y));
                    inq[i][y] = true;
                }
            }
            if(d[i][y] == d[x][y]) break;
        }
        for(int i = x + 1;i <= n;i++){
            if(s[i][y] == '*') break;
            if(d[i][y] > d[x][y] + 1){
                d[i][y] = d[x][y] + 1;
                if(!inq[i][y]){
                    q.push(make_pair(i,y));
                    inq[i][y] = true;
                }
            }
            if(d[i][y] == d[x][y]) break;
        }
        for(int j = y + 1;j <= m;j++){
            if(s[x][j] == '*') break;
            if(d[x][j] > d[x][y] + 1){
                d[x][j] = d[x][y] + 1;
                if(!inq[x][j]){
                    q.push(make_pair(x,j));
                    inq[x][j] = true;
                }
            }
            if(d[x][j] == d[x][y]) break;

        }for(int j = y - 1;j > 0;j--){
            if(s[x][j] == '*') break;
            if(d[x][j] > d[x][y] + 1){
                d[x][j] = d[x][y] + 1;
                if(!inq[x][j]){
                    q.push(make_pair(x,j));
                    inq[x][j] = true;
                }
            }
            if(d[x][j] == d[x][y]) break;
        }
    }
   /* for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            printf("%d ",d[i][j]);
        }
        puts("");
    }*/
    if(d[tx][ty] <= 3) printf("YES");
    else printf("NO");
    return 0;
}