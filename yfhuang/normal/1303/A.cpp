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

int t;
const int maxn = 105;
char s[maxn];

int main(){
    cin >> t;
    while(t--){
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int ans = 0;
        for(int i = 1;i <= n;i++){
            bool flag = true;
            for(int j = i;j <= n;j++){
                if(s[j] != '0')
                    flag = false;
                if(flag and s[i - 1] == '1' and s[j + 1] == '1'){
                    ans += j - i + 1;
                }
            } 
        }
        cout << ans << endl;
    }
    return 0;
}