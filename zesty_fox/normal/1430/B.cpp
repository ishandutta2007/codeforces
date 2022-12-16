#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=200010;
int T,n,k;
ll a[N];
ll sum,ans;
int main(){
    cin>>T;
    while(T--){
        scanf("%d%d",&n,&k);
        sum=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        sort(a+1,a+n+1);
        for(int i=n-1;i>=max(1,n-k);i--){
            a[n]+=a[i];a[i]=0;
        }
        printf("%lld\n",a[n]);
    }
    return 0;
}