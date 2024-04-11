#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline ll
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
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
const ll INF=1e18+7;
struct E{
	ll to,nt,w;
}e[202000];
#define T e[k].to
ll n,m,root,head[101000],f[101000][2],dep[101000],up[101000],ma[101000],siz[101000],ans,tot=-1,X,Y,W;
ll p[101000],v[101000];
I add(ll x,ll y){
	e[++tot].to=y;
	e[tot].nt=head[x];
	head[x]=tot;
	e[tot].w=W;
}
I D_1(ll x,ll fa){
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa)continue;
		D_1(T,x);re val=f[T][0]+e[k].w;
		if(val>f[x][0])f[x][1]=f[x][0],f[x][0]=val;
		else if(val>f[x][1])f[x][1]=val;
	}
}
I D_2(ll x,ll fa,ll dis){
	if(dis>=f[x][0])f[x][1]=f[x][0],f[x][0]=dis;
	else if(dis>f[x][1])f[x][1]=dis;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa)continue;
		D_2(T,x,(f[x][0]==f[T][0]+e[k].w?f[x][1]:f[x][0])+e[k].w);
	}
	if(f[x][0]<W)W=f[x][0],root=x;
}
I D_3(ll x,ll fa,ll depth){
	up[x]=fa;dep[x]=depth;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fa)continue;
		D_3(T,x,depth+1);
	}
}
inline bool bbb(ll x,ll y){
	return f[x][0]^f[y][0]?f[x][0]>f[y][0]:dep[x]>dep[y];
}
IN Max(ll x,ll y){return x>y?x:y;}
IN find(ll x){
	return ma[x]==x?x:ma[x]=find(ma[x]);
}
I join(int x,int y){
	x=find(x);y=find(y);
	ma[x]=y;siz[y]+=siz[x];
}
I add(ll x){
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==up[x])continue;
		join(T,x);
	}
	//cout<<"!"<<x<<" "<<siz[x]<<endl;
	ans=max(ans,siz[x]);
}
I delet(ll x){siz[find(x)]--;}
int main(){
	read(n);tot=-1;C(head,-1);
	F(i,1,n-1){
		read(X);read(Y);read(W);add(X,Y);add(Y,X);
	}
	D_1(1,0);W=INF;D_2(1,0,0);D_3(root,0,1);
	F(i,1,n)p[i]=i;sort(p+1,p+1+n,bbb);F(i,1,n)v[i]=f[p[i]][0];//,cout<<p[i]<<" "<<v[i]<<" ";
	//cout<<endl;
	read(m);
	while(m--){
		read(W);ans=1;
		F(i,1,n)ma[i]=i,siz[i]=1;
		re r=1;
		F(i,1,n){
			while(r<=n&&v[i]-v[r]<=W)add(p[r]),r++;
			delet(p[i]);if(r>n)break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}