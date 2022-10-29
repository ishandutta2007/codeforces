#include<bits/stdc++.h>
using namespace std;
int h,m,s,t1,t2;
int pd(int fr,int to){
	if(fr>to){
		if(s>to*5&&s<fr*5)return false;
		if(h>=to&&h<fr)return false;
		if(m>=to*5&&m<fr*5)return false;
	} else {
		if(s>to*5||s<fr*5)return false;
		if(h>=to||h<fr)return false;
		if(m>=to*5||m<fr*5)return false;
	}
	return true;
}
int main(){
	scanf("%d%d%d%d%d",&h,&m,&s,&t1,&t2);
	if(pd(t1,t2)||pd(t2,t1))printf("YES");
	else printf("NO");
}