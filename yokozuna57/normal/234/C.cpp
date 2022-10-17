#include<iostream>
using namespace std;

int main(){
FILE*infile,*outfile;
infile=fopen("input.txt","r");
outfile=fopen("output.txt","w");
int n,sum=0,small=200000;
int a[200000];
fscanf(infile,"%d\n%d",&n,&a[0]);
for(int i=1;i<n;i++){fscanf(infile," %d",&a[i]);}
for(int i=1;i<n;i++){
if(i==1){
for(int j=0;j<i;j++){if(a[j]>=0)sum++;}
for(int j=i;j<n;j++){if(a[j]<=0)sum++;}}
if(i!=1){
if(a[i-1]<0)sum--;
if(a[i-1]>0)sum++;
}
if(sum<small)small=sum;}
fprintf(outfile,"%d\n",small);}