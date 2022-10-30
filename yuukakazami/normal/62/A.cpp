/*
 * p1.cpp
 *
 *  Created on: 2011-2-25
 *      Author: user
 */

#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

bool ok(int girl,int boy){
	return boy>=girl-1&&boy<=(girl+1)*2;
}

int main(){
	int al,ar,bl,br;
	cin>>al>>ar>>bl>>br;
	if(ok(al,br)||ok(ar,bl))
		puts("YES");
	else
		puts("NO");
}