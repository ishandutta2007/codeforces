#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n;

struct person
{
  char c;
  int s, l, r;
  bool e;
};

struct par
{
  int d, f, s;
};

bool operator<(const par &a, const par &b)
{
  if(a.d == b.d)
    return a.f > b.f;
  return a.d > b.d;
}

person people[223456];

priority_queue<par> pq;

int b, g;

int main(int argc, char const *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i < n; i++)
  {
    cin>>people[i].c;
    if(people[i].c == 'B')
      b++;
    else
      g++;
  }
  for(int i = 0; i < n; i++)
  {
    cin>>people[i].s;
    people[i].l = i-1;
    people[i].r = i+1;
    people[i].e = true;
    if(i && people[i].c != people[i-1].c)
      pq.push({abs(people[i].s-people[i-1].s), i-1, i});
  }
  cout<<min(b, g)<<endl;
  while(!pq.empty())
  {
    par p = pq.top();
    pq.pop();
    if(people[p.f].e && people[p.s].e)
    {
      cout<<p.f+1<<" "<<p.s+1<<endl;
      people[p.f].e = people[p.s].e = false;
      int ll = people[p.f].l;
      int rr = people[p.s].r;
      if(ll != -1)
        people[ll].r = rr;
      if(rr != n)
        people[rr].l = ll;
      if(ll != -1 && rr != n && people[ll].c != people[rr].c)
        pq.push({abs(people[ll].s-people[rr].s), ll, rr});
    }
  }
  return 0;
}