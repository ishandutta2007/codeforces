#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

#define int long long
typedef long long LL;
typedef pair<int,int> pii;
const int MAX_N = 2e5 + 6;
const LL mod = 1e9+7;

pii s[MAX_N];
LL dp[MAX_N];
LL poww(LL a,LL n) {
    LL num[40];
    num[0]=a;
    for (int x=1;40>x;x++) {
        num[x] = num[x-1] * num[x-1];
        num[x] %= mod;
    }
    LL ret=1;
    for (int x=0;40>x;x++) {
        if (((1LL<<x) | n) == n) {
        	ret*=num[x];
        	ret%=mod;
        }
    }
    return ret;
}

main()
{
   int n,k;
   while (scanf("%I64d %I64d",&n,&k) != EOF) {
       memset(dp,0,sizeof(dp));
       for (int x=0;k-1>=x;x++) dp[x]=0;
       dp[k]=1;
       for (int x=k+1;n>=x;x++) {
           dp[x] = dp[x-1] * x;
           dp[x] %= mod;
           dp[x] *= poww(x-k,mod-2);
           dp[x] %= mod;
       }
//       for (int x=0;n>=x;x++) cout<<x<<" : "<<dp[x]<<endl;
       for (int x=0;n>x;x++) {
	   		int i,j;
       		scanf("%I64d %I64d",&i,&j);
       		s[x]=make_pair(i,j);
       }
       sort(s,s+n);
       priority_queue<int, vector<int>, greater<int> > que;
       int id=1;
       int cnt=1;
       int sx=s[0].first;
       LL ans=0;
       que.push(s[0].second);
//       for (int x=0;n>x;x++) cout<<s[x].first<<' '<<s[x].second<<endl;
       while (id!=n || !que.empty()) {
//       		cout<<"id="<<id<<" , cnt="<<cnt<<" , sx="<<sx<<", ans="<<ans<<endl;
			if (id==n) {
				int t=que.top();
				que.pop();
				ans+=dp[cnt--] * (t-sx+1);
				ans%=mod;
				while (!que.empty() && que.top()==t) {
					cnt--;
					que.pop();
				}
				sx=t+1;
			}
			else if (que.empty()) {
				ans+=dp[cnt++] * (s[id].first-sx);
				que.push(s[id].second);
				sx=s[id].first;
				int tmp=s[id].first;
				id++;
				while (id!=n && s[id+1].first==tmp) {
					que.push(s[id].second);
					id++,cnt++;
					
				}
				ans%=mod;
			}
			else if (s[id].first<=que.top()) {
				ans+=dp[cnt++] * (s[id].first-sx);
				que.push(s[id].second);
				sx=s[id].first;
				int tmp=s[id].first;
				id++;
				while (id!=n && s[id+1].first==tmp) {
					que.push(s[id].second);
					id++,cnt++;
				}
				ans%=mod;
			}
			else if (s[id].first>que.top()) {
				int t=que.top();
				que.pop();
				ans+=dp[cnt--] * (t-sx+1);
				ans%=mod;
				while (!que.empty() && que.top()==t) {
					cnt--;
					que.pop();
				}
				sx=t+1;
			}
       }
       printf("%I64d\n",ans);
   }
   return 0;
}