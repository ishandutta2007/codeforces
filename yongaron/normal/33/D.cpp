#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<bitset>

#define ll long long

using namespace std;

int n, m, k;

bitset<1234> bits[1234];

ll kx[1234], ky[1234];
ll r[1234], cx[1234], cy[1234];

bool isin(int i, int j)
{
  return r[j]*r[j] > (unsigned ll)(kx[i]-cx[j])*(kx[i]-cx[j])+
                      (unsigned ll)(ky[i]-cy[j])*(ky[i]-cy[j]);
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>k;
  for(int i = 0; i < n; i++)
    cin>>kx[i]>>ky[i];
  for(int i = 0; i < m; i++)
    cin>>r[i]>>cx[i]>>cy[i];
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      bits[i][j] = isin(i, j);
  int a, b;
  for(int i = 0; i < k; i++)
  {
    cin>>a>>b;
    cout<<(bits[a-1]^bits[b-1]).count()<<endl;
  }
  return 0;
}