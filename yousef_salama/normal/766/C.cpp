#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int n, an[26], cnt[1005], A[1005], B[1005];
char s[1005];

int main(){
    scanf("%d %s", &n, s);
    for(int i = 0; i < 26; i++)
        scanf("%d", &an[i]);
        
    for(int i = n; i >= 0; i--){
        if(i == n){
            cnt[i] = 1;
            A[i] = 0;
            B[i] = 0;
        }else{
            cnt[i] = 0, A[i] = 0, B[i] = 1 << 29;
            
            int mask = 0;
            for(int j = i; j < n; j++){
                mask |= (1 << (s[j] - 'a'));
                
                bool ok = true;
                for(int c = 0; c < 26; c++)if(mask & (1 << c)){
                    if((j - i + 1) > an[c])ok = false;
                }
                if(!ok)break;
                
                cnt[i] = (cnt[i] + cnt[j + 1]) % MOD;
                A[i] = max(A[i], max(j - i + 1, A[j + 1]));
                B[i] = min(B[i], 1 + B[j + 1]);
            }
        }
    }
    
    printf("%d\n%d\n%d\n", cnt[0], A[0], B[0]);
    
    return 0;
}