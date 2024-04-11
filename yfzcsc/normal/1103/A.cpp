#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int z=1,f=1;
	for(auto c:s){
		if(c=='1'){
			printf("%d %d\n",z,2);
			z++;
			if(z==5)z=1;
		} else {
			printf("%d %d\n",f,1);
			f+=2;
			if(f==5)f=1;
		}
	}
}