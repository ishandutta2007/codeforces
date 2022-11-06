#include<iostream>

using namespace std;

long long n, m;
long long p[123456], a[123456];
long long sum = 0;

int main(int argc, char const *argv[]) {
  cin>>n>>m;
  for(int i = 0; i < m; i++)
  {
    cin>>p[i];
    if(n - p[i] < i)
    {
      cout<<-1<<endl;
      return 0;
    }
    sum += p[i];
  }
  if(sum < n)
  {
    cout<<-1<<endl;
    return 0;
  }
  sum = n;
  sum -= m;
  sum -= p[m-1]-1;
  a[m-1] = n-p[m-1]+1;
  for(int i = m-2; i >= 0; i--)
  {
    int shift = min(p[i]-1, sum);
    sum -= shift;
    a[i] = a[i+1]-1-shift;
  }
  for(int i = 0; i < m; i++)
    cout<<a[i]<<" ";
  cout<<endl;
  return 0;
}