#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long
#define mod 1000000007
using namespace std;
static uint64_t splitmix64(uint64_t x) {
  x += 0x9e3779b97f4a7c15;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
  return x ^ (x >> 31);
}
 
struct my_hash {
  size_t operator()(int x) const {
    return x ^ 152901668;
  }
};
void Onigiri()
{
  int n,m;
  cin>>n>>m;
  int arr[n];
  priority_queue<pair<int,int>,std::vector<pair<int,int>>,greater<pair<int,int>>>l,r;
  unordered_set<int, my_hash> humans,tree;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];tree.insert(arr[i]);
  }
  sort(arr,arr+n);
  for(int i=0;i<n;i++)
  {
    l.push({1,arr[i]-1});
    r.push({1,arr[i]+1});
  }
  long long cnt=0,t=4000005;;
  int inf=200005;
 while(m>0)
  {
   	int ll=l.top().first;
   	int rr=r.top().first;
   	int lp=l.top().second;
   	int rp=r.top().second;
   	//cout<<rp<<" "<<lp<<" "<<endl;
   	if(tree.count(rp)||humans.count(rp)){
   		r.pop();continue;
   	}
   	if(tree.count(lp)||humans.count(lp)){
   		l.pop();continue;
   	}
   	
   	if(rr<=ll)
   	{
   		cnt+=rr;
   		r.pop();m--;
   		humans.insert(rp);
   		r.push({rr+1,rp+1});
   	}
   	else{
   		cnt+=ll;
   		l.pop();m--;
   		humans.insert(lp);
   		l.push({ll+1,lp-1});
   	}
  }
  cout<<cnt<<endl;
  for(auto x:humans)
  {
    cout<<x<<" ";
  }
 
 
 
}
signed main()
{
 
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
  #endif  
  int t=1;
  //cin>>t;
  while(t--)
  {
    Onigiri();
  }
  return 0;
 
}