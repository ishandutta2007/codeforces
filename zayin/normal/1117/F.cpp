#include<bits/stdc++.h>
#define maxm 18
#define maxs (1<<18) 
#define maxn 100050
using namespace std;

int n,m,S;
char s[maxn];
int cnt[maxm];

int pre[maxn],pos[maxn];

int ok[maxm],del[maxm][maxs];

int dp[maxs];
int res[maxs],ans=maxn;

int main()	{
	scanf("%d%d%s",&n,&m,s+1),S=1<<m;
	for (int i=0;i<m;++i)	
		pos[i]=i;
	for (int i=1;i<=n;++i)	{
		sort(pos,pos+m,[&](const int& i,const int& j){
			return pre[i]>pre[j];
		});
//		cout<<"pre:"; for (int i=0;i<m;++i)	cout<<pre[i]<<" "; cout<<endl; 
//		cout<<"pos:"; for (int i=0;i<m;++i)	cout<<pos[i]<<" "; cout<<endl; 
		int st=0,c=s[i]-'a';
		for (int j=0;pre[pos[j]]&&j<m;st|=1<<pos[j++])
//			cout<<i<<" "<<c<<":"<<st<<" "<<pos[j]<<endl,
			del[c][st]|=1<<pos[j],del[pos[j]][st]|=1<<c;
		pre[c]=i;
		cnt[c]++;
	}
	for (int i=0;i<m;++i)	{
		for (int a,j=0;j<m;++j)	{
			scanf("%d",&a); 
			ok[i]|=a<<j;
		}
//		cout<<i<<":"<<ok[i]<<endl;
	}
	for (int i=0;i<m;++i)	{
		for (int j=0;j<m;++j)
			for (int s=0;s<S;++s)
				if (s>>j&1)
					del[i][s]|=del[i][s^1<<j];
		for (int s=0;s<S;++s)
			del[i][s]&=~s;
//			cout<<"del["<<i<<"]["<<s<<"]="<<del[i][s]<<endl; 
	}
	
	dp[0]=1;
	for (int s=0;s<S;++s)	{
		for (int i=0;i<m;++i)
			if (~s>>i&1)
				res[s]+=cnt[i];
		if (!dp[s])	continue;
//		cout<<"s:"<<s<<" "<<res[s]<<endl; 
		ans=min(ans,res[s]);
		for (int i=0;i<m;++i)	{
			if (s>>i&1)	continue;
			int t=s^1<<i;
			bool flag=1;
			for (int j=0;j<m;++j)	
				if (~t>>j&1)	{
//					cout<<j<<" "<<del[j][t]<<" "<<ok[j]<<endl;
					if ((del[j][t]|ok[j])!=ok[j])
						flag=0;
				}
//			cout<<s<<" "<<i<<":"<<t<<" "<<flag<<endl;
			dp[t]|=flag;
//			cout<<endl;
		}
	}
	
	printf("%d\n",ans);
	return 0;
}