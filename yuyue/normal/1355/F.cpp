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
const int M=8888;
const LL lim=1e18;
LL qry[50];
vector<int> v[50];
int ct;
bool p[M];

LL gt(LL x){
	cout<<"? "<<x<<endl;
	cin>>x;
	return x;
}
void solve(){
	LL ans=1; int K=1000000000;
	F(i,1,ct){
		int o=gt(qry[i]),lst;
		F(j,0,SZ(v[i])){
			int pr=v[i][j]; 
			if (o%pr==0){
				LL now=1;
				while (now*pr<=1e9) now*=pr;
				int gg=gt(now);
				int ind=0;
				while (gg%pr==0) gg/=pr,ind++,K/=pr;
				ans*=ind+1;
			}
			lst=v[i][j];
		}

		if (K<1ll*lst*lst*lst){		
			cout<<"! "<<ans*2<<"\n";
			return ;
		}
	}
	ans=max(8ll,ans*2);
	cout<<"! "<<ans<<endl;
}
int main(){
	int N=pow(1e9/2/2,0.3333334);
	//cout<<N<<"\n";
	LL now=1;
	F(i,2,N){
		if (!p[i]){		
			if (1.0*now*i>lim){
				qry[++ct]=now;
				v[ct+1].pb(i);
				now=i;
			}
			else{
				v[ct+1].pb(i);
				now*=i;
			}
		}
		for (int j=i*2;j<=N;j+=i) p[j]=1;
	}
	qry[++ct]=now;
	//cout<<ct<<"\n";
	int T=read();
	while (T--) solve(); 
	return 0; 
}