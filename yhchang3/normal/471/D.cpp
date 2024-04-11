#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e6+5;
int z[MAXN];
void Zvalue(vector<int>& s){
   z[0]=s.size();
   int l=0,r=0,x;
   for(int i=1;i<s.size();i++){
      if(r<i||z[i-l]>=r-i+1){
         r<i?x=i:x=r+1;
         while(x<s.size()&&s[x]==s[x-i])  x++;
         z[i]=x-i;if(i<x){l=i;r=x-1;};
      }
      else
         z[i]=z[i-l];
   }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,w;
	cin>>n>>w;
	vector<int> s;
	vector<int> v1(n),v2(w);
	for(int i=0;i<n;i++)
		cin>>v1[i];
	for(int i=0;i<w;i++)
		cin>>v2[i];
	for(int i=1;i<w;i++)
		s.emplace_back(v2[i]-v2[i-1]);
	s.emplace_back(2000000010);
	for(int i=1;i<n;i++)
		s.emplace_back(v1[i]-v1[i-1]);
	Zvalue(s);
	if(w==1)
		cout<<n<<endl;
	else if(w>n)
		cout<<0<<endl;
	else{
		int ans=0;
		for(int i=w;i<s.size();i++)
			ans+=z[i]==(w-1);
		cout<<ans<<endl;
	}
}