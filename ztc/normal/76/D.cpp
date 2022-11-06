#include<iostream>
unsigned long long l,r,i=62;
int main()
{
	std::cin>>l>>r;
	if(((l^r^1)&1)&&l>=r&&(((l-r)>>1)&r)==0)std::cout<<((l-r)>>1)<<" "<<(l-((l-r)>>1));
	else std::cout<<"-1";
}