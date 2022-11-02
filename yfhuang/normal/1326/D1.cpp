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
#include <random>
#include <chrono>
using namespace std;

const int maxn = 1e6 + 5;

char s[maxn];
char s_new[maxn * 2];
int p[maxn * 2];

int L[maxn * 2], R[maxn * 2];

int Init()
{
    int len = strlen(s);
    s_new[0] = '$';
    s_new[1] = '#';
    int j = 2;

    for (int i = 0; i < len; i++)
    {
        s_new[j++] = s[i];
        s_new[j++] = '#';
    }

    s_new[j] = '\0'; 
    
    return j; 
}

int x1, x2;

int Manacher()
{
    int len = Init(); 
    int max_len = -1; 

    int id;
    int mx = 0;
    for(int i = 1;i < len;i++){
        L[i] = -1;
        R[i] = len + 1;
    }

    for (int i = 1; i < len; i++)
    {
        if (i < mx)
            p[i] = min(p[2 * id - i], mx - i); 
        else
            p[i] = 1;

        while (s_new[i - p[i]] == s_new[i + p[i]])  
            p[i]++;

        if (mx < i + p[i])
        {
            id = i;
            mx = i + p[i];
        }

        max_len = max(max_len, p[i] - 1);
    }
    if(max_len == len / 2 - 1)
        return max_len;
    for(int i = 1;i < len;i++){
        if(i <= len / 2){
            int x = i - p[i] + 1;
            L[x] = max(L[x], i);
        }else{
            int x = i + p[i] - 1;
            R[x] = min(R[x], i);
        }
    }
    int ll = -1, rr = len + 1;
    int len1 = 0;
    int ans = 0;
    for(int i = 1, j = len - 1;i < j;i++, j--){
        ll = max(ll, L[i]);
        rr = min(rr, R[j]);
        if(s_new[i] != '#'){
            if(s_new[i] == s_new[j]){
                len1++;
            }else{
                break;
            }
        }else{
            if(len1 * 2 + max(ll - i, j - rr) > ans){
                ans = len1 * 2 + max(ll - i, j - rr);
                x1 = len1;
                if(ll - i > j - rr){
                    x2 = ll - i;
                }else{
                    x2 = rr - j;
                }
            }
        }
    }
    return ans;
}

int n;

int main(){
    int t;
    cin >> t;
    while(t--){
        scanf("%s", s);
        n = strlen(s);
        int ans = Manacher();
        if(ans == n){
            printf("%s\n", s);
        }else{
            //cout << ans << endl;
            for(int i = 0;i < x1;i++){
                putchar(s[i]);
            }
            int l, r;
            if(x2 >= 0){
                l = x1, r = x1 + x2 - 1;
            }else{
                x2 = -x2;
                l = n - x1 - x2;
                r = l + x2 - 1;
            }
            for(int i = l;i <= r;i++){
                putchar(s[i]);
            }
            for(int i = n - x1;i < n;i++){
                putchar(s[i]);
            }
            puts("");
        }
    }
    return 0;
}