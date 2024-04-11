#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n;
int a[100010];

int query(int k){
	if(a[k]!=-1)return a[k];
	cout<<"? "<<k<<endl;
	fflush(stdout);
	cin>>a[k];
	return a[k];
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)a[i]=-1;
	int l=0,r=n+1; a[l]=a[r]=1000000;
	int m=(l+r)/2;
	query(m);
	while(l<m-1||m+1<r){
		int l_=(l+m)/2;
		int r_=(r+m+1)/2;
		if(query(l_)<a[m]){
			r=m;
			m=l_;
			continue;
		}
		if(query(r_)<a[m]){
			l=m;
			m=r_;
			continue;
		}
		l=l_;
		r=r_;
	}
	cout<<"! "<<m<<endl;
	fflush(stdout);
}