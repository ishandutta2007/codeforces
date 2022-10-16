#include <bits/stdc++.h>
using namespace std;
const int ms[]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const string dow[]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
int main(){
	string a, b;
	cin>>a>>b;
	int ida=find(dow, dow+7, a)-dow;
	int idb=find(dow, dow+7, b)-dow;
	for(int i=0; i<11; i++) if((ida+ms[i]-idb)%7==0){
		cout<<"YES\n";
		return 0;
	}
	cout<<"NO\n";
}