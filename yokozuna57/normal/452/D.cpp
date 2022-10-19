#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int main(){
	int k,n1,n2,n3,t1,t2,t3;
	scanf("%d%d%d%d%d%d%d",&k,&n1,&n2,&n3,&t1,&t2,&t3);

	static short imos0[10000000+3000]={0};
	static short imos1[10000000+3000]={0};
	static short imos2[10000000+3000]={0};
	static bool c[10000000+3000]; for(int i=0;i<10000000+3000;i++)c[i]=false;

	int loc=1;
	int ret=0;

	for(int i=0;i<k;i++){

		while(1){
			if(!c[loc]){
				imos0[loc]+=imos0[loc-1];
				imos1[loc+t1]+=imos1[loc+t1-1];
				imos2[loc+t1+t2]+=imos2[loc+t1+t2-1];
				c[loc]=true;
			}

			if(imos0[loc]<n1&&imos1[loc+t1]<n2&&imos2[loc+t1+t2]<n3)break;

			loc++;
		}

		ret=loc+t1+t2+t3-1;
		imos0[loc]++; imos0[loc+t1]--;
		imos1[loc+t1]++; imos1[loc+t1+t2]--;
		imos2[loc+t1+t2]++; imos2[loc+t1+t2+t3]--;
	}

	printf("%d\n",ret);
}