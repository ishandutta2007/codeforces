#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int T,n,a[105];
int main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
            for(int i=1;i<=n;i+=2){
                printf("%d %d ",a[i+1],-a[i]);
            }
            puts("");
    }
    return 0;
}