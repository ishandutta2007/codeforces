%:pragma GCC optimize(3)
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int n;
string s1[10],s2[10];

int main()
{
	scanf("%d",&n);
	if (n<20)
	{
		if (n==0) printf("zero");
		if (n==1) printf("one");
		if (n==2) printf("two");
		if (n==3) printf("three");
		if (n==4) printf("four");
		if (n==5) printf("five");
		if (n==6) printf("six");
		if (n==7) printf("seven");
		if (n==8) printf("eight");
		if (n==9) printf("nine");
		if (n==10) printf("ten");
		if (n==11) printf("eleven");
		if (n==12) printf("twelve");
		if (n==13) printf("thirteen");
		if (n==14) printf("fourteen");
		if (n==15) printf("fifteen");
		if (n==16) printf("sixteen");
		if (n==17) printf("seventeen");
		if (n==18) printf("eighteen");
		if (n==19) printf("nineteen");
		return 0;
	}
	s1[2]="twenty";
	s1[3]="thirty";
	s1[4]="forty";
	s1[5]="fifty";
	s1[6]="sixty";
	s1[7]="seventy";
	s1[8]="eighty";
	s1[9]="ninety";
	if (n%10==0)
	{
		cout<<s1[n/10];
		return 0;
	}
	s2[1]="-one";
	s2[2]="-two";
	s2[3]="-three";
	s2[4]="-four";
	s2[5]="-five";
	s2[6]="-six";
	s2[7]="-seven";
	s2[8]="-eight";
	s2[9]="-nine";
	cout<<s1[n/10]<<s2[n%10];
}