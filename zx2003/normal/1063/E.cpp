#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,p[N],i,j,m;
bool b[N];
char c[N][N];
void doo(int i){
	int lst=0;
	for(j=i;;){
		b[j]=1;
		if(lst==0){
			if(p[j]!=i)c[m][i]=c[m][p[j]]=c[m][n]='/';
		}else{
			c[m][i]=c[m][p[j]]=c[m][n]='\\';
		}
		--m;
		lst^=1;
		j=p[j];if(j==i)break;
	}
}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",p+i);
	for(i=1;i<=n;++i)memset(c[i]+1,'.',n);
	for(i=1;i<=n;++i)if(p[i]!=i)break;
	if(i>n){printf("%d\n",n);for(i=1;i<=n;++i)puts(c[i]+1);return 0;}
	m=n-1;
	if(p[n]!=n){
		for(i=1;i<n;++i)if(p[i]==n)break;
		c[n][n]='\\';c[n][i]='\\';p[i]=p[n];
	}
	for(i=1;i<n;++i)if(!b[i]){
		if(p[i]==i)continue;
		doo(i);
	}
	printf("%d\n",n-1);
	for(i=1;i<=n;++i)puts(c[i]+1);
	return 0;
}