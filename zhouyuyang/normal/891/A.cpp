#include<bits/stdc++.h>
using namespace std;
int n,t,ans,fl;
int a[2005];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (i==1) t=a[i];
		else t=gcd(t,a[i]);
		if (a[i]==1) fl=1;
	}
	if (t!=1){
		puts("-1");
		return 0;
	}
	if (fl){
		ans=0;
		for (int i=1;i<=n;i++)
			if (a[i]!=1) ans++;
		printf("%d\n",ans);
		return 0;
	}
	ans=1e9;
	for (int i=1;i<=n;i++){
		int tmp=a[i];
		for (int j=i+1;j<=n;j++){
			tmp=gcd(tmp,a[j]);
			if (tmp==1){
				ans=min(ans,n-1+(j-i));
				break;
			}
		}
	}
	printf("%d\n",ans);
}