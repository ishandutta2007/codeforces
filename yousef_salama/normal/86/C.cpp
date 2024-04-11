#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
#define MOD 1000000009
using namespace std;
int n, m, dp[2][1005][105], best_prefix[105][4], best[105][4];
string s[15], alph = "ACGT";
vector <string> v;
int main(){
    ios_base::sync_with_stdio(false);
    
    cin >> n >> m;
    
    v.push_back("");
    for(int i = 0; i < m; i++){
        cin >> s[i];
        
        string a = "";
        for(int j = 0; j < s[i].size(); j++){
            a += s[i][j];
            v.push_back(a);
        }
    }
    for(int i = 0; i < v.size(); i++)
    for(int c = 0; c < 4; c++){
        string cur = v[i];
        cur += alph[c];
        
        for(int j = 0; j < v.size(); j++){
            if(v[j].size() <= cur.size()){
                if(cur.substr(cur.size() - v[j].size()) == v[j]){
                    if(v[best_prefix[i][c]].size() < v[j].size()){
                        best_prefix[i][c] = j;
                    }
                }
            }
        }
        
        for(int j = 0; j < m; j++){
            if(s[j].size() <= cur.size()){
                if(cur.substr(cur.size() - s[j].size()) == s[j]){
                    if(best[i][c] < s[j].size()){
                        best[i][c] = s[j].size();
                    }
                }
            }
        }
    }
    for(int k = 0; k < v.size(); k++)
        dp[n & 1][n][k] = 1;
    for(int i = n - 1; i >= 0; i--)
    for(int covered = 0; covered <= i; covered++)
    for(int k = 0; k < v.size(); k++){
        dp[i & 1][covered][k] = 0;
        for(int c = 0; c < 4; c++){
            int nk = best_prefix[k][c];
            int ncovered = (i + 1) - best[k][c] <= covered ? i + 1 : covered;
            
            dp[i & 1][covered][k] += dp[(i + 1) & 1][ncovered][nk];
            dp[i & 1][covered][k] %= MOD;
        }
    }
    printf("%d\n", dp[0][0][0]);
    return 0;
}