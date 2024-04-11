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
namespace Tree{
	int root[404000],tot,lc[9090000],rc[9090000],w[9090000];
	#define lt lc[k],l,mid
	#define rt rc[k],mid+1,r
	I modi(int &k,int l,int r,int x){
		if(!k)k=++tot;w[k]++;
		if(l==r)return;
		re mid=(l+r)>>1;
		if(x<=mid)modi(lt,x);
		else modi(rt,x);
	}
	IN ques(int k,int l,int r,int x,int y){
		if(x>r||y<l||!k)return 0;
		if(x<=l&&r<=y)return w[k];
		re mid=(l+r)>>1;
		return ques(lt,x,y)+ques(rt,x,y);
	}
	IN merge(int x,int y){
		if(!x||!y)return x+y;
		re now=++tot;
		w[now]=w[x]+w[y];lc[now]=merge(lc[x],lc[y]);rc[now]=merge(rc[x],rc[y]);
		return now;
	}
};
namespace SAM{
	int ch[404000][27],len[404000],link[404000],tot,las,p,q,cur,cle;
	int buc[404000],sa[404000],id[202000];
	I init(){
		las=1;tot=1;
	}
	I add(int x){
		if(ch[las][x]){
			p=las;q=ch[p][x];
			if(len[p]+1==len[q]){las=q;return;}
			cle=++tot;len[cle]=len[p]+1,link[cle]=link[q];
			memcpy(ch[cle],ch[q],sizeof(ch[q]));
			while(p&&ch[p][x]==q)ch[p][x]=cle,p=link[p];
			las=cle;link[q]=cle;return;
		}
		len[cur=++tot]=len[las]+1;p=las;las=cur;
		while(p&&!ch[p][x])ch[p][x]=cur,p=link[p];
		if(!p){link[cur]=1;return;}
		q=ch[p][x];
		if(len[p]+1==len[q]){link[cur]=q;return;}
		cle=++tot;len[cle]=len[p]+1,link[cle]=link[q];
		memcpy(ch[cle],ch[q],sizeof(ch[q]));
		while(p&&ch[p][x]==q)ch[p][x]=cle,p=link[p];
		link[cur]=link[q]=cle;
	}
	I sort(){
		F(i,1,tot)buc[len[i]]++;
		F(i,1,tot)buc[i]+=buc[i-1];
		FOR(i,tot,1)sa[buc[len[i]]--]=i;
		FOR(i,tot,1){
			if(sa[i]==1)continue;Tree::root[link[sa[i]]]=Tree::merge(Tree::root[link[sa[i]]],Tree::root[sa[i]]);
		}
	}
};
char c[202000];
int n,m,X,Y,W;
int main(){
	read(n);read(m);
	SAM::init();
	F(i,1,n){
		scanf("%s",c+1);SAM::las=1;re len=strlen(c+1);
		F(j,1,len)SAM::add(c[j]-'a'+1),Tree::modi(Tree::root[SAM::las],1,n,i);
		SAM::id[i]=SAM::las;
	}
	SAM::sort();
	while(m--){
		read(X);read(Y);read(W);
		printf("%d\n",Tree::ques(Tree::root[SAM::id[W]],1,n,X,Y));
	}
	return 0;
}