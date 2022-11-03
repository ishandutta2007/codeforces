#include <iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
const int maxn=3e5+50;
int a[maxn],sum[maxn];
int n,k;

bool Solve(int mid){
    sum[0]=1;
    int l=1,r=0;
    for (int i=1;i<=n;i++){
        while (l<=n && a[i]-a[l]>mid) l++;
        while (r+1<=n && i-r>=k) r++;
        if (r>=l && sum[r-1]-(l-2<0?0:sum[l-2])) sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1];
    }
    return sum[n]-sum[n-1];
}


int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=0,r=a[n]-a[1],ret=a[n]-a[1];
    Solve(20);
    while (l<=r){
        int mid=(l+r)>>1;
        if (Solve(mid)){
            ret=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ret<<endl;
}