#include<bits/stdc++.h>
#define maxn 501000
using namespace std;
int a[maxn],n,m,b[maxn];
int tp=0,len[maxn];
vector<int> v;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	if(n==1)return printf("1\n%d",(a[1]+a[1])%n),0;
	for(int i=2;i<=n;++i){
		b[++tp]=a[i]-a[i-1];
		if(i!=n)b[++tp]=-1;
	}
//	for(int i=1;i<=tp;++i)printf("{%d}",b[i]);puts("");
	int rig=0,id=0;
	for(int i=1;i<=tp;++i){
		int L=1;
		if(2*id-i>=0)L=max(L,min(rig-i+1,len[2*id-i]));
		while(i-L>=1&&i+L<=tp&&b[i-L]==b[i+L])L++;
		len[i]=L;
		if(rig<i+L-1)rig=i+L-1,id=i;
//		printf("{%d(%d)}",len[i],b[i]);
	}
	int ans=0;
	for(int i=1;i<=tp;++i){
//		if(i%2==1&&len[(i)/2]>=i/2)printf("{OK<%d,%d>}",i,(tp+i)/2+1);
		if(i%2==1&&len[(i)/2]>=i/2&&len[(tp+i)/2+1]>=(tp-i)/2){
//			puts("OK");
			if((a[1]+a[i/2+1])%m==(a[i/2+2]+a[n])%m)
				v.push_back((a[1]+a[i/2+1])%m);
		}
	}
	if(len[(tp+1)/2]>=tp/2+1)
		v.push_back((a[1]+a[n])%m);
	int pos=(tp+3)/2;
//	if(tp==1&&(a[1]+a[1])%m==(a[n]+a[n])%m)v.push_back((a[1]+a[1])%m);
//	else if(tp>1&&(a[1]+a[1])%m==(a[2]+a[n])%m&&(len[pos])>=(tp-pos+1))v.push_back((a[1]+a[1])%m);
	sort(v.begin(),v.end());
	printf("%d\n",v.size());
	for(auto c:v)printf("%d ",c);
}