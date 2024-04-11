
 #include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000005,M=1e9+7;
int n,k,a[N],pre[N],nxt[N],st[N],top;
int calc(int L,int R)
{
	int a=L/k,b=R/k,x=L%k,y=R%k;
	int ans=a+b;
	(ans+=a*k%M*b)%=M;
	(ans+=x*b)%=M;
	(ans+=y*a)%=M;
	if (!x||!y)return ans;
	(ans+=max(0LL,x+y-k+1))%=M;
	return ans;
}
signed main()
{
	scanf("%lld%lld",&n,&k);k--; 
	for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
	a[0]=a[n+1]=1e9+1;st[top=1]=0;
	for (int i=1;i<=n;i++)
	 {
		while (a[i]>=a[st[top]])top--;
		pre[i]=st[top];
		st[++top]=i;
	 }
	st[top=1]=n+1;
	for (int i=n;i;i--)
	 {
		while (a[i]>a[st[top]])top--;
		nxt[i]=st[top];
		st[++top]=i;
	 }
	int ans=0;
	for (int i=1;i<=n;i++)(ans+=calc(i-pre[i]-1,nxt[i]-i-1)*a[i])%=M;
	printf("%lld",ans);
	return 0;
}