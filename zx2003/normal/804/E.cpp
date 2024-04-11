#include<bits/stdc++.h>
int n,m,i,j,k,l;
inline void out(int a,int b,int d){
	for(int i=0;i<4;++i)printf("%d %d\n",a+i,b+(i+d)%4);
}
int main(){
	scanf("%d",&n);
	if(n==1)return puts("YES"),0;
	if(n%4==2 || n%4==3)return puts("NO"),0;
	m=n/4;
	puts("YES");
	for(i=1;i<m;++i)for(j=i+1;j<=m;++j){
		out(i*4-3,j*4-3,0);
		out(i*4-3,j*4-3,1);
		out(i*4-3,j*4-3,3);
		out(i*4-3,j*4-3,2);
	}
	for(i=1;i<=m;++i){
		if(n%4==1)printf("%d %d\n",i*4-3,n);
		printf("%d %d\n",i*4-3,i*4);
		if(n%4==1)printf("%d %d\n",i*4,n);
		if(n%4==1)printf("%d %d\n",i*4-2,n);
		printf("%d %d\n",i*4-2,i*4-1);
		if(n%4==1)printf("%d %d\n",i*4-1,n);
		printf("%d %d\n",i*4-3,i*4-1);
		printf("%d %d\n",i*4-2,i*4);
		printf("%d %d\n",i*4-3,i*4-2);
		printf("%d %d\n",i*4-1,i*4);
	}
	return 0;
}