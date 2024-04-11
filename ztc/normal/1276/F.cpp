#include<stdio.h>
#include<set>
#include<ctime>
#include<vector>
#include<cstdlib>
#include<memory.h>
#include<algorithm>
inline int Max(int p,int q){return p>q?p:q;}
inline int Min(int p,int q){return p<q?p:q;}
struct node{
	node *s[26],*f;
	int maxx;
}tr[600002],*top=tr-1,*null=tr,*lt,*rt;
node *addnode(int maxx){
	node *p=++top;p->f=null;p->maxx=maxx;
	for(int i=0;i<26;i++)p->s[i]=null;
	return p;
}
int n,m,Last[600002],Next[600002],a[600002],d[600002],N,g[600002],f[600002];
int Last1[600002],Next1[600002],a1[600002],d1[600002],N1,g1[600002],f1[600002];
char c[300002];
void build(){
	addnode(0);
	lt=rt=addnode(0);
	for(int i=n;i>0;i--){
		node *p=addnode(n-i+1);a[i]=p-tr;g[p-tr]=i;
		while(1){
			if(lt->s[c[i]-'a']==null)lt->s[c[i]-'a']=p,lt=lt->f;
			else{
				if(lt->s[c[i]-'a']->maxx==lt->maxx+1)p->f=lt->s[c[i]-'a'];
				else{
					node *t=addnode(lt->maxx+1),*q=lt->s[c[i]-'a'];
					memcpy(t->s,q->s,sizeof(q->s));t->f=q->f;q->f=p->f=t;
					while(lt->s[c[i]-'a']==q)lt->s[c[i]-'a']=t,lt=lt->f;
				}break;
			}if(lt==null){
				p->f=rt;break;
			}
		}lt=p;
	}for(int i=top-tr;i>1;i--){
		int F=(tr+i)->f-tr;d[i]=(tr+i)->maxx;
		Next[i]=Last[F];Last[F]=i;f[i]=F;
	}N=top-tr;
}
void build1(){
	top=tr;lt=rt=addnode(0);
	for(int i=1;i<=n;i++){
		node *p=addnode(i);a1[i]=p-tr;g1[p-tr]=i;
		while(1){
			if(lt->s[c[i]-'a']==null)lt->s[c[i]-'a']=p,lt=lt->f;
			else{
				if(lt->s[c[i]-'a']->maxx==lt->maxx+1)p->f=lt->s[c[i]-'a'];
				else{
					node *t=addnode(lt->maxx+1),*q=lt->s[c[i]-'a'];
					memcpy(t->s,q->s,sizeof(q->s));t->f=q->f;q->f=p->f=t;
					while(lt->s[c[i]-'a']==q)lt->s[c[i]-'a']=t,lt=lt->f;
				}break;
			}if(lt==null){
				p->f=rt;break;
			}
		}lt=p;
	}for(int i=top-tr;i>1;i--){
		int F=(tr+i)->f-tr;d1[i]=(tr+i)->maxx;
		Next1[i]=Last1[F];Last1[F]=i;f1[i]=F;
	}N1=top-tr;
}
int t[300002],ft[300002],st[500002][19],pos[300002],tp1=0,tp2=0,log_2[600002];
void dfs0(int p){
	ft[t[p]=++tp1]=p;st[pos[p]=++tp2][0]=d[p];
	for(int i=Last[p];i;i=Next[i]){
		dfs0(i);st[++tp2][0]=d[p];
	}
}
void init(){
	dfs0(1);
	for(int i=2;i<=N+N;i++)log_2[i]=log_2[i>>1]+1;
	for(int i=1;i<=log_2[N+N];i++)for(int j=1;j<=N+N-(1<<i);j++)
		st[j][i]=Min(st[j][i-1],st[j+(1<<i-1)][i-1]);
}
inline int lca(int p,int q){
	p=pos[p];q=pos[q];
	if(p>q)p^=q^=p^=q;
	register int h=log_2[q-p+1];
	return Min(st[p][h],st[q-(1<<h)+1][h]);
}
long long ans=0,cnt=0;
std::set<int>S,S1;
void ins(int p){
	int T=t[p];
	std::set<int>::iterator p1=S.upper_bound(T),p2=S1.upper_bound(-T);
	int g=p1==S.end()?1:ft[*p1],h=p2==S1.end()?1:ft[-*p2];
	int l1=lca(g,p),l2=lca(p,h);
	if(l1!=d[p]&&l2!=d[p]){
		S.insert(T);S1.insert(-T);
		cnt+=d[p]-Max(l1,l2);
	}
}
void clear(){
	S.clear();S1.clear();cnt=0;
}
void add(int p){
	for(int i=Last1[p];i;i=Next1[i])add(i);
	if(g1[p]<=n-2&&g1[p])ins(a[g1[p]+2]);
}
int s[300002],h[300002],mk[300002],mk1[300002];
void dfs1(int p){
	s[p]=g1[p]<=n-2;
	for(int i=Last1[p];i;i=Next1[i]){
		dfs1(i);s[p]+=s[i];
		if(s[i]>s[h[p]])h[p]=i;
	}
}
void dfs2(int p){
	for(int i=Last1[p];i;i=Next1[i])if(i!=h[p]){
		dfs2(i);clear();
	}if(h[p])dfs2(h[p]);
	for(int i=Last1[p];i;i=Next1[i])if(i!=h[p])add(i);
	if(g1[p]<=n-2&&g1[p])ins(a[g1[p]+2]);ans+=1ll*cnt*(d1[p]-d1[f1[p]]);
}
void dfs3(int p){
	if(g[p]==1)mk[p]=1;
	for(int i=Last[p];i;i=Next[i]){
		dfs3(i);if(mk[i])mk[p]=1;
	}for(int i=Last[p];i;i=Next[i])if(!mk[i])mk[p]=0;
	if(g[p]&&g[p]!=1)mk[p]=0;
	if(!mk[p])ans+=d[p]-d[f[p]];
	ans+=d[p]-d[f[p]];
}
void dfs4(int p){
	if(g1[p]==n)mk1[p]=1;
	for(int i=Last1[p];i;i=Next1[i]){
		dfs4(i);if(mk1[i])mk1[p]=1;
	}for(int i=Last1[p];i;i=Next1[i])if(!mk1[i])mk1[p]=0;
	if(g1[p]&&g1[p]!=n)mk1[p]=0;
	if(!mk1[p])ans+=d1[p]-d1[f1[p]];
}
int main(){//srand(time(0));
//	for(int i=1;i<=100000;i++)c[i]='a'+rand()%26;
	scanf("%s",c+1);
	n=1;while(c[n+1])n++;
	build();build1();
	init();
	dfs1(1);dfs2(1);
	dfs3(1);dfs4(1);ans+=2;
	printf("%lld\n",ans);
}