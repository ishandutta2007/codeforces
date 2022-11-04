#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
inline int read(){
	int x=0;char c=getchar();bool f=0;
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';x=(x<<1)+(x<<3)+c-'0',c=getchar());
	return f?-x:x;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+48);
}
string ans="",f[15];
int n,m;
ll g[205],k;
const ll MAX=1e18+1;
bool pre(int n,const string &s,int st,ll len){
	int id=n<=14?n:14-(n&1);
	return len<=f[id].length()&&f[id].compare(0,len,s,st,len)==0;
}
bool suf(int n,const string &s,int st,ll len){
	int id=min(n,14);
	return len<=f[id].length()&&f[id].compare(f[id].length()-len,len,s,st,len)==0;
}
ll calc(int n,const string &s){
	for(int i=0;i<=n;++i){
		if(i<=1){
			g[i]=f[i]==s?1:0;
			continue;
		}
		g[i]=g[i-1]+g[i-2];
		int len=s.length();
		for(int j=1;j<len;++j)
			if(suf(i-2,s,0,j)&&pre(i-1,s,j,len-j))++g[i];
		g[i]=min(g[i],MAX);
	}
	return g[n];
}
int main(){
	f[0]="0";f[1]="1";
	for(int i=2;i<=14;++i)f[i]=f[i-2]+f[i-1];
	cin>>n>>k>>m;
	for(int i=1;i<=m;++i){
		ll _0=calc(n,ans+'0');
		int exact=ans!=""&&suf(n,ans,0,ans.length());
		if(k<=exact)break;
		else if(k<=exact+_0){
			k-=exact;
			ans+='0';
		}else{
			k-=exact+_0;
			ans+='1';
		}
	}
	cout<<ans<<endl;
}