#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int t[223456];

int thist[123];

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  for(int i = 0; i < n; i++)
    cin>>t[i];
  int s = 0;
  for(int i = 0; i < n; i++)
  {
    s += t[i];
    int sum = s;
    int l = 0;
    for(int j = 100; j > 0; j--)
    {
      if(sum <= m)
        break;
      if(sum-j*thist[j] >= m)
      {
        l += thist[j];
        sum -= j*thist[j];
      }
      else
      {
        int no = (sum-m)/j;
        l += no;
        sum -= no*j;
        if(sum > m)
        {
          l++;
          sum -= j;
        }
      }
    }
    cout<<l<<" ";
    thist[t[i]]++;
  }
  cout<<endl;
  return 0;
}