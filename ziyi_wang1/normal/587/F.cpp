#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
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
const int N=500;
char s[101000];
vector<int>c[101000],e[101000],t[101000];
int n,m,L,R,X,len[101000];
int ch[101000][27],fail[101000],tot;
queue<int>q;
ll w[3030000],ans;
int lc[3030000],rc[3030000],root[101000],cnt;
ll st[201][100001],tmp[101000];
int ln,id[101000],val[101000],num;
I insert(int x){
	re p=1;
	F(i,1,len[x]){
		if(!ch[p][c[x][i]])ch[p][c[x][i]]=++tot;
		p=ch[p][c[x][i]];
	}
	t[p].emplace_back(x);
}
I modi(int &k,int k1,int l,int r,int x){
	k=++cnt;w[k]=w[k1]+1;lc[k]=lc[k1];rc[k]=rc[k1];
	if(l==r)return;
	re mid=(l+r)>>1;
	if(x<=mid)modi(lc[k],lc[k1],l,mid,x);
	else modi(rc[k],rc[k1],mid+1,r,x);
}
inline ll ques(int k,int l,int r,int x,int y){
	if(x>r||y<l||!k)return 0;
	if(x<=l&&r<=y)return w[k];
	re mid=(l+r)>>1;
	return ques(lc[k],l,mid,x,y)+ques(rc[k],mid+1,r,x,y);
}
I D_1(int x){
	root[x]=root[fail[x]];
	for(auto d:t[x])modi(root[x],root[x],1,n,d);
	for(auto d:e[x])D_1(d);
}
I D_2(int x){
	for(auto d:e[x])D_2(d),val[x]+=val[d];
	for(auto d:t[x])tmp[d]+=val[x];
}
int main(){
	read(n);read(m);tot=1;
	F(i,1,n){
		scanf("%s",s+1);len[i]=strlen(s+1);c[i].resize(len[i]+1);
		F(j,1,len[i])c[i][j]=s[j]-'a'+1;
		insert(i);
	}
	fail[1]=1;F(i,1,26)if(ch[1][i])fail[ch[1][i]]=1,q.emplace(ch[1][i]);else ch[1][i]=1;
	while(!q.empty()){
		re p=q.front();q.pop();
		F(i,1,26){
			if(!ch[p][i])ch[p][i]=ch[fail[p]][i];
			else{
				fail[ch[p][i]]=ch[fail[p]][i];
				q.emplace(ch[p][i]);
			}
		}
	}
	F(i,2,tot)e[fail[i]].emplace_back(i);D_1(1);
	F(i,1,n)if(len[i]>=N){
		id[i]=++num;
		F(j,1,n)tmp[j]=0;F(j,1,tot)val[j]=0;
		re p=1;F(j,1,len[i])p=ch[p][c[i][j]],val[p]++;
		D_2(1);F(j,1,n)st[num][j]=st[num][j-1]+tmp[j];
	}
	while(m--){
		read(L);read(R);read(X);
		if(len[X]>=N)printf("%lld\n",st[id[X]][R]-st[id[X]][L-1]);
		else{
			re p=1;ans=0;
			F(i,1,len[X])p=ch[p][c[X][i]],ans+=ques(root[p],1,n,L,R);
			printf("%lld\n",ans);
		}
	}
	return 0;
}