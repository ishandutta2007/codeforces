#include<iostream>

using namespace std;

int n, k;

int s, b;
int st, bt;

int main(int argc, char const *argv[]) {
  cin>>n>>k;
  for(int i = 0; i < k+1; i++)
  {
    cout<<"? ";
    for(int j = 0; j < k+1; j++)
      if(j != i)
        cout<<j+1<<" ";
    cout<<endl;
    int x, y;
    cin>>y>>x;
    if(i == 0)
    {
      st++;
      s = x;
    }
    else if(s == x)
      st++;
    else
    {
      b = x;
      bt++;
    }
  }
  if(s < b)
    cout<<"! "<<bt<<endl;
  else
    cout<<"! "<<st<<endl;
  return 0;
}