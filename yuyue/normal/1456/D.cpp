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
#define int LL 
const int M=5050;
struct node{
	LL x,t;
}a[M];
bool cmp(node A,node B){
	return A.t<B.t;
}
int n;
const LL inf=1e15;
LL dp[M][2];//0 this one 1 one bef
bool run(int pos,int i,int tim){
	F(j,i,n){
		int dur=abs(pos-a[j].x);
		if (dur+tim>a[j].t) return 0;
		pos=a[j].x;
		tim=a[j].t;
	}
	return 1;
}
signed main(){
	n=read();
	F(i,1,n){
		a[i].t=read();
		a[i].x=read();
	}
	sort(a+1,a+n+1,cmp);
	dp[0][0]=0;
	dp[0][1]=inf;
	F(i,1,n){
		dp[i][0]=dp[i][1]=inf;
		int pos=a[i].x;
		bool fg=0;
		bool bad=0;
		DF(j,i-1,0){
			if (min(dp[j][1],dp[j][0])>a[j].t) continue;
			if (bad) break;
//			cout<<j<<" -> "<<i<<"\n";
			if (j==i-1){
				LL cost=dp[j][0]+abs(a[j].x-pos);
				if (j) cost=min(cost,dp[j][1]+abs(a[j-1].x-pos));
				cost=max(a[j].t,cost);
				if (cost<=a[i].t) dp[i][0]=min(dp[i][0],cost);
			}
			else{
				if (j+2<=i-1){
					bad|=(a[j+1].t+abs(a[j+1].x-a[j+2].x)>a[j+2].t);
					fg|=(a[j+1].t+abs(a[j+1].x-pos)+abs(pos-a[j+2].x)<=a[j+2].t);
				}
				bool ok=fg;
				LL cost=dp[j][0]+abs(a[j].x-a[j+1].x);
				if (j) cost=min(cost,dp[j][1]+abs(a[j-1].x-a[j+1].x));
//				if (i==3 && j==0)cout<<bad<<" "<<cost<<" "<<a[j+1].t<<"\n";
				if (bad || cost>a[j+1].t) continue;
				
				cost=dp[j][0]+abs(a[j].x-pos);
				if (j) cost=min(cost,dp[j][1]+abs(a[j-1].x-pos));
				cost=max(cost,a[j].t);
				cost+=abs(pos-a[j+1].x);
				ok|=(cost<=a[j+1].t);
				
//				if (i==3 && j==0){
//					cout<<"fk\n";
//				}
				if (ok) dp[i][1]=min(dp[i][1],a[i-1].t);
				
				int o=a[i-1].t+abs(a[i-1].x-a[i].x);
				if (o<=a[i].t) dp[i][0]=min(dp[i][0],o);
			}
		}
		if (dp[i-1][0]<=a[i-1].t){
			if (run(a[i-1].x,i,dp[i-1][0])){
				cout<<"YES\n";
				return 0; 
			}
		}
		if (dp[i-1][1]<=a[i-1].t){
			if (run(a[i-2].x,i,dp[i-1][1])){
				cout<<"YES\n";
				return 0; 
			}
		}
//		cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<"   gg\n";
	}
	if (dp[n][0]<=a[n].t || dp[n][1]<=a[n].t){
		cout<<"YES\n";
	}
	else cout<<"NO\n";
	return 0;
}