#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
char s[7];
inline bool query(int l,int r){
	cout<<"? "<<l<<" "<<r<<endl;
	char x;while(!isalpha(x=getchar()));
	return x=='x'?1:0;
}
inline void work(){
	if(query(0,1)){
		cout<<"! "<<1<<endl;
		return;
	}
	int l=1,r=2;
	for(;r<=2e9;l<<=1,r<<=1)
		if(query(l,r))break;
	int x=l++;
	while(l<=r){
		int mid=(l+r)>>1;
		if(query(x,mid))r=mid-1;
		else l=mid+1;
	}
	cout<<"! "<<l<<endl;
}
int main(){
	while(~scanf("%s",s+1)){
		if(s[1]=='e')break;
		work();
	}
	return 0;
}