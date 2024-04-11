#include<bits/stdc++.h>
#define db double
using namespace std;
int n,k,f[44][44],num[44],st[44],tot,mx;
db ans;

int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		num[i]=i;
		for (int j=1;j<=n;j++){
			scanf("%d",&f[i][j]);
		}
	}
	for (int fl;clock()<=1988;){
		random_shuffle(num+1,num+n+1);
		st[tot=1]=num[1];
		for (int i=2;i<=n;i++){
			fl=1;
			for (int j=1;j<=tot;j++){
				if (!f[num[i]][st[j]]){
					fl=0;
					break;
				}
			}
			if (fl){
				st[++tot]=num[i];
			}
		}
		mx=max(mx,tot);
	}
	ans=(db)mx*(mx-1)/2*((db)k/mx)*((db)k/mx);
	printf("%.10lf\n",ans);
}