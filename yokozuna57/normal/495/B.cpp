#include<iostream>
#include<vector>
using namespace std;

vector<int> solver(int n){
	vector<int> ret;
	ret.push_back(1);
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			int cnt=0;
			while(n%i==0){
				n/=i;
				cnt++;
			}
			int t=ret.size();
			int s=1;
			for(int k=0;k<cnt;k++){
				s*=i;
				for(int j=0;j<t;j++){
					ret.push_back(ret[j]*s);
				}
			}
		}
	}
	if(n>1){
		int t=ret.size();
		for(int j=0;j<t;j++){
			ret.push_back(ret[j]*n);
		}
	}
	return ret;
}

int main(){
	long long a,b;
	cin >> a >> b;

	if(a == b)puts("infinity");
	else if(a < b)puts("0");
	else {
		vector<int> vec=solver(a-b);
		int ret=0;
		for(int i=0;i<vec.size();i++){
			if(vec[i]>b)ret++;
		}
		printf("%d\n",ret);
	}
}