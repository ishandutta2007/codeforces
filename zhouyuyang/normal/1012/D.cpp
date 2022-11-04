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
const int N=400005;
char s[N],t[N];
vector<int> S,T;
int n,m,xx,yy;
int calc(int n,int m,char x,char y){
	if (n&&m&&x==y) n<m?n++:m++;
	return max(n,m)-1;
} 
int main(){
	scanf("%s%s",s,t);
	int ls=strlen(s);
	int lt=strlen(t);
	s[ls]='#',t[lt]='#';
	For(i,0,ls-1) n+=(i==0||s[i]!=s[i-1]);
	For(i,0,lt-1) m+=(i==0||t[i]!=t[i-1]);
	int ans=calc(n,m,s[0],t[0]);
	for (int i=0,n2=0;i<=ls;i++)
		if (!i||s[i]!=s[i-1]){
			for (int j=0,m2=0;j<=lt;j++)
				if (!j||t[j]!=t[j-1]){
					int n3=n-n2+m2-(j&&t[j-1]==s[i]);
					int m3=m+n2-m2-(i&&s[i-1]==t[j]);
					char x3=(j?t[0]:s[i]),y3=(i?s[0]:t[j]);
					int tmp=1+calc(n3,m3,x3,y3);
					if (tmp<ans) ans=tmp,xx=i,yy=j;
					m2++;
				}
			if (n2++==3) break;
		}
	for (int j=0,m2=0;j<=lt;j++)
		if (!j||t[j]!=t[j-1]){
			for (int i=0,n2=0;i<=ls;i++)
				if (!i||s[i]!=s[i-1]){
					int n3=n-n2+m2-(j&&t[j-1]==s[i]);
					int m3=m+n2-m2-(i&&s[i-1]==t[j]);
					char x3=(j?t[0]:s[i]),y3=(i?s[0]:t[j]);
					int tmp=1+calc(n3,m3,x3,y3);
					if (tmp<ans) ans=tmp,xx=i,yy=j;
					n2++;
				}
			if (m2++==3) break;
		}
	printf("%d\n",ans);
	if (xx||yy){
		static char ss[N],tt[N];
		CPY(ss,s); CPY(tt,t);
		int LS=ls,LT=lt; ls=lt=0;
		For(i,0,yy-1) s[ls++]=tt[i];
		For(i,xx,LS-1) s[ls++]=ss[i];
		For(i,0,xx-1) t[lt++]=ss[i];
		For(i,yy,LT-1) t[lt++]=tt[i];
		printf("%d %d\n",xx,yy);
	}
	For(i,1,ls-1) if (s[i]!=s[i-1]) S.PB(i);
	For(i,1,lt-1) if (t[i]!=t[i-1]) T.PB(i);
	if (ls&&lt&&s[0]==t[0])
		S.size()<T.size()?S.PB(0):T.PB(0);
	sort(S.begin(),S.end());
	sort(T.begin(),T.end());
	for (int i=0,j=0,d=0;i<S.size()||j<T.size();){
		int x=(i==S.size()?ls:S[i]);
		int y=(j==T.size()?lt:T[j]);
		printf("%d %d\n",x+d,y-d); d+=(y-d)-(x+d);
		i+=(i!=S.size()); j+=(j!=T.size());
	}
}