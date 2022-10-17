#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define fr first
#define sc second

int main(){
	int t;
	scanf("%d",&t);
	for(;t>0;t--){
		int n;
		string s;
		cin>>n>>s;
		sort(s.begin(),s.end());
		cout<<s<<endl;
	}
}