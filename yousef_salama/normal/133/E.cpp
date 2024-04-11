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
#define Trvi(it, taxis) for(__typeof(taxis.begin()) it = taxis.begin(); it != taxis.end(); ++it)
#define MAX 1000000000000000LL
using namespace std;
string comm;
int N, dp[105][55][105][2];
int dfs(int idx, int rem, int pos, int type){
    if(idx == comm.size()){
        if(rem == 0 || !(rem & 1))return abs(pos);
        else return 0;
    }
    if(dp[idx][rem][pos][type] != -1)return dp[idx][rem][pos][type];
    int ans = dfs(idx + 1, rem, (comm[idx] == 'F'? (pos + (type == 0?1:-1)):pos), (comm[idx] == 'T'? type ^ 1: type));
    if(rem > 0){
        ans = max(ans, dfs(idx + 1, rem - (comm[idx] == 'T'), (pos + (type == 0?1:-1) ), type));
        ans = max(ans, dfs(idx + 1, rem - (comm[idx] == 'F'), pos, type ^ 1));
    }
    return dp[idx][rem][pos][type] = ans;
}
int main(){
    cin >> comm >> N;
    memset(dp, -1, sizeof dp);
    cout << dfs(0, N, 0, 0) << endl;
    return 0;
}