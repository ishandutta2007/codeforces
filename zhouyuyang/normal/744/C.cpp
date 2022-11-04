#include<bits/stdc++.h>
using namespace std;
char ch[5];
int n,r[20],b[20],tg[20];
int sum[65540],cnt[65540];
int ans,f[65540][125];
int cntr,cntb;
void mx(int &x,int y){
	x<y?x=y:0;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%s%d%d",ch,&r[i],&b[i]);
		if (ch[0]=='R') tg[i]=1;
		cntr+=r[i]; cntb+=b[i];
	}
	for (int i=0;i<1<<n;i++)
		for (int j=0;j<n;j++)
			if (i&(1<<j)) sum[i]+=tg[j];
	for (int i=0;i<1<<n;i++) cnt[i]=cnt[i/2]+(i&1);
	memset(f,233,sizeof(f));
	f[0][0]=0;
	for (int i=0;i<1<<n;i++){
		int R=sum[i],B=cnt[i]-R;
		for (int j=0;j<=122;j++)
			if (f[i][j]>=0)
				for (int k=0;k<n;k++)
					if (!(i&(1<<k)))
						mx(f[i|(1<<k)][j+min(R,r[k])],
						   f[i][j]+min(B,b[k]));
	}
	ans=1e9;
	for (int j=0;j<=122;j++)
		ans=min(ans,max(cntr-j,cntb-f[(1<<n)-1][j]));
	printf("%d",ans+n);
}