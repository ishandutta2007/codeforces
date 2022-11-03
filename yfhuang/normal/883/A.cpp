#include <iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
using namespace std;
const int maxn=1e5+50;

long long n,a,d,t[maxn];
int m;

long long get(long long ia,long long num,long long t){
    if (t==-1) return (n-ia+1-1)/num+1;
    long long x=(t/a-ia)/num;
    long long x0=x-2,x1=x-1,x2=x+1,x3=x+2;
    if ((ia+x0*num)*a>t) return x0;
    if ((ia+x1*num)*a>t) return x1;
    if ((ia+x*num)*a>t) return x;
    if ((ia+x2*num)*a>t) return x2;
    return x3;
}

int main(){
    scanf("%lld%d%lld%lld",&n,&m,&a,&d);
    for (int i=1;i<=m;i++) scanf("%lld",&t[i]);
    long long ia=1;
    long long it=1;
    long long ans=0;
    t[m+1]=-1;
    while (ia<=n || it<=m){
        if (ia>n || (it<=m && t[it]<=a*ia)){
            ia=(t[it]+d)/a+1;
            int j=upper_bound(t+1,t+m+1,t[it]+d)-t;
            it=j;
            ans++;
        }
        else{
            long long num=d/a+1;
            long long x=get(ia,num,t[it]);
            long long ia2=ia+x*num;
            if (ia2>n){
                x=(n-ia+1-1)/num+1;
                ia2=n+1;
            }
            ans+=x;
            int j=upper_bound(t+1, t+m+1, (ia+(x-1)*num)*a+d)-t;
            it=j;
            ia=ia2;
        }
    }
    cout<<ans<<endl;

    return 0;
}