#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> par;
int n,a[40],d[100],tp,s[100][100];
bitset<5000>dp[70][40];
par f[100];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	dp[1][1][a[1]]=1;
	for(int i=1;i<=64;++i){
		if(dp[i][n][0]){
			printf("%d\n",i);
			int lst=n,lst2=0;
			for(int j=i-1;j>=1;--j){
//				printf("[%d,%d,%d]\n",j,lst,lst2);
				if(dp[j][lst][lst2+j-a[lst]])
					d[++tp]=a[lst],lst2+=j-a[lst];
				else if(lst>1&&dp[j][lst-1][lst2+j-a[lst]])
					d[++tp]=a[lst],lst2+=j-a[lst],lst--;
			}
			d[++tp]=a[lst];
//			printf("[%d,%d]",lst,lst2);
			for(int i=1;i<=tp;++i)
				f[i]=par(d[i],i);//,printf("[%d]",d[i]);
			for(int i=tp;i>=1;--i){
				sort(f+1,f+i+1);
//				printf("[%d,%d]\n",f[1].first,f[1].second);
				for(int j=2;j<=i;++j){
					if(f[1].first)s[f[1].second][f[j].second]++,f[1].first--;
					else if(f[j].first)s[f[j].second][f[1].second]++,f[j].first--;
				}
				swap(f[1],f[i]);
			}
			for(int i=1;i<=tp;++i,puts(""))
				for(int j=1;j<=tp;++j)
					printf("%d",s[i][j]);
			return 0;
		}
		for(int j=1;j<=n;++j){
//			for(int k=0;k<=10;++k)if(dp[i][j][k])printf("[%d,%d,%d]\n",i,j,k);
			if(a[j]>=i)dp[i+1][j]|=(dp[i][j]<<(a[j]-(i)));
			else dp[i+1][j]|=(dp[i][j]>>(i-a[j]));
			if(j<n&&a[j+1]>=i)dp[i+1][j+1]|=(dp[i][j]<<(a[j+1]-(i)));
			else if(j<n)dp[i+1][j+1]|=(dp[i][j]>>(i-a[j+1]));
		}
	}
	puts("-1");
	return 0;
}