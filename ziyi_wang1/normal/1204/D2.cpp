#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
char c[101000];
stack<int>s;
int n,m;
int main(){
scanf("%s",c+1);
n=strlen(c+1);
F(i,1,n){
	if(c[i]=='1')s.push(i);
	else if(!s.empty())s.pop();
}
while(!s.empty()){
	c[s.top()]='0';
	s.pop();
}
puts(c+1);
    return 0;
}