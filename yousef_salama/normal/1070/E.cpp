#include <bits/stdc++.h>

using namespace std;

template<class INT, int nLeaves>
struct BIT {
  const int kMaxSize = 1 << (int) ceil(log2(nLeaves + 1e-9));
  vector<INT> arr;
  INT size = 0;

  BIT() {
    arr.resize(kMaxSize);
  }

  INT get(int i) {
    i++;
    INT r = 0;
    while (i) {
      r += arr[i - 1];
      i -= i & -i;
    }
    return r;
  }
  
    INT get(int l, int r) {
    if (r < l) return 0;
    if (l == 0) return get(r);
    return get(r) - get(l - 1);
  }


  void add(int i, INT val = 1) {
    size += val;
    i++;
    while (i <= kMaxSize) {
      arr[i - 1] += val;
      i += i & -i;
    }    
  }

  // Finds element at index ind.
  int find(INT ind) {
    int s = 0;
    int m = kMaxSize >> 1;
    while (m) {
      if (arr[s + m - 1] < ind) ind -= arr[(s += m) - 1];
      m >>= 1;
    }
    return s;
  }
};

#define F first
#define S second

const int N=2e5+5;

BIT<int,N> ind;
BIT<long long,N> vals;
pair<int,int> arr[N];
int n,m;
long long t;

int curpv;

int go()
{
  int pos=ind.get(vals.find(t/2+1)-1);
  //if(curpv==7) cout << pos << endl;
  pos/=m; pos*=m;
  long long curd=vals.get(ind.find(pos));
  int npos=ind.get(vals.find(t-curd+1)-1);
  return min(npos,pos+m);
}

int main()
{
  int tc;
  scanf("%d",&tc);
  while(tc--)
  {
    scanf("%d %d %lld",&n,&m,&t);
    for(int i=0;i<n;i++)
    {
      scanf("%d",&arr[i].F);
      arr[i].S=i+1;
    }
    sort(arr,arr+n);
    int d=1,ans=0;
    for(int i=0;i<n;i++)
    {
      if(arr[i].F>t) break;
      vals.add(arr[i].S,arr[i].F);
      ind.add(arr[i].S,1);
      curpv=arr[i].F;
      if(i+1<n&&arr[i].F==arr[i+1].F) continue;
      int mm=go();
      if(mm>ans)
      {
        ans=mm; d=arr[i].F;
      }
    }
    printf("%d %d\n",ans,d);
    for(int i=0;i<n;i++)
    {
      if(arr[i].F>t) break;
      vals.add(arr[i].S,-arr[i].F);
      ind.add(arr[i].S,-1);
    }
  }
}