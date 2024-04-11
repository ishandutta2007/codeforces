#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int main(){
	int n,k;
	int a[202];
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	int sum[202]={0};
	sum[0]=0;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i-1];

	int MAX=-100000;

	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			vector<int> in,out;
//cout<<0;	
			for(int t=0;t<n;t++){
				if(i<=t&&t<=j)in.push_back(a[t]);
				else out.push_back(a[t]);
			}
//cout<<0;
			sort(in.begin(),in.end());
			sort(out.begin(),out.end());
//cout<<0;
			int ret=sum[j+1]-sum[i];
			int s=0,t=out.size()-1;
//cout<<0;
			if(t>=0)while(s<k&&in[s]<out[t]&&s<in.size()&&t>=0){
//cout<<1;
				ret+=out[t]-in[s];
				s++;
				t--;
			}
//cout<<0;
			MAX=max(MAX,ret);
		}
	}

	printf("%d\n",MAX);
}