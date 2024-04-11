#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	int n;
	vector<int> x;
	int h[102]={0};

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int in;
		scanf("%d",&in);
		x.push_back(in);
	}

	sort(x.begin(),x.end());

	for(int i=0;i<n;i++){
		int k=0;
		while(h[k]>x[i])k++;
		h[k]++;
	}

	for(int i=0;i<=n;i++){
		if(h[i]==0){printf("%d\n",i); break;}
	}
	
}