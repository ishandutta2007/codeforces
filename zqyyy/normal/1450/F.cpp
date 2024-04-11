#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define pii pair<int,int>
#define fi first
#define se second
const int N=3e5+7;
int n,a[N],num[N];
inline void work(){
	n=read();
	for(int i=1;i<=n;i++)num[i]=0;
	for(int i=1;i<=n;i++)a[i]=read(),num[a[i]]++;
	for(int i=1;i<=n;i++)
		if(num[i]>(n+1)/2){puts("-1");return;}
	int pos=1;vector<pii>vec(0);
	for(int i=2;i<=n;i++)
		if(a[i]==a[i-1])vec.emplace_back(a[pos],a[i-1]),pos=i;
	vec.emplace_back(a[pos],a[n]);
	for(int i=1;i<=n;i++)num[i]=0;
	int mx=0,cnt=0;
	for(auto x:vec)if(x.fi==x.se)num[x.fi]++;
	for(int i=1;i<=n;i++)if(num[mx]<=num[i])mx=i;
	for(auto x:vec)cnt+=x.fi!=mx && x.se!=mx;
	printf("%d\n",vec.size()-1+max(0,num[mx]-1-cnt));
	
}
int main(){
	int T=read();
	while(T--)work();
	return 0;
}