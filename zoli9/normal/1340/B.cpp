#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

bool dp[2009][2009];
int n, k;
int t[2009];
int numbers[10];
int sum[128];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    numbers[0]=(1<<0)+(1<<1)+(1<<2)+(1<<4)+(1<<5)+(1<<6);
    numbers[1]=(1<<2)+(1<<5);
    numbers[2]=(1<<0)+(1<<2)+(1<<3)+(1<<4)+(1<<6);
    numbers[3]=(1<<0)+(1<<2)+(1<<3)+(1<<5)+(1<<6);
    numbers[4]=(1<<1)+(1<<2)+(1<<3)+(1<<5);
    numbers[5]=(1<<0)+(1<<1)+(1<<3)+(1<<5)+(1<<6);
    numbers[6]=(1<<0)+(1<<1)+(1<<3)+(1<<4)+(1<<5)+(1<<6);
    numbers[7]=(1<<0)+(1<<2)+(1<<5);
    numbers[8]=(1<<0)+(1<<1)+(1<<2)+(1<<3)+(1<<4)+(1<<5)+(1<<6);
    numbers[9]=(1<<0)+(1<<1)+(1<<2)+(1<<3)+(1<<5)+(1<<6);
    dp[0][0]=true;
    sum[0]=0;
    for(int i=1; i<128; i++)
    {
      sum[i]=sum[i/2];
      if(i%2==1) sum[i]++;
    }
    for(int i=n; i>=1; i--)
    {
      for(int j=0; j<7; j++)
      {
        char ccc;
        cin>>ccc;
        if(ccc=='1') t[i]+=(1<<j);
      }
    }
    for(int i=1; i<=n; i++)
    {
      for(int j=0; j<=k; j++)
      {
        dp[i][j]=false;
        for(int dig=0; dig<10; dig++)
        {
          if((numbers[dig]&t[i])!=t[i]) continue;
          int pl=sum[numbers[dig]-t[i]];
          if(pl>j) continue;
          if(dp[i-1][j-pl])
          {
            dp[i][j]=true;
            break;
          }
        }
      }
    }
    if(!dp[n][k])
    {
      cout<<-1<<endl;
      return 0;
    }
    for(int i=n; i>=1; i--)
    {
      for(int dig=9; dig>=0; dig--)
        {
          if((numbers[dig]&t[i])!=t[i]) continue;
          int pl=sum[numbers[dig]-t[i]];
          if(pl>k) continue;
          if(dp[i-1][k-pl])
          {
            cout<<dig;
            k-=pl;
            break;
          }
        }
    }


    return 0;
}