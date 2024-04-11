#include<iostream>
using namespace std;
const int MAX_N=100,MAX_M=10000;

int main(){
	long long int n,m,a[MAX_N+2],t,x,y,z,f[MAX_N+2];
	f[0]=1; f[1]=1;
	for(int i=2;i<=MAX_N;i++)f[i]=(f[i-1]+f[i-2])%1000000000;
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for(int i=0;i<m;i++){
		scanf("%I64d%I64d%I64d",&t,&x,&y);
		if(t==1)a[x]=y;
		else if(t==2){
			long long int ans=0;
			for(int j=0;j<=y-x;j++){
				ans+=f[j]*a[j+x];
				ans%=1000000000;
			}
			printf("%I64d\n",ans);
		}
		else if(t==3){
			scanf("%I64d",&z);
			for(int j=x;j<=y;j++){a[j]+=z; a[j]%=1000000000;}
		}
	}
}