#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1e5+10;
int n,a[100010],b[100010],p[M];
struct bit{
	#define lowbit(x) (x&-x)
	int d[100010];
	void add(int x){
	 	for (;x<=n;x+=lowbit(x)) d[x]++;
	}
	int s(int x){
	 	int o=0;
	 	for (;x;x-=lowbit(x)) o+=d[x];
	 	return o;
	}
}B;
int main(){
	n=read(); 
	DF(i,n,1) a[i]=read();
	DF(i,n,1) b[i]=read(),p[b[i]]=i;
	int ans=0;
	F(i,1,n){
		if (p[a[i]]-1-B.s(p[a[i]])!=0) ans++;
		B.add(p[a[i]]); 
	}
	cout<<ans<<"\n";
    return 0;
}