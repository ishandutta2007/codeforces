#include<bits/stdc++.h>
using namespace std;
int n,m,c,x,a[1005];
void chk(int pos,int v,bool flag){
	int tmp=a[pos]; a[pos]=v;
	for (int i=2;i<=n;i++)
		if (a[i]<a[i-1]){
			a[pos]=tmp;
			return;
		}
	if (flag) printf("%d\n",pos);
	exit(0);
}
int main(){
	scanf("%d%d%d",&n,&m,&c);
	int Htop=1,Ttop=n;
	a[0]=0; a[n+1]=c;
	while (m--){
		scanf("%d",&x);
		if (Htop>Ttop){
			chk(Ttop,x,1);
			chk(Htop,x,1);
		}
		if (a[Htop-1]<=x&&x<=a[Ttop+1]&&Htop<=Ttop){
			if (x<=c/2)
				a[Htop]=x,printf("%d\n",Htop++);
			else a[Ttop]=x,printf("%d\n",Ttop--);
		}
		else if (x<a[Htop-1]){
			for (int j=Htop-1;;j--)
				if (a[j]<=x){
					a[j+1]=x;
					printf("%d\n",j+1);
					break;
				}
		}
		else{
			for (int j=Ttop+1;;j++)
				if (a[j]>=x){
					a[j-1]=x;
					printf("%d\n",j-1);
					break;
				}
		}
		if (Htop>Ttop) chk(1,a[1],0);
		//for (int i=1;i<=n;i++)
		//	printf("%d ",a[i]);
		//puts("");
		//printf("%d %d\n",Htop,Ttop);
		fflush(stdout);
	}
	puts("GG");
}