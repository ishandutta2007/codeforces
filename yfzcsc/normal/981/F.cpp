#include<bits/stdc++.h>
#define maxn 1201000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,L,tp;
int lshx[maxn];
int tg[maxn],S1[maxn],S3[maxn],S2[maxn],tg2[maxn];
pii z[maxn],a[maxn],b[maxn];
bool chk(ll _A){
	int tp=0,tp2=0;
	for(int i=1;i<=n*2;++i)z[++tp]=pii(a[i].first,(i>n?i-n:i)*6+a[i].second);
	tp2=tp;
	for(int i=1;i<=n*2;++i)if((ll)b[i].first-_A>=0)
		z[++tp]=pii(b[i].first-_A,(i>n?i-n:i)*6+2+b[i].second);
	inplace_merge(z+1,z+tp2+1,z+tp+1),tp2=tp;
	for(int i=1;i<=n*2;++i)if((ll)b[i].first+_A<2*L)
		z[++tp]=pii(b[i].first+_A,(i>n?i-n:i)*6+4+b[i].second);
	inplace_merge(z+1,z+tp2+1,z+tp+1),tp2=tp;
	int fuck=tp;
	tp=0;
	for(int i=1;i<=fuck;++i)S1[i]=S2[i]=tg[i]=tg2[i]=0;
	for(int i=1;i<=fuck;++i){
		if(i==1||(z[i].first!=z[i-1].first))lshx[++tp]=z[i].first;
		if(z[i].second%6<2)S1[tp]++;
		else if(z[i].second%6==4||z[i].second%6==5)S2[tp]++,tg2[tp]=1;
		else tg[tp]=1;
	}
	int mn=(1<<30);
	for(int i=1;i<=tp;i++)
		S1[i]+=S1[i-1],S2[i]+=S2[i-1];
	for(int i=1,l=1;i<=tp;i++){
		while(l<=tp&&lshx[l]<lshx[i]+2ll*_A)l++;
		if(l<=tp&&tg[i]==1&&lshx[l]==lshx[i]+2ll*_A)S3[i]=-S1[i-1]+S2[l-1];
		else tg[i]=0;
	}
	int ans=0;
	for(int i=1,l=1;i<=tp&&ans>=0;++i){
		while(l<=tp&&lshx[l]+2ll*_A<=lshx[i]){
			if(tg[l]==1)mn=min(mn,S3[l]);
			l++;
		}
		if(tg2[i])ans=min(ans,mn+S1[i]-S2[i]);
//		printf("{%d,%d[%d]}",lshx[i],ans,mn);
	}
	return ans>=0;
}
int R(){
	return rand()<<13|rand();
}
int main(){
	scanf("%d%d",&n,&L);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),a[i]=pii(x,0),a[i+n]=pii(x+L,1);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),b[i]=pii(x,0),b[i+n]=pii(x+L,1);
//	n=2e5,L=1e9;
//	for(int i=1;i<=n;++i)a[i]=pii(R()%L,0),a[i+n]=pii(a[i].first+L,1);
//	for(int i=1;i<=n;++i)b[i]=pii(R()%L,0),b[i+n]=pii(b[i].first+L,1);
	int l=0,r=(L+1)/2,ans=0;
	sort(a+1,a+n*2+1);
	sort(b+1,b+n*2+1);
//	printf("[%d]",chk(14));return 0;
//	for(int i=1;i<=30;++i)printf("[%d]",chk(i));return 0;
	while(l<=r){
		int mid=l+r>>1;
		if(chk(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
}