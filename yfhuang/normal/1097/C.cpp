#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 5e5 + 5;

char s[maxn];
int a[maxn];
int b[maxn];
int main(){
    int n;
    while(cin >> n){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        for(int i = 0;i < n;i++){
            scanf("%s", s);
            int len = strlen(s);
            int x = 0;
            for(int j = 0;j < len;j++){
                if(s[j] == '(')
                    x++;
                else{
                    x--;
                }
            }
            x = -x;
            bool flag = true;
            int now = 0;
            if(x > 0)
                now = x;
            for(int j = 0;j < len;j++){
                if(s[j] == '(')
                    now++;
                else{
                    now--;
                }
                if(now < 0)
                    flag = false;
            }
            if(flag){
                if(x >= 0)
                    a[x]++;
                else
                    b[-x]++;
            }
        }        
            int ans = 0;
            for(int i = 1;i < maxn;i++){
                ans += min(a[i], b[i]);
            }
            ans += a[0] / 2;
            cout << ans << endl;
    }
    return 0;
}