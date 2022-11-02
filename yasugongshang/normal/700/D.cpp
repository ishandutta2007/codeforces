#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int n,len,m,i,tong[N],kind,ll,rr,an[N],a[N],block,tt[N],arr[N];
map<int,int> M;
map<int,int>::iterator it;
struct data{
	int l,r,id,num;
}q[N];
inline int ask(){
	int ans=0;
	priority_queue<int> q; while(!q.empty())q.pop();
	for(it=M.begin();it!=M.end();it++)for(int j=1;j<=it->second;j++)q.push(-it->first);
	for(int i=1;i<=block;i++)tt[i]=arr[i]; int dq=0;
	for(int i=1;i<=block;i++)if(tt[i]){
		if(dq){
			if(i+dq<=block)tt[i+dq]++; else q.push(-i-dq); ans+=i+dq; tt[i]--; dq=0;
		}
		ans+=(tt[i]/2)*(i+i); if(i+i<=block)tt[i+i]+=tt[i]/2; else for(int j=1;j*2<=tt[i];j++)q.push(-i-i);
		if(tt[i]&1)dq=i; tt[i]=0;
	}
	if(q.empty())return ans;
	if(dq){
		int t=-q.top(); q.pop(); ans+=t+dq; q.push(-t-dq); dq=0;
	}
	while(q.size()>1){
		int t1=-q.top(); q.pop(); int t2=-q.top(); q.pop();
		ans+=t1+t2; q.push(-t1-t2);
	}
	return ans;
}
inline void del(int p){
	arr[tong[a[p]]]--; if(tong[a[p]]>block)if(--M[tong[a[p]]]==0)M.erase(tong[a[p]]);
	arr[--tong[a[p]]]++; if(tong[a[p]]>block)M[tong[a[p]]]++;
}
inline void ins(int p){
	arr[tong[a[p]]]--; if(tong[a[p]]>block)if(--M[tong[a[p]]]==0)M.erase(tong[a[p]]);
	arr[++tong[a[p]]]++; if(tong[a[p]]>block)M[tong[a[p]]]++;
}
inline bool cmp(data a,data b){
	return a.id<b.id||(a.id==b.id&&(((a.id&1)&&a.r<b.r)||(((a.id&1)==0)&&a.r>b.r)));
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
int main(){
	n=read(); len=sqrt(n); block=sqrt(100*n);
	for(int i=1;i<=n;i++)a[i]=read();
	m=read();
	for(int i=1;i<=m;i++){
		q[i].l=read(); q[i].r=read();
		q[i].id=q[i].l/len; q[i].num=i;
	}
	sort(&q[1],&q[m+1],cmp);
	ll=q[1].l; rr=q[1].l-1;
	for(int i=1;i<=m;i++){
		while(ll>q[i].l)ins(--ll);
		while(rr<q[i].r)ins(++rr);
		while(ll<q[i].l)del(ll++);
		while(rr>q[i].r)del(rr--);
		//cout<<ll<<" "<<rr<<" zhu"<<endl;
		an[q[i].num]=ask();
	}
	for(int i=1;i<=m;i++)writeln(an[i]);
}