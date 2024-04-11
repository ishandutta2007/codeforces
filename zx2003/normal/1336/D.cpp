#include<bits/stdc++.h>
using namespace std;
const int N=105;
int lv1,lv2,v1,v2;
void ask(int x){
	printf("+ %d\n",x);fflush(stdout);
	int p,q;scanf("%d%d",&p,&q);v1=p-lv1;v2=q-lv2;lv1=p;lv2=q;
}
int n,i,j,a[N],dt1[N],dt2[N];
map<int,int>mp;
int main(){
	scanf("%d%d%d",&n,&lv1,&lv2);
	for(i=3;i<N;++i)mp[i*(i-1)*(i-2)/6-(i-1)*(i-2)*(i-3)/6]=i;
	for(i=n-1;i>=3;--i)
		ask(i),dt1[i]=v1,dt2[i]=v2;
	int v3,v4,v5,v6,v7,v8;
	ask(1);v3=v1;v4=v2;
	ask(2);v5=v1;v6=v2;
	ask(1);v7=v1;v8=v2;
	a[1]=v7?mp[v7]-2:0;
	a[3]=v8-v4-1;
	a[2]=v4/(a[3]+1);
	a[4]=v6/(a[3]+1)-a[1]-1-(n>4);
	for(i=4;i<n;++i)
		a[i+1]=(dt2[i-1]-a[i-3]*a[i-2])/(a[i]+1)-a[i-2]-(i<n-1);
	printf("! ");for(i=1;i<=n;++i)printf("%d%c",a[i],i==n?'\n':' ');fflush(stdout);
}