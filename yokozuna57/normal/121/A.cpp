#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> lucky;

long long solver(long long n){
	long long ret=0;
	for(int i=0;i<lucky.size();i++){
		if(n<lucky[i]){
			ret+=(n-lucky[i-1])*lucky[i];
			break;
		}
		else {
			ret+=(lucky[i]-lucky[i-1])*lucky[i];
		}
	}
	return ret;
}

int main(){
	lucky.push_back(0);
	for(int i=1;i<10;i++){
		for(int j=0;j<1<<i;j++){
			long long r=0;
			for(int k=i-1;k>=0;k--){
				if(((j>>k)&1)==0)r=r*10+4;
				else r=r*10+7;
			}
			lucky.push_back(r);
		}
	}
	lucky.push_back(4444444444);

	long long l,r;
	scanf("%I64d%I64d",&l,&r);

	printf("%I64d\n",solver(r)-solver(l-1));

/*for(int i=0;i<10;i++){
	printf("%I64d\n",lucky[i]);
}

for(int i=0;i<10;i++){
	printf("%I64d\n",solver(i));
}*/
}