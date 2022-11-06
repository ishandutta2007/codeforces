#include<stdio.h>
#include<vector>
#include<stack>
#include<unordered_map>
int ans[100002],n,m,f[200002],s[200002];
inline int gf(int p){while(f[p]!=p)p=f[p];return p;}
std::unordered_map<unsigned long long,int>M;std::stack<std::pair<int,int> >S;
struct node{
	node *ls,*rs;
	std::vector<std::pair<int,int> >V;
}tr[300002],*null=tr,*top=tr-1,*rt;
node *addnode(){node *p=++top;p->ls=p->rs=null;return p;}
void build(int l,int r,node *p){
	if(l!=r)build(l,l+r>>1,p->ls=addnode()),build(l+r+2>>1,r,p->rs=addnode());
}
void add(int L,int R,int l,int r,node *p,int x,int y){
	if(L<=l&&r<=R){p->V.push_back(std::make_pair(x,y));return;}
	if(L<=l+r>>1)add(L,R,l,l+r>>1,p->ls,x,y);
	if(R>l+r>>1)add(L,R,l+r+2>>1,r,p->rs,x,y);
}
void merge(int p,int q){
	p=gf(p);q=gf(q);
	if(p!=q){
		if(s[p]<s[q])p^=q^=p^=q;
		f[q]=p;s[p]+=s[q];S.push(std::make_pair(p,q));
	}else S.push(std::make_pair(0,0));
}
void hdhdAKIOI(){
	int p=S.top().first,q=S.top().second;S.pop();
	if(p&&q)f[q]=q,s[p]-=s[q];
}
void dfs(int l,int r,node *p){
	bool fl=0;
	for(auto i:p->V){
		merge(i.first,i.second+n);
		merge(i.second,i.first+n);
		if(gf(i.first)==gf(i.second))fl=1;
	}if(fl){
		for(int i=l;i<=r;i++)ans[i]=1;
	}else if(l!=r){
		dfs(l,l+r>>1,p->ls);
		dfs(l+r+2>>1,r,p->rs);
	}for(int i=p->V.size()*2;i;i--)hdhdAKIOI();
}
int main(){
	scanf("%d%d",&n,&m);
	addnode();build(1,m,rt=addnode());
	for(int i=1;i<=m;i++){
		int hdhd,AKIOI;scanf("%d%d",&hdhd,&AKIOI);
		if(hdhd>AKIOI)hdhd^=AKIOI^=hdhd^=AKIOI;
		auto pt=M.find(1ull*hdhd*n+AKIOI);
		if(pt==M.end())M[1ull*hdhd*n+AKIOI]=i;
		else add(pt->second,i-1,1,m,rt,hdhd,AKIOI),M.erase(pt);
	}for(auto i:M)add(i.second,m,1,m,rt,(i.first-1)/n,(i.first-1)%n+1);
	for(int i=1;i<=n+n;i++)f[i]=i,s[i]=1;dfs(1,m,rt);
	for(int i=1;i<=m;i++)puts(ans[i]?"NO":"YES");
}