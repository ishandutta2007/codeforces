#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

typedef long long int64;

int main(){
	char ch;
	int64 n;cin>>n>>ch;
	int64 cst = 0;

	int64 passed = (n-1)/4;
	cst = passed * 16;
	n -= passed*4;
	int me = string("fedabc").find(ch);
	if(n == 2 || n== 4)
		cst += 7;
	cst += me;
	cout<<cst+1<<endl;
}