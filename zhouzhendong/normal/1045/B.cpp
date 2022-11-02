#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=200005;
int read(){
	int x=0;
	char ch=getchar();
	while (!isdigit(ch))
		ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}
int n,m;
int a[N];
int T[2]={19260817,65537},mod[2]={998244353,1000000007};
int F[2][N],I[2][N],S[2][N];
int HL[2][N],HR[2][N];
vector <int> ans;
int Pow(int x,int y,int mod){
	int ans=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1)
			ans=1LL*ans*x%mod;
	return ans;
}
int GetHash_L(int t,int L,int R){
	int res=1LL*(HL[t][R]-HL[t][L-1])*I[t][L]%mod[t];
	return (res+mod[t])%mod[t];
}
int GetHash_R(int t,int L,int R){
	L=n-L+1,R=n-R+1,swap(L,R);
	int res=1LL*(HR[t][R]-HR[t][L-1])*I[t][L]%mod[t];
	return (res+mod[t])%mod[t];
}
bool check1(int L,int R){
	int mid=(L+R)/2;
	for (int t=0;t<2;t++){
		int hl=GetHash_L(t,L,mid);
		int hr=GetHash_R(t,mid+((L+R)&1),R);
		hr=((1LL*(a[L]+a[R])*S[t][mid-L]-hr)%mod[t]+mod[t])%mod[t];
		if (hl!=hr)
			return 0;
	}
	return 1;
}
void check2(){
	for (int i=1;i<n;i++)
		if (a[1]+a[i]==a[i+1]+a[n]-m)
			if (check1(1,i)&&check1(i+1,n))
				ans.push_back((a[1]+a[i])%m);
}
int main(){
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		a[i]=read();
	for (int t=0;t<2;t++){
		F[t][0]=I[t][0]=S[t][0]=1;
		int invt=Pow(T[t],mod[t]-2,mod[t]);
		for (int i=1;i<=n;i++){
			F[t][i]=1LL*F[t][i-1]*T[t]%mod[t];
			I[t][i]=1LL*I[t][i-1]*invt%mod[t];
			S[t][i]=(S[t][i-1]+F[t][i])%mod[t];
			HL[t][i]=(1LL*HL[t][i-1]+1LL*F[t][i]*a[i])%mod[t];
			HR[t][i]=(1LL*HR[t][i-1]+1LL*F[t][i]*a[n-i+1])%mod[t];
		}
	}
	ans.clear();
	if (check1(1,n))
		ans.push_back((a[1]+a[n])%m);
	check2();
	sort(ans.begin(),ans.end());
	printf("%d\n",(int)ans.size());
	for (int i=0;i<ans.size();i++)
		printf("%d ",ans[i]);
	return 0;
}