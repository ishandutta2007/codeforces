#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
int T,n,m,a[105];
ll sum;
int main(){
    cin>>T;
    while(T--){
        sum=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
        puts(sum==m?"YES":"NO");
    }
    return 0;
}