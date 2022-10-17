#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
	string ss;
	int n;
	bool a[125],b[125][125];
	for(int i=0;i<125;i++){for(int j=0;j<125;j++)b[i][j]=false; a[i]=false;}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>ss;
		int c=ss.size();
		for(int j=0;j<c;j++){
			int d=ss[j],e=ss[j+1]; 
			a[d]=true;
			if(j!=c-1)b[d][e]=true;
		}
	}
	bool c=false;
	for(int i=97;i<123;i++){
		if(!a[i]){printf("%c\n",i); c=true; break;}
	}
	if(!c)for(int i=97;i<123;i++){
		for(int j=97;j<123;j++){
			if(!b[i][j]){printf("%c%c\n",i,j); c=true; break;}
		}
		if(c)break;
	}
}