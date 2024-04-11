#include<cstdio>
#include<vector>
using std::vector;
vector<int> v;
int n,i,x,y;
char c[100];
int main(){
	scanf("%d",&n);
	scanf("%s",c+1);
	y=1;
	for(i=1;i<=n;++i){
		if(c[i]=='0'){
			if(x)v.push_back(x);
			x=0;
			++y;
			if(y>1)v.push_back(0);
		}else{
			y=0;
			++x;
		}
	}
	v.push_back(x);	
	for(i=0;i<(int)v.size();++i)printf("%d",v[i]);
	return 0;
}