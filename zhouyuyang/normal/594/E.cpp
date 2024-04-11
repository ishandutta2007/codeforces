#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=10000005;
int n,m;
char s[N],ans[N];
int p[N],q[N],tot;
//p: 
void getmn(){
	for (int i=0;i<n;){
		int j=i,k=i+1;
		for (;k<n&&s[j]<=s[k];++k)
			j=(s[j]<s[k]?i:j+1);
		p[tot]=i; q[tot++]=k-j;
		for (;i<=j;i+=k-j);
	}
}
int z[N];//LCP S[i] with S
void init(){
	z[0]=2*n+1;
	for (int i=1,j=0,r=0;i<=2*n;i++){
		z[i]=max(min(r-i,z[i-j]),0);
		for (;s[z[i]]==s[i+z[i]];z[i]++);
		if (i+z[i]>r) r=i+z[j=i];
	}
}
void solve(char *res,int len){
	int k=2*n+1-len,t=z[k];
	strncpy(res,s[t]<s[k+t]?s:(s+k),len);
}
int main(){
	scanf("%s%d",s,&m);
	int l=n=strlen(s);
	reverse(s,s+n);
	reverse_copy(s,s+n,s+n+1);
	s[n]='#'; init(); getmn();
	for (;tot&&m>2;m--){
		tot--;
		strncpy(ans+n-l,s+p[tot],l-p[tot]);
		l=p[tot];
		if (q[tot]==1)
			for (;tot&&q[tot-1]==1;l=p[--tot])
				strncpy(ans+n-l,s+p[tot-1],l-p[tot-1]);
	}
	if (m==1||tot<2) solve(ans+n-l,l);
	else{
		static char tmp[N];
		strcpy(tmp,ans);
		strncpy(ans+n-l,s+p[tot-1],l-p[tot-1]);
		strncpy(tmp+n-l,s+p[tot-2],l-p[tot-2]);
		solve(ans+n-p[tot-1],p[tot-1]);
		solve(tmp+n-p[tot-2],p[tot-2]);
		if (strcmp(tmp,ans)<0) strcpy(ans,tmp);
		int k=0;
		for (int i=1;i<l;i++){
			int a=2*n+1-l+k,t=z[a];
			if (t<i-k){
				if (s[a+t]<s[t]) k=i;
			}
			else{
				t=z[i-k];
				if (s[t]<s[i-k+t]) k=i;
			}
		}
		strncpy(tmp+n-l,s+2*n+1-l,k);
		strncpy(tmp+n-l+k,s,l-k);
		if (strcmp(tmp,ans)<0)
			strcpy(ans,tmp);
	}
	puts(ans);
}