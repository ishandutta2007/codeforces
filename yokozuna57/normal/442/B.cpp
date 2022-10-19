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
	double in;
	vector<double> d;

	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf",&in);
		d.push_back(in);
	}

	sort(d.begin(),d.end());

	double ret0=1.0,ret1=0.0,ret2=0.0;
	double ret=0.0;

	for(int i=n-1;i>=0;i--){
		ret2+=ret1*d[i];
		ret1*=(1-d[i]);
		ret1+=ret0*d[i];
		ret0*=(1-d[i]);
		ret=max(ret,ret1);

		//cout<<ret0<<" "<<ret1<<" "<<ret2<<" "<<ret<<endl;
	}

	printf("%.12f\n",ret);
}