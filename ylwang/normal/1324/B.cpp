#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;

int T , n , a[N] , cnt[N] , flag;

int main(){
    scanf("%d" , &T); while(T--){
        scanf("%d" , &n) , flag = false;
        for(int i = 1; i <= n; i++)
            scanf("%d" , &a[i]) , cnt[i] = 0;
        for(int i = 1; i <= n; i++){
            if(cnt[a[i]] == 1 && a[i - 1] != a[i]) flag = true;
            else if(cnt[a[i]] > 1) flag = true;
            cnt[a[i]]++;
        }
        flag ? puts("YES") : puts("NO");
    }
    return 0;
}