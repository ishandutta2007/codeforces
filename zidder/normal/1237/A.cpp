#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	bool b = false;
	for(int i = 0;i<n;i++){
		int x;
		cin>>x;
		if (x%2){
			if (b){
				cout<<(x+1)/2<<endl;
			}
			else{
				cout<<(x-1)/2<<endl;
			}
			b^=true;
		}
		else{
			cout<<x/2<<endl;
		}
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}