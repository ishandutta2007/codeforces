#include<bits/stdc++.h>
using namespace std;
int n,m,fl;
int a[10005],b[10005];
int ask(int x,int y){
	printf("0 %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&x);
	return x;
}
int main(){
	srand(time(NULL));
	int now=-1e8;
	int last=0;
	for (int i=1;i<=8;i++)
		last=last*10+rand()%10;
	if (rand()&1) last=-last;
	for (;now<=1e8;){
		int x=ask(now,now);
		if (!x){
			if (now>-1e8){
				if (!ask(last,now)) b[++m]=now;
				if (!ask(now,last)) a[++n]=now;
			}
			else
				fl=1;
			if (now+1000<=1e8){
				x=ask(now+1000,now+1000);
				if (x!=1000) now++;
				else now+=1000;
			}
			else now++;
		}
		else now+=x;
	}
	if (fl){
		if (!ask(last,-1e8)) b[++m]=-1e8;
		if (!ask(-1e8,last)) a[++n]=-1e8;
	}
	printf("1 %d %d\n",n,m);
	for (int i=1;i<=n;i++) printf("%d ",a[i]);
	for (int i=1;i<=m;i++) printf("%d ",b[i]);
}