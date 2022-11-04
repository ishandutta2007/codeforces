#include<bits/stdc++.h>
#define N 1005
using namespace std;
char a[N],b[N][N];
int f[N][N],len[N];
int cal[N],cost[15];
pair<int,int> lab[N];
int ml[N],val[N];
int main(){
	int mx=1002;
	scanf("%s",a);
	int m=strlen(a);
	reverse(a,a+m);
	for (int i=m;i<=mx;i++)
		a[i]='0';
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s",b[i]);
		int l=strlen(b[i]);
		reverse(b[i],b[i]+l);
		for (int j=l;j<=mx;j++)
			b[i][j]='0';
		len[i]=l;
	}
	for (int i=0;i<10;i++)
		scanf("%d",&cost[i]);
	memset(f,233,sizeof(f));
	f[0][0]=0;
	for (int i=0;i<n;i++)
		lab[i]=make_pair(0,i);
	for (int i=0;i<=mx;i++){
		int l=0,r=9;
		if (i==m-1) l=1;
		if (a[i]!='?') l=r=a[i]-'0';
		for (int j=0;j<n;j++){
			val[j]=b[lab[j].second][i]-'0';
			ml[j]=max(m,len[lab[j].second]);
		}
		for (int k=l;k<=r;k++){
			int c2=0,d2=0;
			for (int j=0;j<n;j++){
				c2+=((val[j]+k)>=10);
				if ((val[j]+k)||(i<ml[j]))
					d2+=cost[(val[j]+k)%10];
			}
			for (int j=0;j<=n;j++){
				f[i+1][c2]=max(f[i+1][c2],f[i][j]+d2);
				if (j>=n) continue;
				c2-=(val[j]+k>=10);
				c2+=(val[j]+k+1>=10);
				if ((val[j]+k)||(i<ml[j]))
					d2-=cost[(val[j]+k)%10];
				d2+=cost[(val[j]+k+1)%10];
			}
		}
		for (int j=0;j<n;j++)
			lab[j].first=val[j]*(n+1)+n-j;
		sort(lab,lab+n);
		reverse(lab,lab+n);
	}
	printf("%d",f[mx+1][0]);
}