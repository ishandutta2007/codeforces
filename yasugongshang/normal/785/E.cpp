#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=200005,B=500;
int belong[N],L[B],R[B],a[N],n,q;
long long ans;
vector<int> v[B];
inline int get(int l,int r,int x){ 
    if(l>r)return 0;
	int sum=0;
	if(belong[l]==belong[r]){
		for(int i=l;i<=r;i++)if(a[i]<=x)sum++;
	}else{
		for(int i=l;i<=R[belong[l]];i++)if(a[i]<=x)sum++;
		for(int i=L[belong[r]];i<=r;i++)if(a[i]<=x)sum++;
		for(int i=belong[l]+1;i<belong[r];i++)sum+=upper_bound(v[i].begin(),v[i].end(),x)-v[i].begin();
	}
	return sum;
}
inline void update(int x){
	v[x].clear();
	for(int i=L[x];i<=R[x];i++)v[x].push_back(a[i]);
	sort(v[x].begin(),v[x].end());
}
int main(){
	n=read(); q=read(); int block=min(n,(int)sqrt(n*5));
	for(int i=1;i<=n;i++){a[i]=i; if(i%block==0){belong[i]=belong[i-1]+1; R[belong[i]]=L[belong[i]]=i;} else {R[belong[i]=belong[i-1]]=i;}}
	for(int i=1;i<=belong[n];i++)update(i);
	while(q--){
		int l=read(),r=read(); if(l>r)swap(l,r);
		int t1=get(l,r-1,a[r]-1),t2=r-l-t1,t3=get(l+1,r-1,a[l]-1),t4=max(0,r-l-1-t3);
		//for(int i=1;i<=n;i++)cout<<a[i]<<" "; puts("");
		//cout<<t1<<" "<<t3<<endl;
		ans+=t1-t2+t4-t3; //if(a[l]<a[r])ans++; else ans--;
		swap(a[l],a[r]);
		update(belong[l]); update(belong[r]);
		writeln(ans);
	}
}