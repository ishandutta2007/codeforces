/*
 * D. Permutations.cpp
 *
 *  Created on: 2011-1-15
 *      Author: wjmzbmr
 */
#include <cstdio>
#include <iostream>
using namespace std;
int n;
const int MAX_N=100000+100;
int cnt[MAX_N]={};
int id[MAX_N]={};
int at[MAX_N];

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",at+i);cnt[at[i]]++;
	}
	for(int i=1;i<MAX_N-1;i++)
		if(cnt[i]<cnt[i+1]){
			puts("-1");
			return 0;
		}
	cout<<cnt[1]<<endl;
	for(int i=0;i<n;i++){
		printf("%d ",++id[at[i]]);
	}
}