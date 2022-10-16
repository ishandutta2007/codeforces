#include <bits/stdc++.h>
using namespace std;
int n, l;
int x[1001];
int b[1001];
double f[1001];
int trace[1001];
int main(){
	cin>>n>>l;
	for(int i=1; i<=n; i++) cin>>x[i]>>b[i];
	double low=0, high=1e18, mid;
	for(int pre=0; pre<100; pre++){
		mid=(low+high)/2;
		f[0]=0;
		for(int i=1; i<=n; i++) f[i]=1e18;
		for(int i=0; i<n; i++) for(int j=i+1; j<=n; j++){
			auto value=f[i]+sqrt(abs(x[j]-x[i]-l))-mid*b[j];
			if(f[j]>value){
				f[j]=value;
				trace[j]=i;
			}
		}
		if(f[n]<0) high=mid;
		else low=mid;
	}
	vector <int> ans;
	ans.push_back(n);
	while(trace[ans.back()]) ans.push_back(trace[ans.back()]);
	reverse(ans.begin(), ans.end());
	for(auto &x: ans) cout<<x<<' ';
}