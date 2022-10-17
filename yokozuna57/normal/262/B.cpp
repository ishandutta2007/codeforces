#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,k;
	int a;
	vector<int> seq;

	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		seq.push_back(a);
	}

	if(k<=lower_bound(seq.begin(),seq.end(),0)-seq.begin()){
		for(int i=0;i<k;i++)seq[i]*=-1;
	}
	else {
		int loc=0;
		while(loc<n&&seq[loc]<0){
			seq[loc]*=-1;
			k--;
			loc++;
		}

		sort(seq.begin(),seq.end());
		for(int i=0;i<k;i++){
			seq[0]*=-1;
		}
	}

	int ret=0;
	for(int i=0;i<n;i++)ret+=seq[i];

	printf("%d\n",ret);
}