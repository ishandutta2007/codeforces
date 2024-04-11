#include<bits/stdc++.h>
#define db double
using namespace std;

int h,m,s,p1,in1,p2,in2;
db pos[233];

int where(int x){
	x%=12;
	db t=(db)360*x/12;
	for (int i=1;i<3;i++){
		if (pos[i]<t&&t<pos[i+1]) return i;
	}
	return 3;
}

int main(){
	cin>>h>>m>>s>>p1>>p2;
	h%=12;
	pos[1]=(db)360*s/60;
	pos[2]=(db)360*m/60+(db)360*s/60/60;
	pos[3]=(db)360*h/12+(db)360*m/12/60+(db)360*s/12/60/60;
	
	sort(pos+1,pos+4);
	//for (int i=1;i<=3;i++) printf("%.3lf ",pos[i]);
	in1=where(p1);
	in2=where(p2);
	
	puts(in1==in2?"YES":"NO");
}