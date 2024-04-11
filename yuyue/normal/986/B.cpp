#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10;
LL rd(){
	return rand()^(rand()<<10ll);
}
int n,p[M];
#define lowbit(x) (x&-x)
int d[M];
void add(int x){
	for (;x<=n;x+=lowbit(x)) d[x]++;
}
int Q(int x){
	int ret=0;
	for (;x;x-=lowbit(x)) ret+=d[x];
	return ret;
}
int main(){
	n=read();
	F(i,1,n) p[i]=read();
	LL ni=0;
	DF(i,n,1){
		ni+=Q(p[i]);
		add(p[i]);
	}
	if ((ni&1)==(n&1)) cout<<"Petr\n";
	else cout<<"Um_nik\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/