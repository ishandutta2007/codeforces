#include<stdio.h>
using namespace std;
int n,m,p,i,S;
double ans;
int a[1005];
int main() {
    scanf("%d%d%d",&n,&m,&p);
    for (i=1;i<=m;i++) scanf("%d",&a[i]),S+=a[i];
    if (S<n) return printf("-1\n"),0;
    a[p]--;
    S--;
    n--;
    ans=1.0;
    for (i=1;i<=a[p];i++) 
    ans=ans*(S-a[p]-n+i)*1./(S-a[p]+i)*1.;
    printf("%.7lf\n",1-ans);
}