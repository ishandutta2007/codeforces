#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> inp(n);
	for(int i=0;i<n;i++)
		cin>>inp[i];
	int count = 0;
	for(int i=0;i<n;i++)
		if(inp[i]<=k)
			count++;
		else
			break;
	int ans=count;
	for(int i=n-1;i>count;i--)
		if(inp[i]<=k)
			ans++;
		else
			break;
	cout<<ans<<endl;
}