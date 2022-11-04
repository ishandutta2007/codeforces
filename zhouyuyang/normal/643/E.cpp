#include<bits/stdc++.h>
using namespace std;
double f[500005][62];
int tot=1,fa[500005];
int q[233];
int main(){
	for (int i=0;i<=60;i++)
		f[1][i]=1;
	int Q;
	scanf("%d",&Q);
	while (Q--){
		int fl,x;
		scanf("%d%d",&fl,&x);
		if (fl==1){
			fa[++tot]=x;
			int D=0; q[0]=tot;
			for (;D<60&&q[D]>1;)
				q[D+1]=fa[q[D]],D++;
			for (int i=D;i>1;i--)
				f[q[i]][i-1]/=0.5+f[q[i-1]][i-2]/2;
			for (int i=0;i<=60;i++)
				f[tot][i]=1;
			f[q[1]][0]/=2;
			for (int i=2;i<=D;i++)
				f[q[i]][i-1]*=0.5+f[q[i-1]][i-2]/2;
		}
		else{
			double ans=f[x][60]*60;
			for (int i=0;i<60;i++)
				ans-=f[x][i];
			printf("%.15lf\n",ans);
		}
	}
}