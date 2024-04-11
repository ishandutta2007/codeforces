#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int maxn = 1e5 + 5;
char s[maxn];
int n;
bool vis[maxn];
int main(){
    while(cin >> n){
        scanf("%s", s + 1);
        int m1 = (n - 11 + 1) / 2;
        int m2 = (n - 11) / 2;
        memset(vis, 0, sizeof(vis));
        for(int i = 1;i <= n;i++){
            if(s[i] == '8' && m2 > 0){
                vis[i] = true;
                m2--;
            }
            if(s[i] != '8' && m1 > 0){
                vis[i] = true;
                m1--;
            }
        }
        bool flag = false;
        for(int i = 1;i <= n;i++){
            if(!vis[i]){
                if(s[i] == '8')
                    flag = true;
                else
                    flag = false;
                break;
            }
        }
        if(flag)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}