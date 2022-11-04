#include<bits/stdc++.h>
#define pa pair<int,int>
#define S 200000
#define N 400005
using namespace std;
int n,ur[N],ul[N];
int dr[N],dl[N];
vector<pa > v[2];
void Max(int &x,int y){
	x=(x>y?x:y);
}
void Min(int &x,int y){
	x=(x<y?x:y);
}
long long solve(int p){
	memset(ur,0,sizeof(ur));
	memset(ul,60,sizeof(ul));
	for (int i=0;i<v[p].size();i++){
		Max(ur[v[p][i].first],v[p][i].second);
		Min(ul[v[p][i].first],v[p][i].second);
	}
	for (int i=0;i<=400000;i++)
		dl[i]=ul[i],dr[i]=ur[i];
	for (int i=1;i<=400000;i++)
		Min(dl[i],dl[i-1]),Max(dr[i],dr[i-1]);
	for (int i=399999;i>=0;i--)
		Min(ul[i],ul[i+1]),Max(ur[i],ur[i+1]);
	long long ans=0;
	for (int i=0;i<=400000;i++)
		if (i&1) ans+=max(0,min(dr[i],ur[i])/2-max(dl[i],ul[i])/2);
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int x,y; scanf("%d%d",&x,&y);
		if ((x+y)&1) x--,v[1].push_back(pa(x+y+S,x-y+S));
		else v[0].push_back(pa(x+y+S,x-y+S));
	}
	printf("%lld\n",solve(0)+solve(1));
}