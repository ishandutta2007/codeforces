#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m,k;
bool vis[N],w[N];
int q[N];
bool connect(){
	int h=0,t=1,cnt=0;
	memset(vis,0,sizeof(vis));
	for (int i=1;i<=n*m;i++)
		if (w[i]) q[1]=i,cnt++;
	while (h!=t){
		int x=q[++h];
		if (x+m<=n*m&&w[x+m]&&!vis[x+m])
			vis[x+m]=1,cnt--,q[++t]=x+m;
		if (x>m&&w[x-m]&&!vis[x-m])
			vis[x-m]=1,cnt--,q[++t]=x-m;
		if (x%m&&w[x+1]&&!vis[x+1])
			vis[x+1]=1,cnt--,q[++t]=x+1;
		if ((x-1)%m&&w[x-1]&&!vis[x-1])
			vis[x-1]=1,cnt--,q[++t]=x-1;
	}
	return cnt==0;
}

int count(){
	int ans=0;
	for (int i=1;i<=(n-1)*m;i++)
		if (i%m){
			ans+=w[i]&w[i+1]&w[i+m];
			ans+=w[i]&w[i+1]&w[i+m+1];
			ans+=w[i]&w[i+m]&w[i+m+1];
			ans+=w[i+1]&w[i+m]&w[i+m+1];
		}
	return ans;
}
int calc(int mid){
	for (int i=1;i<=n*m;i++)
		w[i]=(i<=mid);
	return count();
}

vector<int> p1,p2;
int work(){
	int c=4*(n-1)*(m-1);
	if (k>c) return 0;
	if (k==c-1||k==c-2||k==c-4||k==c-5) return 0;
	if (k==c-8&&n!=3&&m!=3) return 0;
	int l=0,r=n*m,ans;
	while (l<=r){
		int mid=(l+r)/2;
		if (calc(mid)<=k)
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	int cur=calc(ans);
	if (cur==k) return 1;
	p1.clear(); p2.clear();
	for (int i=1;i<=n*m;i++)
		if (min((i-1)/m,abs((i-1)/m-(ans-1)/m))<=1)
			w[i]?p1.push_back(i):p2.push_back(i);
	for (;cur!=k;){
		int at,x;
		if (cur<k){
			at=rand()%(p2.size());
			x=p2[at]; w[x]=1;
			if (!connect()){
				w[x]=0; continue;
			}
			p2.erase(p2.begin()+at);
			p1.push_back(x);
			cur=count();
		}
		else{
			at=rand()%(p1.size());
			x=p1[at]; w[x]=0;
			if (!connect()){
				w[x]=1; continue;
			}
			p1.erase(p1.begin()+at);
			p2.push_back(x);
			cur=count();
		}
	}
	return 1;
}
void solve(){
	scanf("%d%d%d",&n,&m,&k);
	int fl=(n<m);
	if (fl) swap(n,m);
	if (!work()) puts("-1");
	else if (fl==0)
		for (int i=1;i<=n;i++,puts(""))
			for (int j=1;j<=m;j++)
				printf("%c",w[(i-1)*m+j]?'*':'.');
	else
		for (int i=1;i<=m;i++,puts(""))
			for (int j=1;j<=n;j++)
				printf("%c",w[i+(j-1)*m]?'*':'.');
}
int main(){
	srand(19260817);
	int T; scanf("%d",&T);
	while (T--) solve(),puts("");
}