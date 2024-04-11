#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 1e3 + 6;
const int MAX_M = 2e3 + 6;

bool dp[MAX_N][MAX_M];

int f(int val) {
    return val+MAX_M/3;
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    s="D"+s;
    dp[0][f(0)] = 1;
    bool get_ans=false;
    int last_k;
    for (int i=1;n>=i;i++) {
        for (int j=f(-k);f(k)>=j;j++) {
            if (i!=n && (j==f(-k) || j==f(k))) continue;
            if (s[i]=='W') dp[i][j] = dp[i-1][j-1];
            if (s[i]=='L') dp[i][j] = dp[i-1][j+1];
            if (s[i]=='D') dp[i][j] = dp[i-1][j];
            if (s[i]=='?') {
                dp[i][j] = dp[i-1][j-1] | dp[i-1][j] | dp[i-1][j+1];
            }
            if (i==n && (j==f(-k) || j==f(k))) get_ans |= dp[i][j];
            if (i==n && dp[i][j] && (j==f(-k)||j==f(k))) last_k = j;
        }
    }
    if (!get_ans) {
        cout<<"NO"<<endl;
        return 0;
    }
    string ans=s;
    for (int i=n;i>=1;i--) {
        if (s[i]!='?') {
            if (s[i]=='W') last_k--;
            else if (s[i]=='L') last_k++;
        }
        else {
            if (dp[i-1][last_k]) ans[i]='D';
            else if (dp[i-1][last_k+1]) ans[i]='L',last_k++;
            else if (dp[i-1][last_k-1]) ans[i]='W',last_k--;
        }
    }
    for (int i=1;n>=i;i++) cout<<ans[i];
    cout<<endl;
}