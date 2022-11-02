#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
LL n;
int ans=0;
int main(){
	n=read();
	while (n>0){
		if (n<10){
			ans+=n;
			break;
		}
		if (n%10<9){
			ans+=n%10+10;
			n=n/10-1;
		}
		else {
			ans+=9;
			n/=10;
		}
	}
	printf("%d",ans);
	return 0;
}