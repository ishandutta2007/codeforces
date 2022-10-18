#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

string fld[55];
int n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>fld[i];
	}
	int r1=-1,c1=-1,r2,c2;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(fld[i][j]!='4'){
				continue;
			}
			if(r1==-1){
				r1=i;
				c1=j;
			}
			r2=i;
			c2=j;
		}
	}
	if(r1==-1){
		cout<<"No"<<endl;
		return 0;
	}
	bool ok=true;
	int cnt=0;
	for(int i=r1;i<=r2;i++){
		for(int j=c1;j<=c2;j++){
			if(fld[i][j]!='4'){
				ok=false;
			}
			cnt++;
		}
	}
	if(r1>0){
		for(int j=c1;j<=c2;j++){
			if(fld[r1-1][j]!='2'){
				ok=false;
			}
			cnt++;
		}
	}
	if(r2<n-1){
		for(int j=c1;j<=c2;j++){
			if(fld[r2+1][j]!='2'){
				ok=false;
			}
			cnt++;
		}
	}
	if(c1>0){
		for(int i=r1;i<=r2;i++){
			if(fld[i][c1-1]!='2'){
				ok=false;
			}
			cnt++;
		}
	}
	if(c2<n-1){
		for(int i=r1;i<=r2;i++){
			if(fld[i][c2+1]!='2'){
				ok=false;
			}
			cnt++;
		}
	}
	if(r1>0 && c1>0){
		if(fld[r1-1][c1-1]!='1'){
			ok=false;
		}
		cnt++;
	}
	if(r2<n-1 && c1>0){
		if(fld[r2+1][c1-1]!='1'){
			ok=false;
		}
		cnt++;
	}

	if(r1>0 && c2<n-1){
		if(fld[r1-1][c2+1]!='1'){
			ok=false;
		}
		cnt++;
	}
	if(r2<n-1 && c2<n-1){
		if(fld[r2+1][c2+1]!='1'){
			ok=false;
		}
		cnt++;
	}
	if(!ok){
		cout<<"No"<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(fld[i][j]=='0'){
				cnt++;
			}
		}
	}
	if(n*n!=cnt){
		ok=false;
	}
	if(!ok){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
}