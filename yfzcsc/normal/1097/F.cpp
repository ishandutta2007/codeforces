#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10,maxm=7010,M=7005;
int n,m,mu[maxm];
bitset<maxm>s[maxn],pre[maxm],pre2[maxm];
int main(){
	for(int i=0;i<=M;++i)mu[i]=1;
	for(int i=2;i*i<=M;++i)
		for(int j=i*i;j<=M;j+=i*i)mu[j]=0;
	for(int i=1;i<=M;++i)for(int j=i;j<=M;j+=i)pre[j][i]=1;
	for(int i=1;i<=M;++i)for(int j=i;j<=M;j+=i)if(mu[j/i])pre2[i][j]=1;
	scanf("%d%d",&n,&m);
	for(int i=1,op,x,y,z;i<=m;++i){
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			s[x]=pre[y];
		} else if(op==2){
			scanf("%d",&z);
			s[x]=s[y]^s[z];
		} else if(op==3){
			scanf("%d",&z);
			s[x]=s[y]&s[z];
		} else {
			printf("%d",(s[x]&pre2[y]).count()&1);
		}
	}
}