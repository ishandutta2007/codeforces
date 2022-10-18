#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, a[MAXN], s[MAXN];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
        
    int r = 0;
    for(int i = n - 1; i >= 0; i--){
        if(i == n - 1){
            s[i] = 1;
            r = max(r, s[i]);
        }else{
            if(a[i] >= a[i + 1]){
                s[i] = 1;
                r = max(r, 1 + s[i + 1]);
            }else{
                s[i] = 1 + s[i + 1];
                
                if(s[i] == n - i){
                    r = max(r, s[i]);
                    continue;
                }else{
                    if(a[i + s[i]] - 1 > a[i + s[i] - 2]){
                        r = max(r, s[i] + s[i + s[i]]);
                    }else{
                        if((i + s[i] == n - 1) || (a[i + s[i] + 1] > a[i + s[i] - 1] + 1)){
                            r = max(r, s[i] + s[i + s[i]]);
                        }else r = max(r, s[i] + 1);
                    }
                }
            }
        }
    }
    
    printf("%d\n", r);
    
    return 0;
}