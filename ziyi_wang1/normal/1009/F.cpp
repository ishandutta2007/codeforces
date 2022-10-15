#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
I read(int &res){
	res=0;re g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
struct E{
	int to,nt;
}e[2020000];
#define T e[k].to
int n,m,tot,X,Y,g[1001000],*id=g,head[1010000],ans[1010000],*f[1010000],len[1010000],son[1010000];
I D_1(int x,int fa){
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa)continue;
		D_1(T,x);
		if(len[T]>len[son[x]])son[x]=T;
	}
	len[x]=len[son[x]]+1;
}
I tree_dp(int x,int fa){
	f[x][0]=1;
	if(son[x])f[son[x]]=f[x]+1,tree_dp(son[x],x),ans[x]=ans[son[x]]+1;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa||T==son[x])continue;
		f[T]=id;id+=len[T];
		tree_dp(T,x);
		F(i,1,len[T]){
			f[x][i]+=f[T][i-1];
			if((i<ans[x]&&f[x][i]>=f[x][ans[x]])||(i>ans[x]&&f[x][i]>f[x][ans[x]]))ans[x]=i;
		}
	}
	if(f[x][ans[x]]==1)ans[x]=0;
}
int main(){
	read(n);
	memset(head,-1,sizeof(head));
	F(i,1,n-1){
		read(X);read(Y);
		e[++tot].to=Y;
		e[tot].nt=head[X];
		head[X]=tot;
		e[++tot].to=X;
		e[tot].nt=head[Y];
		head[Y]=tot;
	}
	D_1(1,0);
	f[1]=id;id+=len[1];
	//system("pause");
	tree_dp(1,0);
	F(i,1,n){
		cout<<ans[i]<<endl;
	}
	return 0;
}