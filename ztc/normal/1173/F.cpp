#include<stdio.h>
int a[100002][2],n,q[100002][4],tot=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i][0]);
	for(int i=1;i<=n;i++)scanf("%d",&a[i][1]);
	for(int i=n;i>=1;i--){
		if(a[i][0]==i&&a[i][1]==i)continue;
		tot++;
		q[tot][0]=q[tot][3]=i;
		q[tot][1]=a[i][1];
		q[tot][2]=a[i][0];
		for(int j=1;j<i;j++){
			if(a[j][0]==i)a[j][0]=a[i][0];
			if(a[j][1]==i)a[j][1]=a[i][1];
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)printf("%d %d %d %d\n",q[i][0],q[i][1],q[i][2],q[i][3]);
}