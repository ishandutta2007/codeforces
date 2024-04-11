#include<bits/stdc++.h>
using namespace std;

int T , n , a[200];

int main(){
    scanf("%d" , &T); while(T--){
        scanf("%d" , &n);
        for(int i = 1; i <= n; i++) scanf("%d" , &a[i]);
        bool flag = true;
        for(int i = 2; i <= n; i++)
            if((a[i] & 1) != (a[1] & 1)) flag = false;
        flag ? puts("YES") : puts("NO");
    }
    return 0;
}