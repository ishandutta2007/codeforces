#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define rep1(i,x) for(int i = 1 ; i <= x ; i ++)

int main(){
	int n,m;
	int a[100010],b[100010];
	scanf("%d%d",&n,&m);
	rep1(i,n)scanf("%d",&a[i]);
	rep1(i,m)scanf("%d",&b[i]);
	
	vector<ll> A,B;
	rep1(i,n)A.push_back(a[i]);
	rep1(i,m)B.push_back(b[i]);
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	
	if(A[n-1] > B[0]){
		puts("-1");
		return 0;
	}
	ll ret = 0;
	rep1(i,n)ret += a[i];
	ret *= m;
	if(n == 1){
		if(A[n-1] < B[0]){
			puts("-1");
			return 0;
		}
		else {
			ll sum = 0;
			rep1(i,m)sum += b[i];
			cout << sum <<endl;
		}
	}
	else {
		if(A[n-1] < B[0]){
			rep1(i,m)ret += b[i];
			ret -= A[n-1]*(m-1)+A[n-2];
			cout << ret <<endl;
		}
		else {
			rep1(i,m)ret += b[i];
			ret -= A[n-1]*m;
			cout << ret << endl;
		}
	}
}