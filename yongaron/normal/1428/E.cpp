#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

#define ll long long

using namespace std;

int n, k;

ll sum = 0;

ll a[123456];

priority_queue<pair<ll, int>> pq;
ll cuts[123456];

ll cost(ll a, ll c)
{
    ll s = 0;
    ll len = a/(c+1);
    ll longer = a-(c+1)*len;
    s += longer*(len+1)*(len+1);
    s += (c+1-longer)*(len)*(len);
    return s;
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>k;
  for(int i = 0; i < n; i++)
  {
    cin>>a[i];
    ll diff = cost(a[i], cuts[i])-cost(a[i], cuts[i]+1);
    pq.push({diff, i});
  }
  for(int i = n; i < k; i++)
  {
    int ind = pq.top().second;
    pq.pop();
    cuts[ind]++;
    ll diff = cost(a[ind], cuts[ind])-cost(a[ind], cuts[ind]+1);
    pq.push({diff, ind});
  }
  for(int i = 0; i < n; i++)
  {
    sum += cost(a[i], cuts[i]);
  }
  cout<<sum<<endl;
  return 0;
}