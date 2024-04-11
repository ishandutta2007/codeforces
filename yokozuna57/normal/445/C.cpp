#include<iostream>
using namespace std;

int main(){
	int n,m;
	int v[502];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}

	long double ret=0.0;

	for(int i=0;i<m;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		ret=max(ret,(long double)(v[a]+v[b])/c);
	}

	printf("%.12lf\n",ret);
}