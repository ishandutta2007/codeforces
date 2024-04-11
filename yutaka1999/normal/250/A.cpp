#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector <int> vec;
    
    int ans=1;
    int k=0;
    int kiroku=0;
    
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        
        if(a<0) k++;
        if(k==3)
        {
            ans++;
            k=1;
            vec.push_back(i-kiroku);
            kiroku=i;
        }
    }
    vec.push_back(n-kiroku);
    
    printf("%d\n",ans);
    for(int i=0;i<vec.size();i++)
    {
        if(i!=vec.size()-1) printf("%d ",vec[i]);
        else printf("%d\n",vec[i]);
    }
    return 0;
}