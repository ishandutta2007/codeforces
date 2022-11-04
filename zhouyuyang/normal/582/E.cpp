#include<bits/stdc++.h>
using namespace std;
const int N=505,M=(1<<16)+5;
const int mo=1000000007;
char s[N];
int w[N],v[N],f[N][M];
int A[M],B[M],C[M];
int n,m,ans,num;
void FWT_OR(int *a,int f){
	for (int i=1;i<1<<16;i<<=1)
		for (int j=0;j<1<<16;j+=(i<<1))
			for (int k=j;k<j+i;k++)
				a[k+i]=(a[k+i]+(!f?a[k]:mo-a[k]))%mo;
}
void FWT_AND(int *a,int f){
	for (int i=1;i<1<<16;i<<=1)
		for (int j=0;j<1<<16;j+=(i<<1))
			for (int k=j;k<j+i;k++)
				a[k]=(a[k]+(!f?a[k+i]:mo-a[k+i]))%mo;
}
int work(int l,int r){
	int x=++num;
	if (l==r){
		for (int i=0;i<4;i++)
			if (s[l]=='?'||s[l]=='A'+i){
				int sta=0;
				for (int t=0;t<16;t++)
					sta|=((t>>i)&1)<<t;
				f[x][sta]++;
			}
		for (int i=0;i<4;i++)
			if (s[l]=='?'||s[l]=='a'+i){
				int sta=0;
				for (int t=0;t<16;t++)
					sta|=(!((t>>i)&1))<<t;
				f[x][sta]++;
			}
		return x;
	}
	int tmp=0,mid,lson,rson;
	for (int i=l;i<=r;i++){
		if (s[i]=='(') tmp++;
		if (s[i]==')'){
			--tmp;
			if (!tmp){
				mid=i+1;
				break;
			}
		}
	}
	lson=work(l+1,mid-2);
	rson=work(mid+2,r-1);
	if (s[mid]=='?'||s[mid]=='|'){
		memcpy(A,f[lson],sizeof(A));
		memcpy(B,f[rson],sizeof(B));
		FWT_OR(A,0); FWT_OR(B,0);
		for (int t=0;t<1<<16;t++)
			C[t]=1ll*A[t]*B[t]%mo;
		FWT_OR(C,1);
		for (int t=0;t<1<<16;t++)
			f[x][t]=(f[x][t]+C[t])%mo;
	}
	if (s[mid]=='?'||s[mid]=='&'){
		memcpy(A,f[lson],sizeof(A));
		memcpy(B,f[rson],sizeof(B));
		FWT_AND(A,0); FWT_AND(B,0);
		for (int t=0;t<1<<16;t++)
			C[t]=1ll*A[t]*B[t]%mo;
		FWT_AND(C,1);
		for (int t=0;t<1<<16;t++)
			f[x][t]=(f[x][t]+C[t])%mo;
	}
	return x;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		for (int j=0;j<4;j++){
			int x;
			scanf("%d",&x);
			w[i]|=x<<j;
		}
		scanf("%d",&v[i]);
	}
	work(1,n);
	for (int t=0;t<1<<16;t++){
		bool ok=1;
		for (int i=1;i<=m;i++)
			if (((t>>w[i])&1)^v[i]){
				ok=0; break;
			}
		if (ok)
			ans=(ans+f[1][t])%mo;
	}
	printf("%d\n",ans);
}