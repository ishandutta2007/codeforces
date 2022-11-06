#include<stdio.h>
#include<vector>
#include<memory.h>
#include<algorithm>
struct nodde{
	nodde *s[26],*f;
	int maxx;
}trr[600002],*topp=trr-1,*nulll=trr,*lt,*rtt;
nodde *addnode(int maxx){
	nodde *p=++topp;p->f=nulll;p->maxx=maxx;
	for(int i=0;i<26;i++)p->s[i]=nulll;
	return p;
}
int n,m,Last[600002],Next[600002],a[600002],d[600002],N;
char c[200002];
void build(){
	addnode(0);lt=rtt=addnode(0);
	for(int i=n,j=1;i>0;i--,j++){
		nodde *p=addnode(j);a[j]=p-trr;
		while(1){
			if(lt->s[c[i]-'a']==nulll)lt->s[c[i]-'a']=p,lt=lt->f;
			else{
				if(lt->s[c[i]-'a']->maxx==lt->maxx+1)p->f=lt->s[c[i]-'a'];
				else{
					nodde *t=addnode(lt->maxx+1),*q=lt->s[c[i]-'a'];
					memcpy(t->s,q->s,sizeof(q->s));t->f=q->f;q->f=p->f=t;
					while(lt->s[c[i]-'a']==q)lt->s[c[i]-'a']=t,lt=lt->f;
				}break;
			}if(lt==nulll){
				p->f=rtt;break;
			}
		}lt=p;
	}for(int i=topp-trr;i>1;i--){
		int f=(trr+i)->f-trr;d[i]=(trr+i)->maxx;
		Next[i]=Last[f];Last[f]=i;
	}N=topp-trr;
}
int t[600002],r[600002],st[1200002][21],pos[600002],tp1=0,tp2=0,log_2[1200002];
void dfs(int p){
	t[p]=++tp1;st[pos[p]=++tp2][0]=p;
	for(int i=Last[p];i;i=Next[i])dfs(i),st[++tp2][0]=p;
	r[p]=tp1;
}
void st_init(){
	dfs(1);
	for(int i=2;i<=N<<1;i++)log_2[i]=log_2[i>>1]+1;
	for(int i=1;i<=log_2[N<<1];i++)
		for(int j=1;j<=N+N-(1<<i);j++)
			st[j][i]=d[st[j][i-1]]<d[st[j+(1<<i-1)][i-1]]?st[j][i-1]:st[j+(1<<i-1)][i-1];
}
int lca(int p,int q){
	if(p==q)return p;
	p=pos[p];q=pos[q];
	if(p>q)p^=q^=p^=q;
	int h=log_2[q-p+1];
	return d[st[p][h]]<d[st[q-(1<<h)+1][h]]?st[p][h]:st[q-(1<<h)+1][h];
}
int cnt1[600002],cnt2[600002],f[600002];
unsigned long long calc(int p){
	unsigned long long ans=0;
	for(int i=Last[p];i;i=Next[i])ans+=calc(i),cnt1[p]+=cnt1[i],cnt2[p]+=cnt2[i];
	return ans+(p==1?0:1ull*cnt1[p]*cnt2[p]*(d[p]-d[f[p]]));
}
std::vector<int>V,S;
void solve(std::vector<int>&A,std::vector<int>&B){
	V.push_back(1);
	for(int &p:A)V.push_back(a[p]);
	for(int &p:B)V.push_back(a[p]);
	std::sort(V.begin(),V.end(),[](int p,int q){return t[p]<t[q];});
	V.resize(std::unique(V.begin(),V.end())-V.begin());
	int n=V.size();
	for(int i=1;i<n;i++)V.push_back(lca(V[i-1],V[i]));
	std::sort(V.begin(),V.end(),[](int p,int q){return t[p]<t[q];});
	V.resize(std::unique(V.begin(),V.end())-V.begin());
	for(int &i:V){
		while(!S.empty()&&r[S.back()]<t[i])S.pop_back();
		if(!S.empty())Next[i]=Last[f[i]=S.back()],Last[S.back()]=i;
		S.push_back(i);
	}S.clear();
	for(int &p:A)cnt1[a[p]]++;
	for(int &p:B)cnt2[a[p]]++;
	printf("%lld\n",calc(1));
	for(int &p:V)cnt1[p]=cnt2[p]=Last[p]=Next[p]=0;
	V.clear();
}
int main(){
	scanf("%d%d%s",&n,&m,c+1);
	build();st_init();
	memset(Last,0,sizeof(Last));
	memset(Next,0,sizeof(Next));
	std::vector<int>A,B;
	while(m--){
		int p,q,r;scanf("%d%d",&p,&q);
		while(p--)scanf("%d",&r),A.push_back(n+1-r);
		while(q--)scanf("%d",&r),B.push_back(n+1-r);
		solve(A,B);
		A.clear();B.clear();
	}
}