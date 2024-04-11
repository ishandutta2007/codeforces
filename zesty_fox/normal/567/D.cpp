#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=200010;
int n,k,a,m,g[N],cpy[N];
inline bool check(int lim){
    int cnt=0;
    for(int i=1;i<=lim;i++) cpy[i]=g[i];
    sort(cpy+1,cpy+lim+1);
    for(int i=1;i<=lim;i++) cnt+=(int)((cpy[i]-cpy[i-1])/(a+1));
    cnt+=((n-cpy[lim]+1)/(a+1));
    return cnt>=k;
}

inline int ef(){
    int l=0,r=m+1;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    return l;
}

int main(){
    cin>>n>>k>>a>>m;
    for(int i=1;i<=m;i++) scanf("%d",&g[i]);
    int tmp=ef();
    if(tmp==m+1) puts("-1");
    else printf("%d\n",tmp);
    return 0;
}