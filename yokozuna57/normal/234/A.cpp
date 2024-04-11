#include<iostream>
using namespace std;

int main(){
FILE*infile,*outfile;
infile=fopen("input.txt","r");
outfile=fopen("output.txt","w");
int n,a[1000];
char RL[1000];
fscanf(infile,"%d\n%s\n",&n,&RL);
for(int i=0;i<n;i++){a[i]=i+1;}
for(int i=0;i<n/2;i++){
if(RL[i]=='R'&&RL[i+n/2]=='L'){a[i]+=n/2; a[i+n/2]-=n/2;}
fprintf(outfile,"%d %d\n",a[i],a[i+n/2]);
}}