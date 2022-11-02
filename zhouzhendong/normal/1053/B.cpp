#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300005;
LL read(){
	LL x=0,f=1;
	char ch=getchar();
	while (!isdigit(ch)&&ch!='-')
		ch=getchar();
	if (ch=='-')
		f=-1,ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+ch-48,ch=getchar();
	return x*f;
}
int n;
LL a[N],s[N],t[N],tot[N][2];
LL cnt1(LL x){
	LL ans=0;
	while (x)
		ans++,x-=x&-x;
	return ans;
}
int main(){
	n=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	memset(tot,0,sizeof tot);
	LL ans=0;
	tot[0][0]=1;
	for (int i=1;i<=n;i++){
		LL C=cnt1(a[i]);
		s[i]=C;
		t[i]=t[i-1]^(s[i]&1);
		tot[i][0]=tot[i-1][0];
		tot[i][1]=tot[i-1][1];
		tot[i][t[i]]++;
		LL Max=C,Tot=0;
		for (int j=i;j>=max(i-60,1);j--){
			Max=max(Max,s[j]);
			Tot+=s[j];
			if (Tot>=Max*2&&(Tot&1)==0)
				ans++;
		}
		if (i>61)
			ans+=tot[i-61-1][t[i]];
	}
	printf("%I64d",ans);
	return 0;
}