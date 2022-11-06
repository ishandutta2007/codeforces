//#pragma GCC optimize("-std=c++11")
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define inf 1000000000000000000ll
#define ce if(!D[End[i]]&&End[i]!=f)
#define pll std::pair<long long,long long>
#define vll std::vector<pll >
#define it vll::iterator
vll V[100002],pool[100002];std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int> >,std::greater<std::pair<int,int> > >Q;
int Last[100002],Next[200002],End[200002],D[100002],M[100002],s[100002],L1[200002],L2[200002],tot=0,n,m;
inline long long gp(pll &p,pll &q){return (p.second-q.second-1)/(q.first-p.first)+1;}bool FL=0;
void build(vll &p,bool st){
	if(!st)std::sort(p.begin(),p.end());
	static vll tmp;tmp.clear();tmp.swap(p);
	for(auto i:tmp){
		while(!p.empty()&&p.back().second<=i.second)p.pop_back();
		while(p.size()>1&&gp(p.back(),i)<=gp(*(p.end()-2),p.back()))p.pop_back();
		p.push_back(i);
	}
}
void calc(vll &p,vll &q,vll &ans){
	ans.clear();it p1=p.begin(),p2=q.begin(),e1=p.end(),e2=q.end();
	while(p1!=e1&&p2!=e2){
		ans.push_back(std::make_pair(p1->first+p2->first,p1->second+p2->second));
		long long r1=p1==e1-1?inf:gp(*p1,*(p1+1)),r2=p2==e2-1?inf:gp(*p2,*(p2+1));
		p1+=r1<=r2;p2+=r2<=r1;
	}
}
void merge(vll &p,vll &q){
	static vll tmp;tmp.clear();it p1=p.begin(),p2=q.begin(),e1=p.end(),e2=q.end();
	while(p1!=e1||p2!=e2)tmp.push_back(p2==e2||(p1!=e1&&*p1<=*p2)?*p1++:*p2++);
	p.swap(tmp);build(p,1);
}
void print(vll &p,int l,int r){
	it pt=p.begin(),e=p.end();
	for(int i=l;i<r;i++){
		while(pt!=e-1&&gp(*pt,*(pt+1))<=i)pt++;
		printf("%lld ",pt->first*i+pt->second);
	}
}
void gs(int p,int f){s[p]=1;for(int i=Last[p];i;i=Next[i])ce gs(End[i],p),s[p]+=s[End[i]];}
int gg(int p,int f,int t){M[p]=t-s[p];for(int i=Last[p],j;i;i=Next[i])ce{if(j=gg(End[i],p,t))return j;M[p]<s[End[i]]&&(M[p]=s[End[i]]);}return M[p]*2<=t?p:0;}
int getg(int p){gs(p,0);return gg(p,0,s[p]);}
void get(int p,int f,long long k,long long b,vll &V){bool F=1;for(int i=Last[p];i;i=Next[i])ce F=0,get(End[i],p,k+L1[i],b+L2[i],V);if(F)V.push_back(std::make_pair(k,b));}
void dfs(int p){
	p=getg(p);int top=0;while(!Q.empty())Q.pop();V[++top].clear();V[top].push_back(std::make_pair(0ll,0ll));Q.push(std::make_pair(1,top));
	for(int i=Last[p];i;i=Next[i])if(!D[End[i]])V[++top].clear(),get(End[i],p,L1[i],L2[i],V[top]),build(V[top],0),Q.push(std::make_pair(V[top].size(),top));
	while(Q.size()>1){
		int p=Q.top().second;Q.pop();
		int q=Q.top().second;Q.pop();
		calc(V[p],V[q],pool[++tot]);merge(V[p],V[q]);
		Q.push(std::make_pair(V[p].size(),p));
	}D[p]=1;for(int i=Last[p];i;i=Next[i])if(!D[End[i]])dfs(End[i]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<n+n-2;i+=2)
		scanf("%d%d%d%d",End+i+1,End+i,L1+i,L2+i),L1[i+1]=L1[i],L2[i+1]=L2[i],Next[i]=Last[End[i+1]],Last[End[i+1]]=i,Next[i+1]=Last[End[i]],Last[End[i]]=i+1;
	dfs(1);
	while(!Q.empty())Q.pop();for(int i=1;i<=tot;i++)Q.push(std::make_pair(pool[i].size(),i));
	while(Q.size()>1){
		int p=Q.top().second;Q.pop();int q=Q.top().second;Q.pop();
		if(Q.empty())FL=1;
		merge(pool[p],pool[q]);Q.push(std::make_pair(pool[p].size(),p));FL=0;
	}if(Q.empty())for(int i=0;i<m;i++)printf("%d ",0);
	else print(pool[Q.top().second],0,m);
}