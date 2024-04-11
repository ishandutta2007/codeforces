/*
 * p2.cpp
 *
 *  Created on: 2011-2-26
 *      Author: user
 */

#include<cstdio>
#include<iostream>
#include<algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N=100000+10;
char am[MAX_N],cur[MAX_N*3];
typedef long long int64;

int main(){
	int n,k;
	cin>>n>>k;
	scanf(" ");scanf("%s",am);
	vector<int> posByChar[26];
	for (int i = 0; i < k; ++i) {
		posByChar[am[i]-'a'].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%s",cur);
		int len=strlen(cur);

		int64 ret=0;
		for (int j = 0; j < len; ++j) {
			char ch=cur[j];
			if(posByChar[ch-'a'].size()==0){
				ret+=len;
				continue;
			}
			vector<int>&v=posByChar[ch-'a'];
			vector<int>::iterator vit;
			int minDist=~0U>>2;
			if((vit=lower_bound(v.begin(),v.end(),j))!=v.end())
				minDist=*vit-j;
			vit=upper_bound(v.begin(),v.end(),j)-1;
			if(vit>=v.begin())
				minDist=min(minDist,j-*vit);
			ret+=minDist;
		}

		printf("%I64d\n",ret);
	}
}