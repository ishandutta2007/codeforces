#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,a,b,c,i,j,k,ans,st[399],w,aa[N],cnt[8];
int C2(int x){return x*(x-1)/2;}
int C3(int x){return x*(x-1)*(x-2)/6;}
vector<int>d[N];
void ins(int a,int z){
	for(int x:d[a]){
		if(!aa[x])st[++w]=x;
		aa[x]|=z;
	}
}
bool can[8][8][8];
int main(){
	for(i=1;i<8;++i)for(j=i;j<8;++j)for(k=j;k<8;++k){
		int p[3]={1,2,4},fl=0;
		do{
			fl|=(i&p[0]) && (j&p[1]) && (k&p[2]);
		}while(next_permutation(p,p+3));
		can[i][j][k]=fl;
	}
	for(i=1;i<N;++i)for(j=i;j<N;j+=i)d[j].push_back(i);
//	for(i=1;i<N;++i)a=max(a,d[i]);printf("%d\n",a);
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&a,&b,&c);
		w=0;ins(a,1);ins(b,2);ins(c,4);
		memset(cnt,0,32);
		for(i=1;i<=w;++i)++cnt[aa[st[i]]];
		ans=0;
		for(i=1;i<8;++i)for(j=i;j<8;++j)for(k=j;k<8;++k)if(can[i][j][k]){
			if(i==j && j==k)ans+=C3(cnt[i]+2);
				else if(i==j)ans+=C2(cnt[i]+1)*cnt[k];
						else if(j==k)ans+=cnt[i]*C2(cnt[j]+1);
								else ans+=cnt[i]*cnt[j]*cnt[k];
		}
		printf("%d\n",ans);
		for(i=1;i<=w;++i)aa[st[i]]=0;
	}
}