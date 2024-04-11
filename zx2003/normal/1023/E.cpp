#include<bits/stdc++.h>
const int N=5005;
int n,x,y,i,j;
char ans[N],*s=ans+1,*t,c[100];
int main(){
	scanf("%d",&n);
	t=ans+2*n-2;
	for(x=y=1;x+y<n+1;){
		printf("? %d %d %d %d\n",x,y+1,n,n);fflush(stdout);
		scanf("%s",c+1);
		if(c[1]=='Y')++y,*s++='R';else ++x,*s++='D';
	}
	for(x=y=n;x+y>n+1;){
		printf("? %d %d %d %d\n",1,1,x-1,y);fflush(stdout);
		scanf("%s",c+1);
		if(c[1]=='Y')--x,*t--='D';else --y,*t--='R';
	}
	printf("! %s\n",ans+1);fflush(stdout);
	return 0;
}