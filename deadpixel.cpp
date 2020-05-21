#include <bits/stdc++.h> 
using namespace std; 

int calculatemax(int a, int b, int x, int y)
{
    int a1=x*b;
    int a2=a*y;
    int a3=(a-x-1)*b;
    int a4=a*(b-y-1);
    int max=std::max({a1,a2,a3,a4});
    return max;
    
}

int main()
{
    int n,a,b,x,y;
    for(int i=0;i<n;i++)
    {
        //cout<<"Enter the number of input,a,b,x,y"<<endl;
        cin>>n>>a>>b>>x>>y;
        int max=calculatemax(a,b,x,y);
        cout<<"the max area for given input"<< a << b << x << y <<" is: "<< max <<endl;
    }
    
  
}