#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a[202000],pre[202000],nex[202000],pmo[202000],emo[202000],now;
struct P{
	int val,id;
}p[202000];
ll ans=0;

bool cmp(P p1,P p2){
	return p1.val>p2.val;
}

void doit(int x){
	int q1=pre[x],q2=nex[x];
	//printf(" %d %d %d  %d %d ",x,q1,q2,pmo[x],emo[x]);
	ans+=(ll)(x-q1)*(q2-x);
	q1=max(q1,pmo[x]);
	q2=min(q2,emo[x]);
	ans-=(ll)(x-q1)*(q2-x);
	//printf("--%lld\n",ans);
}

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[i].val=a[i];
		p[i].id=i;
		pmo[i]=0;
		emo[i]=n+1;
	}
	
	for (now=0;now<30;now++){
		pre[0]=0;
		for (int i=1;i<=n;i++){
			if (a[i]&(1<<now)){
				pre[i]=i;
			}else{
				pre[i]=pre[i-1];
				pmo[i]=max(pmo[i],pre[i]);
			}
		}
		
		nex[n+1]=n+1;
		for (int i=n;i>0;i--){
			if (a[i]&(1<<now)){
				nex[i]=i;
			}else{
				nex[i]=nex[i+1];
				emo[i]=min(emo[i],nex[i]);
			}
		}
	}
	
	sort(p+1,p+n+1,cmp);
	for (int i=1;i<=n;i++){
		pre[i]=i-1;
		nex[i]=i+1;
	}
	nex[0]=1; pre[n+1]=n;
	
	int now;
	for (int i=n;i>0;i--){
		now=p[i].id;
		nex[pre[now]]=nex[now];
		pre[nex[now]]=pre[now];
	}
	
	for (int i=1;i<=n;i++){
		now=p[i].id;
		nex[pre[now]]=now;
		pre[nex[now]]=now;
		doit(now);
	}
	
	cout<<ans;
}