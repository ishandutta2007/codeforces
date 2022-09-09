#include<cstdio> 
const int N=300005,L=20,M=6200000;
struct trie{
	int u,s[M],i,ch[M][2],xb,c,T[L],ans;
	inline void ins(int x){
		for(i=19,u=0;i>=0;--i){
			c=x>>i&1;
			if(!ch[u][c])ch[u][c]=++xb;
			u=ch[u][c];
			++s[u];
		}
	}
	inline void mdy(int x){
		for(i=0;i<20;++i)T[i]^=x>>i&1;
	}
	inline int mex(){
		for(i=19,u=0,ans=0;i>=0;--i){
			c=T[i];
			if(s[ch[u][c]]==1<<i)ans|=1<<i,u=ch[u][c^1];
				else u=ch[u][c];
		}
		return ans;
	}
}t;
int n,m,i,x;
bool b[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&x);
		if(!b[x])t.ins(x),b[x]=1;
	}
	while(m--){
		scanf("%d",&x);
		t.mdy(x);
		printf("%d\n",t.mex());
	}
	return 0;
}