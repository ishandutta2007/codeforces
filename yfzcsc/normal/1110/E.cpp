#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100];
vector<int>A,B;
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=2;i<=n;++i)A.push_back(a[i]-a[i-1]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=2;i<=n;++i)B.push_back(b[i]-b[i-1]);
	if(a[1]!=b[1]||a[n]!=b[n]){
		puts("No");
		return 0;
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	if(A==B)puts("Yes");
	else puts("No");
}