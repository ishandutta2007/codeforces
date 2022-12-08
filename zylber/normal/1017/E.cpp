// C++11
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <sys/time.h>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#define GETT(i, j) get(i, j, n, k, board, mask)
typedef long long tint;
using namespace std;

typedef tint tipo;
struct pto{
    tipo x,y;
    pto operator+ (const pto& p)const{
        pto res;
        res.x = x + p.x;
        res.y = y + p.y;
        return res;
    }
    pto operator- (const pto& p)const{
        pto res;
        res.x = x - p.x;
        res.y = y - p.y;
        return res;
    }
    tipo operator* (const pto& p)const{
        return x*p.x + y*p.y;
    }
    tipo operator^ (const pto& p)const{
        return x*p.y - y*p.x;
    }
};
#define sqr(x) (x)*(x)

tint dist2(pto a, pto b) {
	return sqr((a-b).x)+sqr((a-b).y);
}

typedef vector<pto> VP;
pto r;
bool men2(const pto &p1, const pto &p2){
  return (p1.y==p2.y)?(p1.x<p2.x):(p1.y<p2.y);
}
bool operator<(const pto &p1,const pto &p2){
  tipo ar = (p1-r)^(p2-r);
  return(ar==0)?(dist2(p1,r)<dist2(p2,r)):ar>0;
  //< clockwise, >counterclockwise
}

VP chull(VP poly){
  if(poly.size()<3) return poly;
  r = *(min_element(poly.begin(),poly.end(),men2));
  sort(poly.begin(),poly.end());
  int i=0, s;
  VP ch;
  while(i<(int) poly.size()){
    s = ch.size();
    if(s>1 && ((ch[s-1]-ch[s-2])^(poly[i]-ch[s-2]))<=0) //<0 conterclockwise, >0 clockwise, sin el = deja puntos colineares
      ch.pop_back();
    else
      ch.push_back(poly[i++]);
  }
  return ch;
}

tint pmp[100010];
void preMp(vector<vector<tint>>& x){
  tint i=0, j = pmp[0] = -1;
  while(i<(tint)x.size()){
    while(j>-1 && x[i] != x[j]) j = pmp[j];
      pmp[++i] = ++j;
  }
}
bool mp(vector<vector<tint>>& b, vector<vector<tint>>& g){
  preMp(b);
  tint i=0,j=0;
  while(j<(tint)g.size()){
    while(i>-1 && b[i] != g[j]){i = pmp[i];}
    i++; j++;
    if (i>=(tint)b.size()){
      return true;
      i=pmp[i];
    }
  }
  return false;
}

int main() { ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	VP ps1(n);
	VP ps2(m);
	forn(i, n) cin >> ps1[i].x >> ps1[i].y;
	forn(i, m) cin >> ps2[i].x >> ps2[i].y;
	ps1 = chull(ps1);
	ps2 = chull(ps2);
	int k = ps1.size();
	if(k != (int) ps2.size()) {
		cout << "NO" << endl;
		return 0;
	}
	
	vector<vector<tint>> info1(k), info2(k); 
	forn(i, k) {
		info1[i] = {dist2(ps1[i], ps1[(i+1)%k]), dist2(ps1[(i+1)%k], ps1[(i+2)%k]), (ps1[i] - ps1[(i+1)%k]) * (ps1[(i+1)%k] - ps1[(i+2)%k])};
		info2[i] = {dist2(ps2[i], ps2[(i+1)%k]), dist2(ps2[(i+1)%k], ps2[(i+2)%k]), (ps2[i] - ps2[(i+1)%k]) * (ps2[(i+1)%k] - ps2[(i+2)%k])};
	}
	forn(i, k) {
		info1.push_back(info1[i]);
	}
	
	if(mp(info2, info1)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	
}