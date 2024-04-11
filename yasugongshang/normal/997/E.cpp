#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=120005,block=300,B=N/block+3,inf=1000000005;
int n,q,a[N],belong[N],mzs[N],p[N],l[N],r[N],q1[N],q2[N],t1,t2,val[N],cnt[B],lazy[B],L[B],R[B];
PI mn[N];
ll ans[N];
PI operator +(PI a,PI b){
	if(a.second==0)return b; else if(b.second==0)return a;
	return a.first==b.first?mp(a.first,a.second+b.second):(a.first>b.first?a:b);
}
void bao(int l,int r,int x){
	//cout<<l<<" "<<r<<" "<<x<<endl;
	int id=belong[l];
	for(int i=l;i<=r;i++)a[i]+=x;
	mn[id]=mp(inf,0); 
	for(int i=L[id];i<=R[id];i++)mn[id]=mn[id]+mp(a[i],1);
}
void down(int x){
	if(!mzs[x])return;
	for(int i=L[x];i<=R[x];i++)if(a[i]==mn[x].first){
		val[i]+=mzs[x];
	}
	mzs[x]=0;
}
void ins(int l,int r,int x){
	if(l>r)return;
	if(belong[l]==belong[r]){
		down(belong[l]); bao(l,r,x); return;
	}
	down(belong[l]); bao(l,R[belong[l]],x);
	down(belong[r]); bao(L[belong[r]],r,x);
	for(int i=belong[l]+1;i<belong[r];i++)lazy[i]+=x;
}
void upd(){
	for(int i=1;i<=belong[n];i++)if(mn[i].first+lazy[i]==0){
		mzs[i]++; cnt[i]+=mn[i].second;
	}
}
ll ask(int l){
	ll ans=0; down(belong[l]);
	for(int i=l;i<=R[belong[l]];i++)ans+=val[i];
	for(int i=belong[l]+1;i<=belong[n];i++)ans+=cnt[i];
	return ans;
}
vector<int> v[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		p[i]=read();
		if((i-1)%block==0)L[belong[i]=belong[i-1]+1]=i; else belong[i]=belong[i-1];
		R[belong[i]]=i; a[i]=-1; mn[belong[i]]=mn[belong[i]]+mp(-1,1);
	}
	q=read();
	for(int i=1;i<=q;i++){
		l[i]=read(); r[i]=read();
		v[r[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		while(p[q1[t1]]<p[i]&&t1){
			ins(q1[t1-1]+1,q1[t1],-p[i]+p[q1[t1]]); t1--; 
		}
		q1[++t1]=i;
		while(p[q2[t2]]>p[i]&&t2){
			ins(q2[t2-1]+1,q2[t2],p[i]-p[q2[t2]]); t2--;
		}
		q2[++t2]=i;
		ins(1,i,1); 
		upd();
		//for(int i=1;i<=n;i++)cout<<a[i]<<" "; puts("");
		//cout<<mzs[1]<<" "<<mn[1].first<<" szb"<<lazy[1]<<" "<<cnt[2]<<" "<<endl;
		for(unsigned j=0;j<v[i].size();j++)ans[v[i][j]]=ask(l[v[i][j]]);
	}
	for(int i=1;i<=q;i++)writeln(ans[i]);
}