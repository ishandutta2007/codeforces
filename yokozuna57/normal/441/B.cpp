#include<iostream>
using namespace std;

int main(){
	int n,v;
	int c[3010]={0};
	scanf("%d%d",&n,&v);

	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);

		c[a]+=b;
	}

	int ret=0;
	int fi=0,se=0;
	for(int i=1;i<=3001;i++){
		fi=se;
		se=c[i];

		if(fi>=v){
			ret+=v;
		}
		else {
			ret+=fi;
			ret+=min(se,v-fi);
			se-=min(se,v-fi);
		}
	}

	printf("%d\n",ret);
}