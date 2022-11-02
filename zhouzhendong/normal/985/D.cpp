#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=x*10+ch-48,ch=getchar();
	return x;
}
LL n,H;
LL f(LL x){
	return x*(x+1)/2;
}
bool check(int x){
	if (x<=H)
		return f(x)>=n;
	else {
		LL y=x-H;
		LL top=H+y/2;
		LL v=f(top)*2-f(H-1);
		if (y%2==0)
			v-=top;
		return v>=n;
	}
}
LL findx(LL n){
	LL L=1,R=2e9,mid,ans=R;
	while (L<=R){
		mid=(L+R)>>1;
		if (check(mid))
			R=mid-1,ans=mid;
		else
			L=mid+1;
	}
	return ans;
}
int main(){
	n=read();
	H=read();
	LL x=findx(n);
	printf("%I64d",x);
	return 0;
}