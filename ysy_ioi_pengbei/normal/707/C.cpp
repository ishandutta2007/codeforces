#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
int main()
{
	long long s,ys=0,rp=1;
	cin>>s; ys=s;
	while(s%2==0) s>>=1, rp<<=1;
	if(s>1)
	{
		long long t=s*s,n=t/2;
		cout<<n*rp<<" "<<(n+1)*rp<<"\n";
		return 0;
	}
	if(rp>=4)
	{
		cout<<ys/4*3<<" "<<ys/4*5<<"\n";
	}
	else puts("-1");
}