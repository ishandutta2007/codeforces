#include<bits/stdc++.h>
#define pb push_back
#define SZ(x) ((int)x.size())
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,mod1=1000000007,mod2=1000000009;typedef long long ll;
struct hash{
	ll a,b;
	inline hash(){a=b=0;}
	inline hash(ll x){a=x,b=x;}
	inline hash(ll x,ll y){a=x,b=y;}
	inline hash operator += (const hash &o){a=a+o.a>=mod1?a+o.a-mod1:a+o.a,b=b+o.b>=mod2?b+o.b-mod2:b+o.b;return *this;}
	inline hash operator + (const hash &o)const{hash x(*this);return x+=o;}
	inline hash operator -= (const hash &o){a=a-o.a<0?a-o.a+mod1:a-o.a,b=b-o.b<0?b-o.b+mod2:b-o.b;return *this;}
	inline hash operator - (const hash &o)const{hash x(*this);return x-=o;}
	inline hash operator * (const hash &o)const{return hash(a*o.a%mod1,b*o.b%mod2);}
	inline bool operator == (const hash &o)const{return a==o.a&&b==o.b;}
	inline bool operator != (const hash &o)const{return a!=o.a||b!=o.b;}
	inline bool operator < (const hash &o)const{return a==o.a?b<o.b:a<o.a;}
}f[35][N],pw[N];
const hash base=hash(2333);
inline hash get(int p,int l,int r){
	hash ans=f[p][r];if(l)ans-=f[p][l-1]*pw[r-l+1];
	return ans;
}
std::string s[35];int id[35][N],nc;
struct edge{int v,nxt;}c[N*31];
int front[N],ec,dg[N];
inline void addedge(int u,int v){
	c[++ec]=(edge){v,front[u]},front[u]=ec,++dg[v];
}
int _q[N],_l,_r;
bool check(int l,int r){
	if(l>r)return 1;
	memset(dg,0,(nc+3)<<2),memset(front,0,(nc+3)<<2),nc=1;ec=0;
	for(int i=l;i<=r;++i)for(int j=0;j<SZ(s[i]);++j)id[i][j]=++nc;
	for(int i=l;i<=r;++i){
		addedge(1,id[i][0]);
		for(int j=0;j<SZ(s[i]);++j){
			int len=SZ(s[i])-j;
			for(int k=l;k<=r;++k){
				int tmp=std::min(len,SZ(s[k]));
				if(get(i,j,j+tmp-1)!=get(k,0,tmp-1))continue;
				if(j==0&&SZ(s[i])==SZ(s[k]))continue;
				if(len==SZ(s[k]))addedge(id[i][j],1);
				else if(len>SZ(s[k]))addedge(id[i][j],id[i][j+SZ(s[k])]);
				else addedge(id[i][j],id[k][len]);
			}
		}
	}
	_l=1,_r=0;for(int i=1;i<=nc;++i)if(!dg[i])_q[++_r]=i;
	while(_l!=_r+1){
		int x=_q[_l++];
		for(int i=front[x];i;i=c[i].nxt){
			int v=c[i].v;
			if(!--dg[v])_q[++_r]=v;
		}
	}
	return _r==nc;
}
int main(){
	pw[0]=hash(1);for(int i=1;i<N;++i)pw[i]=pw[i-1]*base;
	int n;read(n);
	for(int i=1;i<=n;++i)std::cin>>s[i];
	for(int i=1;i<=n;++i)for(int j=0;j<SZ(s[i]);++j)f[i][j]=j==0?hash(s[i][j]):f[i][j-1]*base+hash(s[i][j]);
	int ans=0;
	for(int i=1,j=0;i<=n;++i){
		while(j<n&&check(i,j+1))++j;
		ans+=j-i+1;
	}
	printf("%d\n",ans);
	return 0;
}