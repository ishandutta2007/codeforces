#include<iostream>
#include<cstdio>
#include<algorithm>
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
int f[20],ans,n,m,Right[20],Left[20];
char zs,ch[20][105];
inline void dfs(int p,int pos,int jia){//cout<<p<<" "<<pos<<" "<<jia<<endl;
	if(f[p+1]){
		ans=min(ans,jia+(pos==1?Right[p]:Left[p]));
		return;
	}
	if(pos==1){
		dfs(p+1,1,jia+1+2*Right[p]);
		dfs(p+1,0,jia+m+2);
	}else{
		dfs(p+1,0,jia+1+2*Left[p]);
		dfs(p+1,1,jia+m+2);
	}
}
int main(){
	n=read(); m=read(); ans=1000000;
	for(int i=n;i;i--){scanf("\n%c",&zs);
		for(int j=1;j<=m;j++){scanf("\n%c",&ch[i][j]); if(ch[i][j]=='1')Right[i]=j; if(ch[i][j]=='1'&&Left[i]==0)Left[i]=m-j+1;
	}scanf("\n%c",&zs);}f[n+1]=1;
	for(int i=n;i;i--){f[i]=1;
		for(int j=1;j<=m;j++)if(ch[i][j]=='1')f[i]=0;
		if(!f[i])break;
	}
	dfs(1,1,0);
	cout<<ans<<endl;
}