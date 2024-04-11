#include<bits/stdc++.h>
using namespace std;
const int N=100005,M=333;
priority_queue<int,vector<int>,greater<int> > pq;
int cnt[N],sum[N],a[N];
int b[M],spe[M],GG[N];
int n,Q,tot,S,s[N],ans[N];
struct que{
	int l,r,id;
	friend bool operator <(const que &a,const que &b){
		if (a.l/S!=b.l/S) return a.l/S<b.l/S;
		return a.r<b.r; 
	}
}q[N];
void add(int x){
	if (GG[x]){
		sum[x]++;
		return;
	}
	cnt[sum[x]]--;
	cnt[++sum[x]]++;
}
void del(int x){
	if (GG[x]){
		sum[x]--;
		return;
	}
	cnt[sum[x]]--;
	cnt[--sum[x]]++;
}
int solve(){
	memset(b,0,sizeof(b));
	for (int i=1;i<=S;i++)
		b[i]=cnt[i];
	int ans=0,now=1;
	while (!pq.empty()) pq.pop();
	for (int i=1;i<=tot;i++)
		if (sum[spe[i]]<=S) b[sum[spe[i]]]++;
		else pq.push(sum[spe[i]]);
	for (;;){
		for (;now<=S&&!b[now];now++);
		if (now>S) break;
		if (b[now]>=2){
			if (now*2>S){
				for (;b[now]>=2;b[now]-=2)
					pq.push(2*now),ans+=2*now;
			}
			else{
				ans+=b[now]/2*(2*now);
				b[now*2]+=b[now]/2;
				b[now]&=1;
			}
		}
		if (b[now]){
			int nxt=now+1;
			for (;nxt<=S&&!b[nxt];nxt++);
			if (nxt>S){
				pq.push(now);
				break;
			}
			b[now]--; b[nxt]--;
			ans+=nxt+now;
			if (now+nxt<=S)
				b[nxt+now]++;
			else pq.push(nxt+now);
		}
	}
	for (;pq.size()>1;){
		int x=pq.top(); pq.pop();
		int y=pq.top(); pq.pop();
		ans+=y+x; pq.push(x+y);
	}
	return ans;
}
int main(){
	scanf("%d",&n); S=320;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[a[i]]++;
		if (s[a[i]]==S){
			GG[a[i]]=1;
			spe[++tot]=a[i];
		}
	}
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++)
		scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
	sort(q+1,q+Q+1);
	int l=1,r=0;
	for (int i=1;i<=Q;i++){
		for (;l>q[i].l;add(a[--l]));
		for (;r<q[i].r;add(a[++r]));
		for (;l<q[i].l;del(a[l++]));
		for (;r>q[i].r;del(a[r--]));
		ans[q[i].id]=solve();
	}
	for (int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
}