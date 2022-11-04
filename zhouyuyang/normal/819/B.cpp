#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
#define N 1000005
using namespace std;
int a[N],n,p,id;
ll sum,c[N],ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++){
		sum+=abs(a[i]-i);
		p=a[i];
		if (p>=i){
			c[0]--; c[p-i+1]++;
			c[p-i+1]++; c[n-i+1]--;
			c[n-i+1]-=abs(n-a[i])-abs(1-a[i]);
			c[n-i+2]+=abs(n-a[i])-abs(1-a[i]);
			c[n-i+2]--;
		}
		else{
			c[0]++; c[n-i+1]--;
			c[n-i+1]-=abs(n-a[i])-abs(1-a[i]);
			c[n-i+2]+=abs(n-a[i])-abs(1-a[i]);
			c[n-i+2]--; c[p+n-i+1]++;
			c[p+n-i+1]++;
		}
	}
	for (int i=1;i<=n;i++) c[i]+=c[i-1];
	ans=sum; id=0;
	for (int i=1;i<n;i++){
		sum+=c[i];
		if (sum<ans) ans=sum,id=i;
	}
	printf("%lld %d",ans,id);
}