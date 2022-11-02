#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
int ans[N],g[N],p[N],t[N],n,w,h,q1[N],q2[N],a[N],b[N],tot1,tot2;
vector<int> v[N<<1];
inline bool cmp(int a,int b){
	return p[a]<p[b];
}
int main(){
	n=read(); w=read(); h=read();
	for(int i=1;i<=n;i++){
		g[i]=read(); p[i]=read(); t[i]=read();
		v[p[i]-t[i]+100000].push_back(i);
	}
	for(int i=0;i<200000;i++){
		int aa=0,bb=tot1=tot2=0;
		for(unsigned j=0;j<v[i].size();j++){
			if(g[v[i][j]]==2)a[++aa]=v[i][j];
   			else b[++bb]=v[i][j];
		}
		sort(&a[1],&a[aa+1],cmp); sort(&b[1],&b[bb+1],cmp); reverse(&a[1],&a[aa+1]);
		for(int i=1;i<=aa;i++)q1[++tot1]=a[i]; for(int i=1;i<=bb;i++)q1[++tot1]=b[i];
		for(int i=1;i<=bb;i++)q2[++tot2]=b[i]; for(int i=1;i<=aa;i++)q2[++tot2]=a[i];
		for(int i=1;i<=tot1;i++){
			ans[q1[i]]=q2[i];
		}
		//if(tot1)cout<<i<<endl;
	}
	for(int i=1;i<=n;i++){
		//cout<<ans[i]<<endl;
		if(g[ans[i]]==1){
			write(p[ans[i]]); putchar(' '); writeln(h);
		}else{
			write(w); putchar(' '); writeln(p[ans[i]]);
		}
	}
}