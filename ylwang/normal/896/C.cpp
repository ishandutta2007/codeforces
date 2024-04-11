#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
using namespace std;

//
template<typename _Tp>
struct chtholly_node
{
  typedef _Tp value;
  mutable int l, r;
  mutable value v;
  chtholly_node(int L, int R, value x) : l(L), r(R), v(x) { }
  bool operator<(const chtholly_node& x) const { return l < x.l; }
};

//
template<typename _Tp>
struct chtholly_tree : public set<chtholly_node<_Tp> >
{
  typedef _Tp value;
  typedef chtholly_node<value> node;
  typedef typename set<chtholly_node<value> >::iterator it;

  //
  it split(int pos)
  {
    it itl = this->lower_bound(node(pos, -1, value()));
    if(itl != this->end() && itl->l == pos) return itl; --itl;
    it itr = this->insert(node(pos, itl->r, itl->v)).first; itl->r = pos - 1;
    return itr;
  }
  void assign(int l, int r, value x)
  {
    it itl = this->split(l), itr = this->split(r + 1);
    this->erase(itl, itr); this->insert(node(l, r, x));
  }
};

//
typedef long long value;
typedef chtholly_tree<value> tree; typedef tree::node node; typedef tree::it it;
tree T;

//
void add(int l, int r, value x)
{
  it itl = T.split(l), itr = T.split(r + 1);
  for(; itl != itr; ++itl) itl->v += x;
}
void change(int l, int r, value x)
{ T.assign(l, r, x); }
value select(int l, int r, value x)
{
  it itl = T.split(l), itr = T.split(r + 1);
  vector<pair<value, int> > vp;
  for (; itl != itr; ++itl)
    vp.push_back(pair<value, int>(itl->v, itl->r - itl->l + 1));
  std::sort(vp.begin(), vp.end());
  for(vector<pair<value, int> >::iterator it = vp.begin(); it != vp.end(); ++it)
    if((x -= it->second) <= 0)
      return it->first;
  return -1;
}
value pow(value x, value y, value m)
{
  value res = 1, ans = x % m;
  while(y)
  {
    if(y & 1) res = res * ans % m;
    ans = ans * ans % m;
    y >>= 1;
  }
  return res;
}
value sum(int l, int r, value x, value y)
{
  it itl = T.split(l), itr = T.split(r + 1);
  value res = 0;
  for(; itl != itr; ++itl)
    res = (res + (itl->r - itl->l + 1) * pow(itl->v, x, y)) % y;
  return res;
}

value n, m, seed, vmax;
value rnd()
{ value ret = seed; seed = (seed * 7 + 13) % 1000000007; return ret; }

int main(int argc, char* argv[])
{
  cin >> n >> m >> seed >> vmax;
  value op, l, r, x, y;

  //
  for(int i = 1; i <= n; i++) T.insert(node(i, i, rnd() % vmax + 1));

  for(int i = 1; i <= m; i++)
  {
    op = rnd() % 4 + 1; l = rnd() % n + 1; r = rnd() % n + 1;
    if(l > r) swap(l, r);
    if(op == 3) x = rnd() % (r - l + 1) + 1;
    else x = (rnd() % vmax) + 1;
    if(op == 4) y = rnd() % vmax + 1;
    switch(op)
    {
    case 1:
      add(l, r, x);
      break;
    case 2:
      change(l, r, x);
      break;
    case 3:
      cout << select(l, r, x) << endl;
      break;
    case 4:
      cout << sum(l, r, x, y) << endl;
      break;
    }
  }
  return 0;
}