#include<bits/stdc++.h>
#include<tr1/unordered_map>
#define maxn 110
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> par;
int n,a[maxn],b[40][maxn];
par lsh[maxn*20];
int tp,tp2;
tr1::unordered_map<ull,int>st;
int solve(int d,int tp){
	int mx=0;
	ull h=0;
	sort(b[d]+1,b[d]+tp+1);
	tp=unique(b[d]+1,b[d]+tp+1)-b[d]-1;
	for(int i=1;i<=tp;++i)
		mx=max(mx,b[d][i]),h=h*19260817+b[d][i]+1;//,printf("[%d]",b[i]);
//	puts("");
//	system("pause");
	if(!mx)return 0;
	if(st.count(h))return st[h];
//	st[h]=0;
//	printf("[%d]",st.size());
	int vis[40]={0};
	for(int i=1;i<=mx;++i){
		for(int j=1;j<=tp;++j){
			b[d+1][j]=b[d][j];
			if(b[d+1][j]>=i)b[d+1][j]-=i;
		}
		vis[solve(d+1,tp)]=1;
	}
	for(int i=0;i<40;++i)if(!vis[i])return st[h]=i;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);//,a[i]=1<<a[i];
//	n=100;
//	srand(time(0));
//	for(int i=1;i<=n;++i)
//		a[i]=1<<(rand()%30);
	for(int i=1;i<=n;++i){
		for(int j=2;j*j<=a[i];++j)if(a[i]%j==0){
			int k=0;
			while(a[i]%j==0)a[i]/=j,k++;
			lsh[++tp]=par(j,k);
		}
		if(a[i]>1)
			lsh[++tp]=par(a[i],1);
	}
	int ans=0;
	sort(lsh+1,lsh+tp+1);
	for(int i=1,j;i<=tp;i=j){
		tp2=0;
		for(j=i;j<=tp&&lsh[j].first==lsh[i].first;j++)
			b[0][++tp2]=lsh[j].second;//,printf("[%d]",lsh[j].second);
		sort(b[0]+1,b[0]+tp2+1),tp2=unique(b[0]+1,b[0]+tp2+1)-b[0]-1;
//		for(int j=1;j<=tp2;++j)printf("[%d]",b[j]);
		int x=solve(0,tp2);
//		printf("[%d]",x);
		ans^=x;
	}
	if(ans)printf("Mojtaba");
	else printf("Arpa");
}