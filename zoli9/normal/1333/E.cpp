#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef vector<int> vi;
int n;

vector<vector<int>> v3={
  {2, 8, 7}, 
  {3, 1, 6},
  {4, 5, 9}
};

vector<vector<int>> v4={
  {4, 3, 6, 12}, 
  {7, 5, 9, 15},
  {14, 1, 11, 10}, 
  {13, 8, 16, 2}
};

vector<vector<int>> v5={
  {13, 12, 15, 21, 1}, 
  {16, 14, 18, 24, 2},
  {23, 10, 20, 19, 3}, 
  {22, 17, 25, 11, 4},
  {8, 9, 7, 6, 5}
};

vector<vector<int>> v6={
  {6, 5, 4, 3, 2, 1}, 
  {7, 16, 17, 20, 19, 18},
  {8, 15, 24, 23, 26, 32}, 
  {9, 14, 27, 25, 29, 35},
  {10, 13, 34, 21, 31, 30},
  {11, 12, 33, 28, 36, 22}
};

int t[509][509];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  if(n<3)
  {
    cout<<-1<<'\n';
    return 0;
  }
  if(n==3)
  {
  for(vi w: v3)
  {
    for(int u: w) cout<<u<<" ";
    cout<<'\n';
  }
  return 0;
  }
  if(n==4)
  {
  for(vi w: v4)
  {
    for(int u: w) cout<<u<<" ";
    cout<<'\n';
  }
  return 0;
  }
  if(n==5)
  {
  for(vi w: v5)
  {
    for(int u: w) cout<<u<<" ";
    cout<<'\n';
  }
  return 0;
  }
  if(n==6)
  {
  for(vi w: v6)
  {
    for(int u: w) cout<<u<<" ";
    cout<<'\n';
  }
  return 0;
  }
  int cnt=1;
  int id=5;
  if(n%2==0) id=6;
  for(int j=1; j<=n-id; j++)
  {
    for(int i=1; i<=n; i++)
    {
      if(j%2==1) t[i][j]=cnt;
      else t[n-i+1][j]=cnt;
      cnt++;
    }
  }
  for(int i=1; i<=n-id; i++)
  {
    for(int j=n-id+1; j<=n; j++)
    {
      if(i%2==1) t[i][j]=cnt;
      else t[i][n-j+n-id+1]=cnt;
      cnt++;
    }
  }
  cnt--;
  for(int i=1; i<=id; i++)
  {
    for(int j=1; j<=id; j++)
    {
      if(n%2==1) t[n-id+i][n-id+j]=cnt+v5[i-1][id-j];
      else t[n-id+i][n-id+j]=cnt+v6[i-1][id-j];
    }
  }
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=n; j++)
    {
      cout<<t[i][j]<<" ";
    }
    cout<<'\n';
  }
  
  return 0;
}