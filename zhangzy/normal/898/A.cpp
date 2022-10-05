#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin>>n;
	cout<<n/10*10+(n%10<5?0:10);
}