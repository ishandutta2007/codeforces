#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

vi cnt[509];
vi task, z;
int n;
vi answer;

void move(int idx)
{
  answer.push_back(idx+1);
  int a1=z[idx];
  int a2=z[idx+1];
  int a3=z[idx+2];
  z[idx]=a3;
  z[idx+1]=a1;
  z[idx+2]=a2;
  task[z[idx]]=idx;
  task[z[idx+1]]=idx+1;
  task[z[idx+2]]=idx+2;
}

void solve()
{
  z.resize(n);
  for(int i=0; i<n; i++)
  {
    z[task[i]]=i;
  }
  for(int i=n-1; i>=2; i--)
  {
    while(task[i]<i)
    {
      //cout<<i<<" and "<<task[i]<<endl;
      int mmm=task[i];
      if(task[i]==i-1) mmm=i-2;
      move(mmm);
    }
  }
}

int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  int test;
  cin>>test;
  while(test--)
  {
    answer.clear();
    cin>>n;
    for(int i=1; i<=500; i++)
    {
      cnt[i].clear();
    }
    task.clear();
    for(int i=0; i<n; i++)
    {
      int x;
      cin>>x;
      cnt[x].push_back(i);
    }
    int sw1=-1;
    int sw2=-1;
    int inv_num=0;
    for(int i=1; i<=500; i++)
    {
      for(int j=0; j<cnt[i].size(); j++)
      {
        if(j==1)
        {
          sw1=cnt[i][0];
          sw2=cnt[i][1];
        }
        task.push_back(cnt[i][j]);
        for(int x=0; x+1<task.size(); x++)
        {
          if(task[x]>task.back()) inv_num++;
        }
      }
    }
    if(inv_num%2==1)
    {
      if(sw1==-1)
      {
        cout<<-1<<'\n';
        continue;
      }
      for(int i=0; i<n; i++)
      {
        if(task[i]==sw1) task[i]=sw2;
        else if(task[i]==sw2) task[i]=sw1;
      }
    }
    solve();
    cout<<answer.size()<<'\n';
    for(int x: answer) cout<<x<<" ";
    cout<<'\n';
  }
	return 0;
}