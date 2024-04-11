#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
int n, m;
bool col[1000009];
int was[1000009];
int nxt[1000009];
int ccnt[1000009];
vector<vector<bool> > cycles;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test;
	cin>>test;
	while(test--)
	{
    cycles.clear();
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
        char ccc;
        cin>>ccc;
        if(ccc=='0') col[i*m+j]=true;
        else col[i*m+j]=false;
      }
    }
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
        was[i*m+j]=-1;
        ccnt[i*m+j]=0;
        char ccc;
        cin>>ccc;
        if(ccc=='U') nxt[i*m+j]=i*m+j-m;
        if(ccc=='R') nxt[i*m+j]=i*m+j+1;
        if(ccc=='D') nxt[i*m+j]=i*m+j+m;
        if(ccc=='L') nxt[i*m+j]=i*m+j-1;
      }
    }
    int wcnt=-1;
    int ans=0;
    for(int i=0; i<n*m; i++)
    {
      if(was[i]>-1)
      {
        int csize=cycles[was[i]].size();
        if(col[i]) cycles[was[i]][ccnt[i]%csize]=true;
        continue;
      }
      wcnt++;
      int cur=i;
      int j=0;
      vector<int> q;
      while(was[cur]<0)
      {
        q.push_back(cur);
        was[cur]=wcnt;
        ccnt[cur]=j;
        j++;
        cur=nxt[cur];
      }
      if(was[cur]==wcnt)
      {
        vector<bool> ccy(j-ccnt[cur], false);
        cycles.push_back(ccy);
        ans+=(j-ccnt[cur]);
      }
      else
      {
        int x=ccnt[cur];
        int csize=cycles[was[cur]].size();
        for(int u=(int)(q.size())-1; u>=0; u--)
        {
          x=(x+csize-1)%csize;
          ccnt[q[u]]=x;
          was[q[u]]=was[cur];
        }
        wcnt--;
      }
      int csize=cycles[was[i]].size();
      if(col[i]) cycles[was[i]][ccnt[i]%csize]=true;
    }
    int ans2=0;
    for(int i=0; i<cycles.size(); i++)
    {
      for(bool b: cycles[i]) if(b) ans2++;
    }
    cout<<ans<<" "<<ans2<<'\n';
	}
	return 0;
}