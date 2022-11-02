#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 2e5 + 5;
char s[maxn];
int n;
int main(){
    while(cin >> n){
        scanf("%s", s + 1);
        if(n & 1){
            puts("No");
        }else{
            int p1 = 0, p2 = 0;
            for(int i = 1;i <= n;i++){
                if(s[i] == ')'){
                    p1 = i;
                    break;
                }
            }
            for(int i = n;i >= 1;i--){
                if(s[i] == '('){
                    p2 = i;
                    break;
                }
            }
            if(p1 != 0){
                for(int i = p1;i < n;i++){
                    s[i] = s[i + 1];
                }
                s[n] = ')';
            }
            int cnt = 0;
            bool flag = true;
            for(int i = 1;i <= n;i++){
                if(s[i] == '(')
                    cnt++;
                else
                    cnt--;
                if(cnt < 0)
                    flag = false;
            }
            if(cnt != 0)
                flag = false;
            if(flag)
                puts("Yes");
            else
                puts("No");
        }
    }
    return 0;
}