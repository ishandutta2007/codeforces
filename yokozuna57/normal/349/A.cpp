#include<iostream>
using namespace std;

int main(){
	int n,a=0,b=0,c=0,d;
	bool ee=true;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&d);
		if(d==25)c++;
		if(d==50){
			if(c==0)ee=false;
			b++; c--;
		}
		if(d==100){
			if(c<=2&&b==0)ee=false;
			if(c==0)ee=false;
			if(b==0){c-=3; a++;}
			else {c--; b--; a++;}
		}
	}
	if(ee)printf("YES\n");
	else printf("NO\n");
}