#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,a[maxn],b[maxn];
vector<int>A,B;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]<b[i])A.push_back(i);
		else B.push_back(i);
	}
	if(A.size()>B.size()){
		sort(A.begin(),A.end(),[](int x,int y){
			return b[x]>b[y];	
		});
		printf("%d\n",A.size());
		for(auto a:A)printf("%d ",a);
	} else {
		
		sort(B.begin(),B.end(),[](int x,int y){
			return b[x]<b[y];
		});
		printf("%d\n",B.size());
		for(auto a:B)printf("%d ",a);
	}
}