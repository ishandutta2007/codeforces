#include <bits/stdc++.h>
using namespace std;
int k;
int n=2;
bool f[1002][1002];

int main(){
	cin>>k;
	const int mx=30;
	int source=1;
	vector <int> temp;
	while(temp.size()<2*mx) temp.push_back(++n);
	temp.push_back(2);
	int old=1001;
	for(int x: temp){
		f[x][old]=f[old][x]=1;
		old=x;
	}
	for(int i=0; i<=mx; i++){
		if((k>>i)&1) f[source][temp[i*2]]=f[temp[i*2]][source]=1;
		int top=++n;
		int bot=++n;
		f[top][source]=f[source][top]=1;
		f[bot][source]=f[source][bot]=1;
		source=++n;
		f[top][source]=f[source][top]=1;
		f[bot][source]=f[source][bot]=1;
	}
	// for(int i=1; i<=n; i++)
		// for(int j=i+1; j<=n; j++){
			// if(f[i][j]) cerr<<i<<' '<<j<<'\n';
		// }
	cout<<n<<'\n';
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) cout<<"NY"[f[i][j]];
		cout<<'\n';
	}
}