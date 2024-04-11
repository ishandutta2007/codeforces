#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	int n;
	cin >>n;
	int a[n];
	int tot=0;
	vector<int> v;
	for (int i=0;n>i;i++) {
		cin >>a[i];
		if (a[i]%2==0 && a[i]>0) tot+=a[i];
		else if ((a[i]%2+2)%2==1) v.push_back(a[i]); 
	}
	sort(v.begin(),v.end());
	int cnt=0;
	int tott=0;
	int mx=-999999997;
//	cout<<"sz = "<<v.size()<<endl;
	for (int i=v.size()-1;i>=0;i--) {
		cnt++;
		tott+=v[i];
		if (cnt %2==1) mx = max(mx,tot+tott);
	}
	cout<<mx<<endl;
}