#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T,a[55],b[55],n,x;
int main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        sort(a+1,a+n+1);sort(b+1,b+n+1);reverse(b+1,b+n+1);
        for(int i=1;i<=n;i++) 
            if(a[i]+b[i]>x){
                puts("No");
                goto nxt;
            }
        puts("Yes");
        nxt:;
    }
    return 0;
}