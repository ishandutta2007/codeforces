#include<cstdio>
#include<iostream>
const int N=300005;
int n,x,y,i,w,s;
char c[N],st[N];
int main(){
	scanf("%d%d%d%s",&n,&x,&y,c+1);
	for(i=1;i<=n;++i)if(!w || c[i]!=st[w])st[++w]=c[i],s+=st[w]=='0';
	long long ans;
	if(!s)ans=0;else if(x<y)ans=1ll*(s-1)*x+y;else ans=1ll*s*y;
	std::cout<<ans;
	return 0;
}