#include<iostream>
#include<algorithm>
#include<time.h>

using namespace std;

int n, s, x;

int best = -1, bestn;

int main(int argc, char const *argv[]) {
  cin>>n>>s>>x;
  srand(87879);
  bestn = s;
  for(int i = 0; i < 1000; i++)
  {
    int f = (((((long long)rand())<<12)+(long long)rand())%n)+1;
    cout<<"? "<<f<<endl;
    int ans, ansn;
    cin>>ans>>ansn;
    if(ans <= x && ans > best)
    {
      best = ans;
      bestn = ansn;
    }
  }
  if(best >= x)
  {
    cout<<"! "<<best<<endl;
    return 0;
  }
  if(bestn == -1)
  {
    cout<<"! "<<-1<<endl;
    return 0;
  }
  for(int i = 0; i < 999; i++)
  {
    cout<<"? "<<bestn<<endl;
    cin>>best>>bestn;
    if(best >= x)
    {
      cout<<"! "<<best<<endl;
      return 0;
    }
    if(bestn == -1)
    {
      cout<<"! "<<-1<<endl;
      return 0;
    }
  }
  cout<<"! "<<best<<endl;
  return 0;
}