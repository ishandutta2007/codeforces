#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
long long ans;
int sumred,sumblue,n,a[100005],father[100005],rd[100005],co[100005],red[10000005],blue[10000005],sum,oo=10000001;
inline bool dfs(int p,bool color){
	co[p]=color; //cout<<p<<" "<<color<<" "<<co[father[p]]<<endl;
	if(father[p]&&co[father[p]]==-1)dfs(father[p],color^1);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=2;i<=n;i++){father[i]=read(); rd[father[i]]++;}
	memset(co,-1,sizeof(co));
    for(int i=1;i<=n;i++)if(!rd[i])dfs(i,0);
    for(int i=1;i<=n;i++)if(co[i])red[a[i]]++; else {blue[a[i]]++; sum^=a[i];}
    if(!sum){
    	for(int i=1;i<=n;i++)if(co[i])sumred++; else sumblue++;
    	ans=(long long)sumred*(sumred-1)/2+(long long)sumblue*(sumblue-1)/2;
    	for(int i=1;i<oo;i++){
    		ans+=(long long)blue[i]*red[i];}
    	cout<<ans<<endl;
	}else{
		for(int i=1;i<oo;i++){
			if((sum^i)<oo)ans+=(long long)blue[i]*red[sum^i];
		}
		cout<<ans<<endl;
	}
}