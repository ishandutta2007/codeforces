#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	cin>>s;

	long long a[2]={0},b[2]={0};

	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='a'){
			a[i%2]++;
		}
		else b[i%2]++;
	}

	long long ret0,ret1;
	ret0=a[0]*a[1]+b[0]*b[1];
	ret1=a[0]+a[0]*(a[0]-1)/2+a[1]+a[1]*(a[1]-1)/2+b[0]+b[0]*(b[0]-1)/2+b[1]+b[1]*(b[1]-1)/2;

	printf("%I64d %I64d\n",ret0,ret1);
}