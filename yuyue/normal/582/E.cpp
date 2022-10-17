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
const int M=(1<<16)+100,mod=1e9+7;
int stk[M],t[M],mc[M];
int n,m,tp;
char ch[M];
void FWTor(LL *f,int op){
	for (int p=2;p<=(1<<m);p<<=1){
		int len=p>>1;
		for (int k=0;k<(1<<m);k+=p){
			for (int l=k;l<k+len;l++){
				f[l+len]=(f[l+len]+mod+op*f[l])%mod;
			}
		}
	}
}
void FWTand(LL *f,int op){
	for (int p=2;p<=(1<<m);p<<=1){
		int len=p>>1;
		for (int k=0;k<(1<<m);k+=p){
			for (int l=k;l<k+len;l++){
				f[l]=(f[l]+mod+op*f[l+len])%mod;
			}
		}
	}
}
LL dp[505][M],ta[M],tb[M];
bool a[4][M],f[M];
void con(int ff,int oa,int ob,bool t){
	ms(ta,0); ms(tb,0);
	F(i,0,(1<<m)-1) ta[i]=dp[oa][i],tb[i]=dp[ob][i];
	if (t) FWTor(ta,1),FWTor(tb,1);
	else FWTand(ta,1),FWTand(tb,1);
	F(i,0,(1<<m)-1) ta[i]=ta[i]*tb[i]%mod;
	if (t) FWTor(ta,-1); else FWTand(ta,-1);
	F(i,0,(1<<m)-1) dp[ff][i]=(dp[ff][i]+ta[i])%mod;
}
void dfs(int l,int r){
//	cout<<l<<" "<<r<<"     GG\n";
	if (l+2==r){
		if (ch[l+1]=='?'){
			F(i,0,3){
				int rev=0,fo=0;
				F(j,0,m-1){
					if (a[i][j]) fo|=(1<<j);
					else rev|=(1<<j);
				}
				dp[l][fo]++; dp[l][rev]++;
			}
		}
		else {
			int o; bool rev=0;
			if (ch[l+1]>='a') o=ch[l+1]-'a',rev=1; 
			else o=ch[l+1]-'A';
			int msk=0;
			F(j,0,m-1){
				if (a[o][j]^rev)  msk|=(1<<j);
			}
			dp[l][msk]++;
		}
		return ;
	}
	dfs(l+1,t[l]);
	dfs(t[r],r-1);
	if (ch[t[l]+1]=='?'){
		con(l,l+1,t[r],1);
		con(l,l+1,t[r],0);
	}
	else {
		con(l,l+1,t[r],(ch[t[l]+1]=='|'));
	}
}
int main(){
	scanf("%s",ch+1);
	n=strlen(ch+1);
	F(i,1,n){
		if (ch[i]=='(') stk[++tp]=i;
		if (ch[i]==')') {
			int x=stk[tp--]; mc[i]=x;	
			if (ch[x-1]=='(' || x==1) t[x-1]=i;
			if (ch[i+1]==')' || i==n) t[i+1]=x;
		}
	}
//	F(i,0,n+1){
//		cout<<t[i]<<" ";
//	}cout<<"\n";
	m=read();
	int msk=0;
	F(i,0,m-1){
		F(j,0,3) a[j][i]=read(); 
		f[i]=read();
		msk|=f[i]<<i;
	}
	dfs(0,n+1);
	cout<<dp[0][msk]<<"\n";
	return 0;
}