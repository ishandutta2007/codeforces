#include<bits/stdc++.h>
using namespace std;
int A;int cnt=0;
int ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	char s[20];
	scanf("%s",s);
	return s[0]=='x'?1:2;
}
int test(int ans){
	int z=ask(ans,ans*2);
	if(z==1)return 1;//ans%a<=ans*2%a,a<=ans*2
	return 0;
}
int main(){
	char s[100];
	A=0;
	while(1){
//		A=rand()<<15|rand();
//		A%=1000000000,A++;
//		cnt=0;
		scanf("%s",s);
//		cin>>s;
		if(s[0]=='e'||s[0]=='m')break;
		vector<int>v;
		v.push_back(0); 
		int l=0,r=1e9,ans=0;
		for(int i=0;i<=30;++i)v.push_back(1<<i);
		for(int i=0;i<v.size()-1;++i)if(ask(v[i],v[i+1])==1){
			l=v[i]+1,r=min(r,v[i+1]);
			break;
		}
		while(l<=r){
			int mid=1ll*l+r>>1;
			if(test(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
//		printf("{%d}",cnt);
		printf("! %d\n",ans);
		fflush(stdout);
//		if(ans!=A||cnt>60)exit(-1);
	}
}