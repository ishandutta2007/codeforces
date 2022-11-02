#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
int db[200009];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int test;
	cin>>test;
	while(test--)
	{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
      db[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
      int x;
      cin>>x;
      db[x]++;
    }
    int maxi=0;
    int df=0;
    for(int i=1; i<=n; i++)
    {
      maxi=max(maxi, db[i]);
      if(db[i]>0) df++;
    }
    if(maxi>df) cout<<df<<'\n';
    else if(maxi==df)
    {
      cout<<maxi-1<<'\n';
    }
    else
    {
      cout<<maxi<<'\n';
    }
	}
	return 0;
}