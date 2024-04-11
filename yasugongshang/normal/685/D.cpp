#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
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
inline void write(ll a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=200005;
struct data{
	int l,r,x,id;
};
int n,k,tot,sum[N],que[N],x[N],y[N],last[N];
ll ans[N];
vector<data> v;
vector<data>::iterator it;
inline bool cmp(data a,data b){
	return a.x<b.x;
}
int main(){
	n=read(); k=read();
	for(int i=1;i<=n;i++){
		x[i]=read(); y[i]=read();
		que[++tot]=y[i]; que[++tot]=y[i]+k;
	}
	sort(&que[1],&que[tot+1]);
	tot=unique(&que[1],&que[tot+1])-que;
	for(int i=1;i<=n;i++){
		int l=upper_bound(&que[1],&que[tot],y[i])-que,r=lower_bound(&que[1],&que[tot],y[i]+k)-que;
		v.push_back((data){l,r,x[i],1}); v.push_back((data){l,r,x[i]+k,-1});
	}
	sort(v.begin(),v.end(),cmp);
	for(it=v.begin();it!=v.end();it++){
		data t=*it;
		for(int j=t.l;j<=t.r;j++){
			//cout<<t.x<<" "<<que[j]<<" "<<sum[j]<<endl;
			ans[sum[j]]+=(ll)(que[j]-que[j-1])*(t.x-last[j]);
			sum[j]+=t.id; last[j]=t.x;
		}
	}
	for(int i=1;i<=n;i++){
		write(ans[i]); putchar(' ');
	}
}