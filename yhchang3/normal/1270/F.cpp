#include<bits/stdc++.h>
using namespace std;

const int blocksize=200;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	vector<int>  one(1);
	s.insert(0," ");
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='1'){
			pre[i]=pre[i-1]+1;
			one.emplace_back(i);
		}
		else
			pre[i]=pre[i-1];
	long long int ans=0;
	one.emplace_back(n+1);
	for(int i=1;i<=blocksize;i++){
		unordered_map<int,int> m;
		m[0]++;
		for(int j=1;j<=n;j++){
			int now=i*pre[j]-j;
			ans+=m[now];
			m[now]++;
		}
	}
	for(int k=1;k*(blocksize+1)<=n;k++){
		for(int i=1;i+k-1<=one.size()-2;i++){
			int j=i+k-1;
			for(int l=0;l<one[i]-one[i-1];l++){
				int lb=max(k*(blocksize+1),l+one[j]-one[i]+1),rb=l+one[j+1]-one[i];
				if(lb>rb)	continue;
				lb--;
				ans+=rb/k-lb/k;
			}
		}
	}
	cout<<ans<<endl;
}