#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>

using namespace std;

int n, m;

const int maxn = 1e5 + 5;
char s[maxn];

int a[25][25];
int cnt[25];
int dp[(1 << 20) + 5];

int main(){
    cin >> n >> m;
    scanf("%s", s + 1);
    for(int i = 1;i < n;i++){
        cnt[s[i] - 'a']++;
        cnt[s[i + 1] - 'a']++;
    }
    for(int i = 1;i < n;i++){
        int id1 = s[i] - 'a';
        int id2 = s[i + 1] - 'a';
        if(id1 == id2){
            a[id1][id2]++;
        }
        else{
            a[id1][id2]++;
            a[id2][id1]++;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1;i < (1 << m);i++){
        for(int j = 0;j < m;j++){
            int sum = 0;
            int num = 1;
            if(!(i & (1 << j)))
                continue;
            for(int k = 0;k < m;k++){
                if(k == j){
                    continue;
                }
                if(i & (1 << k)){
                    sum += a[j][k];     
                    num++;
                }
            }
            //cout << i << " " << j << " " << sum << " " << cnt[j] << " " << a[j][j] << " " << num << endl;
            dp[i] = min(dp[i], dp[i ^ (1 << j)] + (sum - (cnt[j] - sum - 2 * a[j][j])) * num); 
        }
        //cout << dp[i] << endl;
    }
    cout << dp[(1 << m) - 1] << endl;
    return 0;
}