#include<bits/stdc++.h>
using namespace std;
 
int n,a[4],b[4];

int main() 
{
    scanf("%d", &n);
    for(int i=1;i<=3;i++) 
		scanf("%d",&a[i]);
    for(int i=1;i<=3;i++)
		scanf("%d",&b[i]);
    int ans1=max({0,a[1]-b[1]-b[3],a[2]-b[2]-b[1],a[3]-b[3]-b[2]});
    int ans2=min(a[1],b[2])+min(a[2],b[3])+min(a[3],b[1]);
    printf("%d %d\n",ans1,ans2);
}