#include <bits/stdc++.h>
#define SIZE 20
#define MX 100005
#define BT (1<<16)

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

vector <int> vec[SIZE];
ll cnt[SIZE];
int ma[MX];
int to[MX],col[MX];
bool use[SIZE];
vector <int> memo[BT];
bool dp[BT];
int back[BT];
int ans1[SIZE],ans2[SIZE];

int main()
{
	int k;
	scanf("%d",&k);
	set <P> st;
	set <P>::iterator it;
	ll sum=0;
	int sz=0;
	for(int i=0;i<k;i++)
	{
		int n;
		scanf("%d",&n);
		cnt[i]=0;
		for(int j=0;j<n;j++)
		{
			int a;
			scanf("%d",&a);
			cnt[i]+=a;
			vec[i].push_back(a);
			sum+=a;
			to[sz]=-1;
			col[sz]=i;
			ma[sz]=a;
			st.insert(P(a,sz++));
		}
	}
	if(abs(sum)%k!=0)
	{
		puts("No");
		return 0;
	}
	sum/=k;
	sz=0;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			ll a=vec[i][j];
			a+=sum-cnt[i];
			it=st.lower_bound(P(a,-1));
			if(it!=st.end()&&it->first==a) to[sz]=it->second;
			sz++;
		}
	}
	for(int i=0;i<sz;i++)
	{
		int now=i;
		memset(use,false,sizeof(use));
		bool up=true;
		vector <int> vx;
		do
		{
			vx.push_back(now);
			if(now==-1||use[col[now]])
			{
				up=false;
				break;
			}
			use[col[now]]=true;
			now=to[now];
		}while(now!=i);
		if(up)
		{
			int bit=0;
			for(int j=0;j<k;j++) if(use[j]) bit|=(1<<j);
			memo[bit]=vx;
		}
	}
	memset(dp,false,sizeof(dp));
	dp[0]=true;
	for(int S=0;S<1<<k;S++)
	{
		if(!dp[S]) continue;
		int T=(1<<k)-S-1;
		for(int U=T;U>0;U=(U-1)&T)
		{
			if(memo[U].empty()) continue;
			back[S|U]=U;
			dp[S|U]=true;
		}
	}
	if(!dp[(1<<k)-1])
	{
		puts("No");
		return 0;
	}
	int now=(1<<k)-1;
	while(now>0)
	{
		int bit=back[now];
		now-=bit;
		for(int i=0;i<memo[bit].size();i++)
		{
			int t=memo[bit][i];
			ans1[col[to[t]]]=ma[to[t]];
			ans2[col[to[t]]]=col[t];
		}
	}
	puts("Yes");
	for(int i=0;i<k;i++) printf("%d %d\n",ans1[i],ans2[i]+1);
	return 0;
}