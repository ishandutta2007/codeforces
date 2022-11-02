#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 500000 + 5;
char s[maxn], t[maxn];
int f[maxn];
int cnt[2];
int cnt1[2];
char a[maxn];
int main(){
    while(scanf("%s", t + 1) != EOF){
        scanf("%s", s + 1);
        f[0] = 0;
        f[1] = 0;
        int len = 0;
        int n = strlen(s + 1);
        for(int i = 2;i <= n;i++){
            while(len > 0 && s[len + 1] != s[i]){
                len = f[len];
            }
            if(s[len + 1] == s[i]){
                len++;
            }
            f[i] = len;
        }
        int x = f[n];
        int m = strlen(t + 1);
        memset(cnt, 0, sizeof(cnt)); 
        memset(cnt1, 0, sizeof(cnt1));
        for(int i = 1;i <= m;i++){
            cnt[t[i] - '0']++;
        }
        for(int i = 1;i <= n;i++){
            cnt1[s[i] - '0']++;
        }
        if((cnt1[0] > cnt[0]) || (cnt1[1] > cnt[1])){
            printf("%s", t + 1);
        }else{
            for(int i = 1;i <= n;i++){
                a[i] = s[i];
            }
            cnt[0] -= cnt1[0];
            cnt[1] -= cnt1[1];
            for(int i = n + 1;i <= m;i++){
                int pos = (i - n - 1) % (n - x) + 1;
                if(cnt[s[f[n] + pos] - '0'] > 0){
                    a[i] = s[f[n] + pos];
                    cnt[s[f[n] + pos] - '0']--;
                }else{
                    int another = 1 ^ (s[f[n] + pos] - '0');
                    a[i] = (char)('0' + another);
                    cnt[another]--;
                }
            }
            a[m + 1] = 0;
            printf("%s", a + 1);
        } 
    }
    return 0;
}