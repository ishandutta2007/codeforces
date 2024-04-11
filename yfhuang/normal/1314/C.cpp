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

const int maxn = 1005;

int lcp[maxn][maxn];
int n, m;
long long k;
char s[maxn];

typedef pair<int, int> pii;
typedef long long LL;
vector<pii> str;

bool cmp(pii a, pii b){
    int len = lcp[a.first][b.first];
    int len1 = a.second - a.first + 1;
    int len2 = b.second - b.first + 1;
    len = min(len, min(len1, len2));
    int ch1 = (len == len1 ? 0 : s[a.first + len]);
    int ch2 = (len == len2 ? 0 : s[b.first + len]);
    return ch1 < ch2;
}

LL dp[maxn][maxn];
const LL INF = 1e18 + 5;

bool check(pii p){
    memset(dp, 0, sizeof(dp));
    dp[n + 1][0] = 1;
    for(int i = n;i >= 1;i--){
        int right;
        if(cmp(make_pair(i, n), p)) right = n + 1;
        else{
            int len = lcp[p.first][i];
            len = min(len, p.second - p.first + 1);
            len = min(len, n - i + 1);
            if(len == p.second - p.first + 1) right = i + len - 1;
            else right = i + len;
        }
        for(int j = 1;j <= m;j++){
            dp[i][j] += dp[right + 1][j - 1];
        }
        if(i == 1){
            return (dp[1][m] >= k);
        }
        for(int j = 0;j <= m;j++){
            dp[i][j] += dp[i + 1][j];
            if(dp[i][j] >= INF){
                dp[i][j] = INF;
            }
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> k;
    scanf("%s", s + 1);
    for(int i = n;i >= 1;i--){
        for(int j = n;j >= 1;j--){
            lcp[i][j] = (s[i] == s[j] ? lcp[i + 1][j + 1] + 1 : 0);
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            str.emplace_back(i, j);
        }
    } 
    sort(str.begin(), str.end(), cmp);
    //for(auto it : str){
    //    cout << it.first << " " << it.second << endl;
    //}
    int l = 0, r = str.size() - 1;
    while(l < r){
        int mid = (l + r + 1) / 2;
        if(check(str[mid])){
            l = mid;
        }else{
            r = mid - 1;
        }
    }
    for(int i = str[l].first;i <= str[r].second;i++){
        putchar(s[i]);
    }
    cout << endl;
    return 0;
}