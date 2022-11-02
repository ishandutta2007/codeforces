#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#define long long long
#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)

const int N = 16;
const int M = 10000;
const int DP = 1 << N; // sizeof dp[*][][] , which means if(bit[x])==1 , then row_x has been used
const int INF = 0x3f3f3f3f; // infinity
int matrix[N][M]; // the given matrix
int dir[N][N]; // min delta in rows
int dic[N][N]; // min delta in row&nextRow
int dp[DP][N][N]; // dp[ row_xHasUsed?(bit[x])=1:(bit[x])=0 ][ firstRow ][ dealingRow ]
int n; // num rows
int m; // num columns

void init(){
    //scan
    cin >> n >> m;
    rep (i,n) rep (j,m) cin >> matrix[i][j];
    //init_dp , as -1 means unknow , otherwise , the answer
    memset(dp,-1,sizeof(dp));
}

void pretreat(){ // pretreatment for dir[][] & dic[][]
    rep(i,n) rep(j,n){
        int mn = INF; // deal with dir
        rep (k,m) mn = min(mn , abs(matrix[i][k] - matrix[j][k]));
        dir[i][j] = mn;
        mn = INF; // deal with dic
        rep (k,m - 1) mn = min(mn , abs(matrix[i][k] - matrix[j][k + 1]));
        dic[i][j] = mn;
    }
}

int dfs(int s,int fr,int dr){ // same meaning as dp[][][]
    if (s == ((1 << n) - 1)) return dic[dr][fr]; // already deat with all
    if (dp[s][fr][dr] != -1) return dp[s][fr][dr]; // already known the ans
    int res = 0;
    rep (i,n){ // as i means the next choise
        int tmp = 1 << i; // bit[i] in s
        if (s & tmp) continue; // have chosen
        res = max(res, min(dfs(s | tmp,fr,i) , dir[dr][i]) ); 
    }
    return dp[s][fr][dr] = res;
}

int main(){
    init();
    pretreat();
    int ans = 0;
    rep (i,n) { // index the first row
        ans = max(ans,dfs( 1 << i , i , i ));
    }
    cout << ans << endl;
    return 0;
}