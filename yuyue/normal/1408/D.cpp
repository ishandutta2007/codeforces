#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2020,N=1e6+10;
#define mid (l+r>>1)
#define lc (x<<1)
#define rc (x<<1|1)
int mx[N];
struct node{
	int x,y;
}a[M],b[M];
bool cmp(node A,node B){
	return A.x==B.x ? A.y<B.y : A.x<B.x;
}
int n,m,s[M],tp;
int main(){
	n=read(); m=read();
	F(i,1,n){
		a[i].x=read(); 
		a[i].y=read();
	}
	F(i,1,m) b[i].x=read(),b[i].y=read();
	sort(b+1,b+m+1,cmp);
	F(i,1,m){
		while (tp && b[s[tp]].y<=b[i].y) tp--;
		s[++tp]=i;
	}
//	cout<<tp<<"\n";
//	s[++tp]=
	F(i,1,n){
		F(j,1,tp){
			int r=b[s[j]].x-a[i].x,nd=b[s[j]].y-a[i].y+1;
			if (r>=0){
				mx[r]=max(mx[r],nd);
			}
		}
		int r=b[s[tp]].x-a[i].x+1;
//		mx[r]=max(mx[r],)
	}
	int ans=1e9;
	DF(i,b[s[tp]].x+1,0){
		mx[i]=max(mx[i],mx[i+1]);
		ans=min(ans,mx[i]+i);
	}
	cout<<ans<<"\n";
	return 0;
}