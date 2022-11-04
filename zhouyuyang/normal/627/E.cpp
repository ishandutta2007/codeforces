#include<bits/stdc++.h>
using namespace std;
const int N=3005;
struct P{
	int x,y;
}a[N];
bool cmp(P a,P b){
	return a.x>b.x;
}
int h,w,n,k;
long long ans;
int cnt[N],pre[N],nxt[N];
int sum[N],la[N];
int main(){
	scanf("%d%d%d%d",&h,&w,&n,&k);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=h;i++){
		memset(cnt,0,sizeof(cnt));
		memset(pre,0,sizeof(pre));
		memset(nxt,0,sizeof(nxt));
		for (int j=1;j<=n;j++)
			if (a[j].x>=i) cnt[a[j].y]++;
		cnt[0]=1e9;
		int last=0;
		for (int j=1;j<=w;j++)
			if (cnt[j]){
				nxt[last]=j;
				pre[j]=last;
				last=j;
			}
		nxt[last]=w+1;
		pre[w+1]=last;
		int Ans=0;
		for (int j=0;j<=w;j++)
			if (cnt[j]){
				la[j]=j; sum[j]=0;
				for (;sum[j]+cnt[la[j]]<k;){
					sum[j]+=cnt[la[j]];
					la[j]=pre[la[j]];
				}
				Ans+=(nxt[j]-j)*(j-la[j]);
				Ans+=(nxt[j]-j-1)*(nxt[j]-j)/2;
			}
		int tmp=1;
		ans+=Ans;
		for (int j=h;j>i;j--){
			for (;a[tmp].x==j&&tmp<=n;tmp++){
				int yy=a[tmp].y;
				for (int y=pre[yy];y!=w+1&&la[y]<=yy;y=nxt[y]){
					Ans-=(nxt[y]-y)*(y-la[y]);
					Ans-=(nxt[y]-y-1)*(nxt[y]-y)/2;
				}
				cnt[yy]--;
				if (!cnt[yy]){
					pre[nxt[yy]]=pre[yy];
					nxt[pre[yy]]=nxt[yy];
				}
				for (int y=pre[yy];y!=w+1&&la[y]<=yy;y=nxt[y]){
					if (!cnt[y]) continue;
					if (y>=yy&&la[y]<yy) sum[y]--;
					for (;sum[y]+cnt[la[y]]<k;){
						sum[y]+=cnt[la[y]];
						la[y]=pre[la[y]];
					}
					Ans+=(nxt[y]-y)*(y-la[y]);
					Ans+=(nxt[y]-y-1)*(nxt[y]-y)/2;
				}
			}
			ans+=Ans;
		}
	}
	printf("%lld",1ll*h*(h+1)*w*(w+1)/4-ans);
}