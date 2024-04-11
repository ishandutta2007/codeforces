#include<bits/stdc++.h>
#define N 8005
using namespace std;
int d[N][N],f[N];
int sum[N],b[N];
char s[N];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=n;i;i--)
		for (int j=n;j;j--)
			d[i][j]=((s[i]==s[j])?d[i+1][j+1]+1:0);
	memset(f,60,sizeof(f));
	f[0]=0;
	for (int i=1;i<=n;i++)
		sum[i]=sum[i/10]+1;
	for (int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for (int j=i;j<=n;j++){
			if (b[j]) continue;
			int l=j-i+1,times=0,p=i;
			for (;d[i][p]>=l;){
				p+=l; times++;
				b[p-1]=1;
				f[p-1]=min(f[p-1],f[i-1]+l+sum[times]);
			}
		}
	}
	printf("%d",f[n]);
}