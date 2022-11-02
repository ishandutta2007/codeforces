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
const int N=100005;
priority_queue<pair<int,int> > q;
int n,m,a[N],w[N],an[N];
LL ans;
int main(){
	n=read(); m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<=n;i++){
		if(a[i]%100==0)continue;
		q.push(mp((a[i]%100-100)*w[i],i));
		if(m>=a[i]%100){
			m-=a[i]%100;
		}else{
			ans-=q.top().first; an[q.top().second]=1; q.pop();
			m+=100-a[i]%100;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		if(an[i]){
			write(a[i]/100+1); puts(" 0");
		}else{
			write(a[i]/100); putchar(' '); writeln(a[i]%100);
		}
	}
}