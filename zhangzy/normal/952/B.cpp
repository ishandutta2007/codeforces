#include<bits/stdc++.h>
using namespace std;
string s;
map<string,int>mp;

int main(){
	mp["terrible"]=1;
	mp["worse"]=1;
	mp["no way"]=1;
	for (int lim=6;lim--;){
		printf("%d\n",lim);
  		fflush(stdout);
		getline(cin,s);
		if (mp.count(s)){
			puts("grumpy");
  			fflush(stdout);
  			return 0;
		}
	}
	puts("normal");
  	fflush(stdout);
}