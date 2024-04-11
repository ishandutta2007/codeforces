#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>ans;

int doit(int x){
	int res=x;
	for (;x;x/=10) res+=x%10;
	return res;
}

int main(){
	cin>>n;
	for (int i=max(1,n-2333);i<n;i++){
		if (doit(i)==n)
			ans.push_back(i);
	}
	printf("%d\n",(int)ans.size());
	for (int i=0;i<(int)ans.size();i++) printf("%d ",ans[i]);
}