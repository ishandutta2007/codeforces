#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string a,b;
	cin>>a>>b;
	int cnt=0;
	for(int i=1;i<b.size();i++)
		if(b[i]!=b[i-1])	cnt++;
	cnt%=2;
	int now=0;
	int ans=0;
	for(int i=0;i<b.size();i++)
		if(a[i]!=b[i])
			now^=1;
	if(!now)	ans++;
	for(int i=1;i+b.size()<=a.size();i++){
		if(cnt)	now^=1;
		if(a[i-1]!=b[0])	now^=1;
		if(a[i+b.size()-1]!=b.back())	now^=1;
		if(!now)	ans++;
	}
	cout<<ans<<endl;
	
}