#include <stdio.h>
#include <algorithm>
using namespace std;
int n, x;
int m=0;
int a[100001];
int b[100001];
int cnt[100001];
int bs(int l, int r, int x){
    while(l<=r){
        int m=(l+r)/2;
        if(b[m]==x) return m;
        if(b[m]>x) r=m-1;
        else l=m+1;
    }
    return 0;
}
int main(){
    scanf("%i%i", &n, &x);
    for(int i=1; i<=n; i++)
        scanf("%i", &a[i]);
    sort(a+1, a+n+1);
    a[0]=a[1]-1;
    for(int i=1; i<=n; i++){
        if(a[i]==a[i-1])
            cnt[m]++;
        else{
            m++;
            b[m]=a[i];
            cnt[m]=1;
        }
    }
    int temp;
    long long res=0;
    for(int i=1; i<=m; i++){
        temp=x^b[i];
        if(temp==b[i]) res+=(long long)(cnt[i])*(cnt[i]-1);
        else if(temp=bs(1, m, temp))
            res+=(long long)(cnt[i])*cnt[temp];
    }
    res>>=1;
    printf("%I64d", res);
}