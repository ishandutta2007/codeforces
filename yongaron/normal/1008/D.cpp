#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int t;
int dv[100005];
vector<int> p;
bool pr[400];

int gcd(int a, int b)
{
  while(a && b)
  {
    if(a > b)
      a %= b;
    else
      b %= a;
  }
  return a+b;
}

void prep()
{
  for(int i = 2; i < 400; i++)
  {
    pr[i] = true;
    for(int j = 2; j < i; j++)
      if(i%j == 0)
        pr[i] = false;
    if(pr[i])
      p.push_back(i);
  }
  for(int i = 1; i <= 100003; i++)
  {
    int x = i;
    int d = 1;
    int c;
    for(int j = 0; j < p.size(); j++)
    {
      c = 0;
      while(x%p[j] == 0)
      {
        c++;
        x /= p[j];
      }
      d *= c+1;
    }
    if(x > 1)
      d*=2;
    dv[i] = d;
  }
}

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(0);
  prep();
  cin>>t;
  srand(34351);
  int a, b, c;
  int ea, eb, ec, eab, eac, ebc, eabc;
  int da, db, dc, dab, dac, dbc, dabc;
  for(int i = 0; i < t; i++)
  {
    cin>>a>>b>>c;
    int ma = 1000;
    /*a = rand()%ma+1;
    b = rand()%ma+1;
    c = rand()%ma+1;*/
    /*int corr = 0;
    for(int j = 1; j <= ma; j++)
    {
      for(int k = j; k <= ma; k++)
      {
        for(int l = k; l <= ma; l++)
        {
          if(a%j == 0 && b%k == 0 && c%l == 0)
            corr++;
          else if(a%j == 0 && b%l == 0 && c%k == 0)
            corr++;
          else if(a%k == 0 && b%j == 0 && c%l == 0)
            corr++;
          else if(a%k == 0 && b%l == 0 && c%j == 0)
            corr++;
          else if(a%l == 0 && b%j == 0 && c%k == 0)
            corr++;
          else if(a%l == 0 && b%k == 0 && c%j == 0)
            corr++;
        }
      }
    }*/
    ea = dv[a];
    eb = dv[b];
    ec = dv[c];
    eab = dv[gcd(a, b)];
    eac = dv[gcd(a, c)];
    ebc = dv[gcd(b, c)];
    eabc = dv[gcd(a, gcd(b, c))];
    dab = eab-eabc;
    dac = eac-eabc;
    dbc = ebc-eabc;
    dabc = eabc;
    da = ea-eab-eac+eabc;
    db = eb-eab-ebc+eabc;
    dc = ec-eac-ebc+eabc;
    /*cout<<ea<<" "<<eb<<" "<<ec<<" "<<eab<<" "<<eac<<" "<<ebc<<" "<<eabc<<endl;
    cout<<da<<" "<<db<<" "<<dc<<" "<<dab<<" "<<dac<<" "<<dbc<<" "<<dabc<<endl;*/
    int ans = dabc*(dabc-1)*(dabc-2)/6+dabc*(dabc-1)+dabc;
    ans += dabc*(dabc+1)/2*(dab+dac+dbc+da+db+dc);
    ans += dabc*(dab*(dab+1)/2+dac*(dac+1)/2+dbc*(dbc+1)/2);
    ans += dabc*(dab+dac+dbc)*(da+db+dc);
    ans += dabc*(dab*dac+dab*dbc+dac*dbc+da*db+da*dc+db*dc);
    ans += dab*(dab+1)/2*(dc+dac+dbc)+dac*(dac+1)/2*(db+dab+dbc)+dbc*(dbc+1)/2*(da+dab+dac);
    ans += dab*dac*dbc+da*db*dc;
    ans += (dab*dac+dab*dbc+dac*dbc)*(da+db+dc);
    ans += da*db*(dac+dbc)+da*dc*(dab+dbc)+db*dc*(dab+dac);
    /*if(ans != corr)
    {
      cout<<a<<" "<<b<<" "<<c<<endl;
      cout<<ans<<" "<<corr<<endl;
    }*/
    cout<<ans<<endl;
  }
  return 0;
}