#include "bits/stdc++.h"

#pragma warning(disable:4996)

//

using namespace std;

int main() {
	int a,b,c,d;cin>>a>>b>>c>>d;
	int ans=(a+2)*(b+2)+(c+2)*(d+2);
	ans-=4+2*min(a,c);
	ans-=a*b+c*d;
	cout<<ans<<endl;

	return 0;
}