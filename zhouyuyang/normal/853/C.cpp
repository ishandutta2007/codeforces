#include<bits/stdc++.h>
#define ll long long
#define N 200005
using namespace std;
struct que{int x,y,tg1,tg2,tg3;}q[N*4];
int cnt[N][5],a[N],t[N];
int n,Q,tot,l,r,x,y;
ll ans[N];
bool cmp(que x,que y){
	return x.x<y.x;
}
ll cal(int x){
	return 1ll*x*(x-1)/2;
}
void add(int x){
	for (;x<=n;x+=x&(-x)) t[x]++;
}
int ask(int x){
	int s=0;
	for (;x;x-=x&(-x)) s+=t[x];
	return s;
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=Q;i++){
		ans[i]=cal(n);
		scanf("%d%d%d%d",&x,&l,&y,&r);
		ans[i]-=cal(l-1)+cal(n-r)+cal(x-1)+cal(n-y);
		q[++tot]=(que){x-1,l-1,i,1,1};
		q[++tot]=(que){y,l-1,i,2,-1};
		q[++tot]=(que){x-1,r,i,3,-1};
		q[++tot]=(que){y,r,i,4,1};
		cnt[i][2]=l-1;
		cnt[i][3]=x-1;
		cnt[i][4]=n-r-y;
	}
	sort(q+1,q+tot+1,cmp);
	int j=1;
	for (;j<=tot&&!q[j].x;j++);
	for (int i=1;i<=n;i++){
		add(a[i]);
		for (;j<=tot&&q[j].x==i;j++){
			int tmp=cnt[q[j].tg1][q[j].tg2]+ask(q[j].y)*q[j].tg3;
			ans[q[j].tg1]+=cal(tmp);
		}
	}
	for (int i=1;i<=Q;i++)
		printf("%I64d\n",ans[i]);
}