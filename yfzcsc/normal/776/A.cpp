#include<bits/stdc++.h>
using namespace std;
int main(){
	string a,b;
	cin>>a>>b;
	cout<<a<<' '<<b<<endl;
	int n;cin>>n;
	while(n--){
		string c,d;
		cin>>c>>d;
		if(c==a)a=d;
		else if(b==c)b=d;
		cout<<a<<' '<<b<<endl; 
	}
}