#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
using namespace std;

int main(){
	int n;
	int a[100010];

	int ret=0;

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		ret=max(ret,a[i]);
	}

	printf("%d\n",ret);
}