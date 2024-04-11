#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxn = 4e5 + 10;

int h[maxn],d[maxn];
int two[maxn];

int n,m;
typedef long long LL;

pair<LL,int> W[2][19][maxn][2];
pair<LL,int> INF = {-1e18,-1};

void update(pair<LL,int> target[],pair<LL,int> v){
    if(v.second == target[0].second || v.second == target[1].second) return;
    if(v.first > target[0].first){
        target[1] = target[0];
        target[0] = v;
    }else if(v.first > target[1].first){
        target[1] = v;
    }
}

LL query(int x,int y){
    pair<LL,int > res[2][2];
    int lv = two[y - x + 1];
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 2;j++) res[i][j] = W[i][lv][x][j];
        for(int j = 0;j < 2;j++) update(res[i], W[i][lv][y - (1 << lv) + 1][j]);
    }
    if(res[0][0].second != res[1][0].second) return res[1][0].first + res[0][0].first;
    return max(res[0][0].first + res[1][1].first,res[0][1].first + res[1][0].first);
}


int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d",d + i);
        d[i + n] = d[i];
    }
    for(int i = 1;i <= n;i++){
        scanf("%d",h + i);
        h[i + n] = h[i];
    }
    memset(two,0,sizeof(two));
    for(int i = 0;i < 19;i++){
        two[1 << i] = i;
    }
    for(int i = 1;i < maxn;i++){
        if(!two[i]){
            two[i] = two[i - 1];
        }
    }
    LL now = 0;
    for(int i = 1;i <= 2 * n;i++){
        W[0][0][i][0] = make_pair(now + 2LL * h[i],i);
        W[1][0][i][0] = make_pair(-now + 2LL * h[i],i);
        W[0][0][i][1] = W[1][0][i][1] = INF;
        now += d[i];
    }
    //cout << W[0][0][4][0].first << " " << W[1][0][5][0].first << endl;
    for(int i = 0;i < 2;i++){
        for(int j = 1;j < 19;j++){
            for(int k = 1;k <= 2 * n;k++){
                for(int k2 = 0;k2 < 2;k2++) W[i][j][k][k2] = W[i][j - 1][k][k2];
                if(k + (1 << (j - 1)) <= 2 * n){
                    update(W[i][j][k],W[i][j - 1][k + (1 << (j - 1))][0]);
                    update(W[i][j][k],W[i][j - 1][k + (1 << (j - 1))][1]);
                }
            }
        }
    }
    while(m--){
        int a,b;
        int l,r;
        scanf("%d%d",&a,&b);
        if(a <= b){
            r = a - 1 + n;
            l = b + 1;
        }else{
            r = a - 1;
            l = b + 1;
        }
        cout << query(l,r) << endl;
    }
    return 0;
}