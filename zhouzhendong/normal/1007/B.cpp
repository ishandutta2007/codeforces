#include <bits/stdc++.h>
using namespace std;
const int N=100005,M=600;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x;
}
int v[3],Fac[M],fcnt,cnt[8];
int d[8]={0,1,1,2,1,2,2,3};
void Get(int x){
	for (int i=1;i*i<=x;i++)
		if (x%i==0)
			Fac[++fcnt]=i,Fac[++fcnt]=x/i;
}
int calc(int v){
	return v*(v-1)*(v-2)/6+v*(v-1)+v;
}
int main(){
	for (int T=read();T--;){
		fcnt=0;
		for (int i=0;i<3;i++)
			Get(v[i]=read());
		sort(Fac+1,Fac+fcnt+1);
		fcnt=unique(Fac+1,Fac+fcnt+1)-Fac-1;
		memset(cnt,0,sizeof cnt);
		for (int i=1,val;i<=fcnt;i++){
			for (int j=val=0;j<3;j++)
				if (v[j]%Fac[i]==0)
					val|=1<<j;
			cnt[val]++;
		}
		int ans=calc(cnt[7]);
		for (int i=1;i<8;i++)
			for (int j=i+1;j<8;j++)
				if (d[i|j]>=2)
					for (int k=j+1;k<8;k++)
						if (!(d[i|k]<2||d[j|k]<2||(i|j|k)!=7))
							ans+=cnt[i]*cnt[j]*cnt[k];
		for (int i=1;i<8;i++)
			if (d[i]>=2)
				for (int j=1;j<8;j++)
					if (!((i|j)!=7||i==j))
						ans+=cnt[i]*(cnt[i]+1)/2*cnt[j];
		printf("%d\n",ans);
	}
	return 0;
}