#include <cstdio>
#include <cassert>
#include <vector>
int n;char s[5];std::vector<int> vec;
bool query(int l,int r){
	static int tim=0;
	if(++tim>82)assert(false);
	printf("? %d ",r-l+1);
	for(int i=l;i<=r;++i)printf("%d ",vec[i]);putchar('\n');
	fflush(stdout),scanf("%s",s);return s[0]=='Y'?true:false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)vec.push_back(i);
	while(vec.size()>2){
		int s=vec.size()-1,t=vec.size()/3;
		int a=t-1,b=2*t-1;
		bool tag1=query(0,a);
		std::vector<int> nxt;
		if(tag1){	
			if(query(a+1,b)){for(int i=0;i<=b;++i)nxt.push_back(vec[i]);}
			else{for(int i=0;i<=a;++i)nxt.push_back(vec[i]);for(int i=b+1;i<=s;++i)nxt.push_back(vec[i]);}
		}
		else{
			bool tag2=query(0,a);
			if(!tag2){for(int i=a+1;i<=s;++i)nxt.push_back(vec[i]);}
			else if(query(a+1,b)){for(int i=0;i<=b;++i)nxt.push_back(vec[i]);}
			else{for(int i=0;i<=a;++i)nxt.push_back(vec[i]);for(int i=b+1;i<=s;++i)nxt.push_back(vec[i]);}
		}
		vec=nxt;
	}
	printf("! %d\n",vec[0]),fflush(stdout);
	scanf("%s",s);if(s[1]==')')return 0;
	printf("! %d\n",vec[1]),fflush(stdout);return 0;
}