#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool sor(int x,int y){return x>=y;}

int main(){
	int n,s,c;
	int ret0=0,ret1=0;
	vector<int> z;

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&s);
		for(int j=0;j<s/2;j++){
			scanf("%d",&c);
			ret0+=c;
		}
		if(s%2==1){
			scanf("%d",&c);
			z.push_back(c);
		}
		for(int j=0;j<s/2;j++){
			scanf("%d",&c);
			ret1+=c;
		}
	}

	sort(z.begin(),z.end(),sor);
	s=z.size();
	for(int i=0;i<s;i++){
		if(i%2==0)ret0+=z[i];
		else ret1+=z[i];
	}

	printf("%d %d\n",ret0,ret1);
}