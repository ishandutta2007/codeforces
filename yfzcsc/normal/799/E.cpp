#include<set>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 400100
using namespace std;
typedef pair<int,int> par;
typedef long long ll;
set<par> st,del;
ll sum,ans=1ll<<60,wer,ppp;
int n,c[maxn],a,x[maxn],sz,b,y[maxn],m,k;
int A[maxn],tpa,vis[maxn],B[maxn],tpb,C[maxn],tpc,D[maxn],tp;
int comp(int a,int b){return c[a]<c[b];}
void push(par x){
	if(sz<=0){
		del.insert(x);
		return ;
	}
	if(st.size()<sz){
		st.insert(x);
		sum+=x.first;
	} else if(*st.rbegin()>x)
		sum+=x.first-st.rbegin()->first,
		del.insert(*st.rbegin()),
		st.erase(*st.rbegin()),st.insert(x);
	else del.insert(x);
}
void _del(par x){
	if(!st.count(x)) del.erase(x);
	else st.erase(x),sum-=x.first;
}
int main(){
//	freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	if(m<k)return puts("-1"),0;
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	scanf("%d",&a);
	for(int i=1;i<=a;++i)scanf("%d",&x[i]),vis[x[i]]++;
	scanf("%d",&b);
	for(int i=1;i<=b;++i)scanf("%d",&y[i]),vis[y[i]]+=2;
	if(a<k||b<k)return puts("-1"),0;
	for(int i=1;i<=n;++i)if(vis[i]==3)A[++tpa]=i;
	sort(A+1,A+tpa+1,comp);
	if(tpa>k){
		for(int i=1;i<=k;++i)vis[A[i]]=-1;
		for(int i=1;i<=n;++i)if(vis[i]!=-1)D[++tp]=i;
		sort(D+1,D+tp+1,comp);
		ll p=0;
		for(int i=1;i<=m-k;++i)p+=c[D[i]];
		for(int i=1;i<=k;++i)p+=c[A[i]];
		ans=p;
	}
	tpa=min(tpa,k);
	sz=m-(tpa+(k-tpa)+(k-tpa));
	for(int i=1;i<=tpa;++i)ppp+=c[A[i]];
	for(int i=1;i<=n;++i)
		if(vis[i]==2)B[++tpb]=i;
		else if(vis[i]==1)C[++tpc]=i;
		else if(vis[i]==0)push(par(c[i],i));
	if(k-tpa>tpb||k-tpa>tpc)return puts("-1"),0;
	sort(B+1,B+tpb+1,comp);
	sort(C+1,C+tpc+1,comp);
	for(int i=k-tpa+1;i<=tpb;++i)push(par(c[B[i]],B[i]));
	for(int i=k-tpa+1;i<=tpc;++i)push(par(c[C[i]],C[i]));
	for(int i=1;i<=k-tpa;++i)wer+=c[B[i]],wer+=c[C[i]];
	if(sz==st.size())ans=min(ans,wer+sum+ppp);
	for(int i=tpa-1;i>=0&&(k-i)<=tpb&&(k-i)<=tpc;--i){
	//	printf("[%d,%d,%d]\n",i,sz,del.size());
		_del(par(c[B[k-i]],B[k-i])),wer+=c[B[k-i]];
		_del(par(c[C[k-i]],C[k-i])),wer+=c[C[k-i]];
		sz--,ppp-=c[A[i+1]];
		while(st.size()>sz&&st.size())sum-=st.rbegin()->first,st.erase(*st.rbegin());
		if(del.size()){
			par x=*del.begin();
			del.erase(*del.begin());
			push(x);
		}
		if(sz==st.size())ans=min(ans,wer+sum+ppp);
	}
	if(ans==(1ll<<60))puts("-1");
	else printf("%lld",ans);
}
/*
tp+(k-tp)+(k-tp) m-();
tp-1+(k-tp+1)+(k-tp+1) m-()-1;8\*/