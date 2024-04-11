/*
 * D. Strange town.cpp
 *
 *  Created on: 2011-1-15
 *      Author: wjmzbmr
 */
#include <cstdio>
#include <iostream>
using namespace std;
const int MAX_VERTEX=20+1;
const int MAX_PRICE=1000;
int label[MAX_VERTEX];
bool exist[MAX_PRICE+1]={};
int main(){
	int n;cin>>n;
	label[0]=1;
	for(int i=1;i<n;i++){
		int newLabel;
		for(newLabel=label[i-1]+1;;newLabel++){
			bool ok=true;
			for(int j=0;j<i;j++)
				if(exist[label[j]+newLabel]){
					ok=false;
					break;
				}
			if(ok)
				break;
		}
		label[i]=newLabel;
		for(int j=0;j<i;j++)
			exist[label[i]+label[j]]=true;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j)cout<<0<<" ";
			else cout<<label[i]+label[j]<<" ";
		}
		cout<<endl;
	}
}