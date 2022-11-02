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
const int N=300005;
struct data{
	int l,r,id;
}a[N];
inline bool cmp(data a,data b){
	return a.r>b.r;
}
int ans,n,k,pos;
priority_queue<int> q;
int main(){
	n=read(); pos=k=read();
	for(int i=1;i<=n;i++){
		a[i].l=read(); a[i].r=read(); a[i].id=i;
	}
	sort(&a[1],&a[n+1],cmp);
	for(int i=1;i<k;i++){
		q.push(a[i].l);
	}
	for(int i=k;i<=n;i++){
		q.push(a[i].l); if(q.size()>k)q.pop();
		if(a[i].r-q.top()+1>ans){
			ans=a[i].r-q.top()+1;
			pos=i;
		}
	}
	priority_queue<pair<int,int> > q;
	while(!q.empty())q.pop(); 
	for(int i=1;i<=pos;i++){
		q.push(mp(a[i].l,a[i].id)); if(q.size()>k)q.pop();
	}
	cout<<ans<<endl;
	while(!q.empty()){
		write(q.top().second); putchar(' '); q.pop();
	}
}