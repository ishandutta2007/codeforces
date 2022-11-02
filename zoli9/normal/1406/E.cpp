#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;

vi primes;
bool cmp[100009];

bool outside[100009];
void finalans(int x)
{
  cout<<"C "<<x<<endl;
  fflush(stdout);
  exit(0);
}

int os[100009];;

int eraseask(int x)
{
  for(int i=x; i<=n; i+=x) outside[i]=true;
  cout<<"B "<<x<<endl;
  fflush(stdout);
  int z;
  cin>>z;
  return z;
}

int ask(int x)
{
  cout<<"A "<<x<<endl;
  fflush(stdout);
  int z;
  cin>>z;
  return z;
}

int countin(int x)
{
  int res=0;
  for(int i=x; i<=n; i+=x) if(!outside[i]) res++;
  return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    if(n==1) finalans(1);
    for(int i=2; i<=100000; i++)
    {
      if(cmp[i]) continue;
      if(i<=n) primes.push_back(i);
      for(int j=2*i; j<=100000; j+=i) cmp[j]=true;
    }
    int ps=primes.size();
    int small=min(80, ps);
    int answer=1;
    for(int i=0; i<small; i++)
    {
      eraseask(primes[i]);
      int pp=primes[i];
      while(pp<=n && ask(pp)!=0)
      {
          answer*=primes[i];
          if(((ll)(pp))*primes[i]<=n)
          {
              pp*=primes[i];
          }
          else break;
      }
    }
    int rem=ask(1);
    int step=200;
    int last=small-1;
    for(int i=small; i<ps; i++)
    {
      if(eraseask(primes[i])>1)
      {
          answer*=primes[i];
          finalans(answer);
      }
      rem--;
      if(i==last+step)
      {
        if(ask(1)!=rem)
        {
          //search from last+1 to i
          for(int j=last+1; j<=i; j++)
          {
            if(ask(primes[j])==1)
            {
              answer*=primes[j];
              finalans(answer);
            }
          }
        }
        last=i;
        step--;
      }
    }
    for(int j=last+1; j<ps; j++)
    {
      if(ask(primes[j])==1)
      {
        answer*=primes[j];
        finalans(answer);
      }
    }
    finalans(answer);
    return 0;
}