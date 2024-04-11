#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n%2==0){
		cout<<"-1\n";
		return 0;
	}
	else{
		vector <int> a;
		vector <int> b;
		for(int i=0; i<n; i++){
			cout<<i<<" \n"[i+1==n];
			a.push_back(i);
		}
		for(int i=0; i<n; i+=2) b.push_back(i);
		for(int i=1; i<n; i+=2) b.push_back(i);
		reverse(b.begin()+1, b.end());
		for(int i=0; i<n; i++) cout<<b[i]<<" \n"[i+1==n];
		for(int i=0; i<n; i++) cout<<(a[i]+b[i])%n<<" \n"[i+1==n];
		
	}
}