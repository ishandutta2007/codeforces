#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=100005;
int n,m,k,p;
LL h[N],a[N],day[N];
struct cmp{
	bool operator () (int a,int b){
		if (day[a]!=day[b])
			return day[a]>day[b];
		return a>b;
	}
};
priority_queue <int,vector <int>,cmp> S;
LL now[N];
int check(LL x){
	while (!S.empty())
		S.pop();
	For(i,1,n){
		now[i]=x,day[i]=now[i]/a[i];
		S.push(i);
	}
	Fod(d,m,1){
		For(j,1,k){
			int i=S.top();
			S.pop();
			if (day[i]>=m){
				LL rem=k-j+1+(d-1)*k;
				For(i,1,n){
					LL v=now[i]-a[i]*m;
					while (v<h[i]){
						v+=p;
						if (!rem--)
							return 0;
					}
				}
				return 1;
			}
			else if (day[i]<=m-d){
				return 0;
			}
			else {
				now[i]+=p;
				day[i]=now[i]/a[i];
				S.push(i);
			}
		}
	}
	For(i,1,n)
		if (now[i]-a[i]*m<h[i])
			return 0;
	outtag(1);
	return 1;
}
int main(){
	n=read(),m=read(),k=read(),p=read();
	For(i,1,n)
		h[i]=read(),a[i]=read();
	LL L=0,R=1e15,mid,ans=R;
	while (L<=R){
		mid=(L+R)>>1;
		if (check(mid))
			R=mid-1,ans=mid;
		else
			L=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}