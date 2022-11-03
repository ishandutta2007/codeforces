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

const int maxn = 2e5 + 5;

int q;

int l, r;
int n;
string s, t;
int pre[maxn][30];
int eq[maxn];
int main(){
    memset(pre, 0, sizeof(pre));
    cin >> s;
    n = s.length();
    t = s;
    reverse(t.begin(), t.end());
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < 26;j++){
            pre[i][j] = pre[i - 1][j];
        }
        pre[i][s[i - 1] - 'a']++;
    }
    cin >> q;
    for(int i = 1;i <= q;i++){
        scanf("%d%d", &l, &r);
        if(l == r){
            printf("Yes\n");
        }else{
            int cnt = 0;
            for(int j = 0;j < 26;j++){
                if(pre[r][j] - pre[l - 1][j] > 0){
                    cnt++;
                }
            }
            if(cnt > 2){
                printf("Yes\n");
            }else if(cnt == 1){
                printf("No\n");
            }else{
                if(s[l - 1] == s[r - 1]){
                    printf("No\n");
                }else{
                    printf("Yes\n");
                }
            }
        }
    }
    return 0;
}