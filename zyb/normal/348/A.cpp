#include<stdio.h>
#include<algorithm>
#define N 100005
using namespace std;
long long n,i,s,gt,ans,a[N];
int main() {
    scanf("%I64d",&n);
    for (i=1;i<=n;i++) scanf("%I64d",&a[i]),gt=max(gt,a[i]);
    for(i=1;i<=n;i++) s+=(gt-a[i]); 
    if(s>=gt) ans=gt;  
    else{  
        ans=gt-s;  
        if(ans%(n-1)==0) ans=gt+ans/(n-1);  
        else ans=gt+ans/(n-1)+1;  
    }  
    printf("%I64d\n",ans);    
}