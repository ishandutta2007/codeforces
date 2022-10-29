#include<bits/stdc++.h>
#define maxn 5010
using namespace std;
int p[maxn],ans,b[maxn],ret,A[maxn],B[maxn],n,anses[maxn];
int ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&ret);
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		A[i]=ask(0,i);
	for(int i=0;i<n;++i)
		B[i]=ask(i,0);
	for(int i=0;i<n;++i){
		p[0]=i;
		for(int j=1;j<n;++j)
			p[j]=B[j]^B[0]^p[0];
		for(int j=0;j<n;++j)
			b[p[j]]=j;
		for(int j=0;j<n;++j)
			if((b[j]^p[0])!=(A[j]))goto nxt;
		for(int j=0;j<n;++j)anses[j]=p[j];
		ans++;
		nxt:;
	}
	printf("!\n%d\n",ans);
	for(int i=0;i<n;++i)printf("%d ",anses[i]);
	printf("\n");
	fflush(stdout);
}