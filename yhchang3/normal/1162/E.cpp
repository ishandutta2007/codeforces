#include<iostream>
#include<algorithm>
using namespace std;

int a[50];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	if(a[0]==a[n/2])
		cout<<"Bob"<<endl;
	else
		cout<<"Alice"<<endl;
}