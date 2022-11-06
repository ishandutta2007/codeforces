#include<stdio.h>
#include<deque>
#define div(a,b) ((a+b-1)/b)
#define mod(a,b) ((a+b-1)%b+1)
inline long long Max(long long a,long long b){return a>b?a:b;}
long long a[1000002],m,k,ans=0;
int n;std::deque<long long>Q[11];
int main(){
	scanf("%d%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(int i=0;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(!Q[j].empty()){
				ans=Max(ans,a[i]-Q[j].front()-(div(i,m)+(mod(i,m)>j))*k);
			}
		}int t=mod(i,m);long long val=a[i]-div(i,m)*k;
		while(!Q[t].empty()&&Q[t].back()>=val)Q[t].pop_back();
		Q[t].push_back(val);
	}printf("%lld",ans);
}