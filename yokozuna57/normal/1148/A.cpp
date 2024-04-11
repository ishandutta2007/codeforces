#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;

#define rep1(i,x) for(int i = 1 ; i <= x ; i ++)
#define mp1(a,b,c) P1(a,P(b,c))

int main(){
	ll a,b,c;
	cin >> a >> b >> c;
	if(a > b)swap(a,b);
	if(a == b)cout << 2*c+a+b << endl;
	else cout << 2*c+2*a+1 << endl;
}