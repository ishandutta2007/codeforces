#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[102];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	reverse(a,a+n);
	
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=a[i];
		if(sum>=m){
			cout<<i+1<<endl;
			return 0;
		}
	}
}