#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(j);i<=(k);i++)
using namespace std;
int c[10],c2[10],num[100];
int has[10],ans[10000],tot;
bool diff(int x){
	For(i,0,3) c[i]=x%10,x/=10;
	For(i,0,3) For(j,i+1,3)
		if (c[i]==c[j]) return 0;
	return 1;
}
int check(int x,int y){
	For(i,0,3) c[i]=x%10,x/=10,has[c[i]]=1;
	For(i,0,3) c2[i]=y%10,y/=10;
	int s1=0,s2=0;
	For(i,0,3) if (c[i]==c2[i]) s1++;
	For(i,0,3) if (c[i]!=c2[i]&&has[c2[i]]) s2++;
	For(i,0,3) has[c[i]]=0;
	return s1*10+s2;
}
int calc(int x){
	For(i,0,4) For(j,0,4) num[i*10+j]=0;
	For(i,1,tot) num[check(ans[i],x)]++;
	int ans=0;
	For(i,0,4) For(j,0,4) ans=max(ans,num[i*10+j]);
	return ans;
}
int main(){
	For(i,0,9999) if (diff(i)) ans[++tot]=i; 
	for (;tot>1;){
		int mn=23333333,x;
		For(i,1,tot){
			int v=calc(ans[i]);
			if (v<mn) mn=v,x=ans[i];
		}
		printf("%04d\n",x);
		fflush(stdout);
		int p,q,tmp=0;
		scanf("%d%d",&p,&q);
		For(i,1,tot)
			if (check(ans[i],x)==p*10+q)
				ans[++tmp]=ans[i];
		tot=tmp;
	}
	printf("%04d\n",ans[1]);
}