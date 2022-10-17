#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,m,c,t,s=0,ans=0;
	vector<int> a;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d%d",&c,&t);
		a.push_back(c*t);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&c);
		while(s<c){
			s+=a[ans];
			ans++;
		}
		printf("%d\n",ans);
	}
}