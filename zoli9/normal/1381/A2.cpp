#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

vi s, z;

int e1;
int e2;
int flipped;
    
int main() {
	ios::sync_with_stdio(false);
  cin.tie(0);
  
  int test;
  cin>>test;
  while(test--)
  {
    int n;
    cin>>n;
    s.resize(n);
    z.resize(n);
    for(int i=0; i<n; i++)
    {
      char ccc;
      cin>>ccc;
      if(ccc=='0') s[i]=0;
      else s[i]=1;
    }
    for(int i=0; i<n; i++)
    {
      char ccc;
      cin>>ccc;
      if(ccc=='0') z[i]=0;
      else z[i]=1;
    }
    vector<int> ans;
    
    e1=0;
    e2=n-1;
    flipped=0;
    for(int i=n-1; i>=0; i--)
    {
      //cout<<e1<<" : "<<e2<<endl;
      if(z[i]==(s[e2]+flipped)%2)
      {
        //cout<<"round "<<i<<endl;
        if(e2>=e1) e2--;
        else e2++;
        continue;
      }
      if((s[e1]+flipped)%2==z[i])
      {
        ans.push_back(0);
        s[e1]=1-s[e1];
      }
      ans.push_back(abs(e2-e1));
      flipped=1-flipped;
      swap(e1, e2);
      if(e2>=e1) e2--;
      else e2++;
    }
    
    cout<<ans.size();
    for(int x: ans) cout<<" "<<x+1;
    cout<<'\n';
  }
	return 0;
}