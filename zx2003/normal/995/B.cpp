#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,ans=0;
	scanf("%d",&n);
	vector<int>a(n*2);for(int&x:a)scanf("%d",&x);
	for(i=0;i<n;++i){
		int x=a[0],j=find(a.begin()+1,a.end(),x)-a.begin();
		ans+=j-1;a.erase(a.begin()+j);a.erase(a.begin());
	}
	printf("%d\n",ans);
	return 0;
}