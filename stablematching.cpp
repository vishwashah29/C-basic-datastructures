#include<iostream>
#include<stack>

using namespace std;

int main()
{
    int n,i,j,order;
    cout<< "enter the number of total women/men" << endl;
    cin >> n;
    int menpref[n][n], womenpref[n][n],matching[n],rank[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout << "Enter women number in range:" << n << "whose preference is " << j << endl;
            cin >> order;
            menpref[i][j]=order;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout << "Enter men number in range:" << n << "whose preference is " << j << endl;
            cin >> order;
            womenpref[i][j]=order;
            rank[i][order]=j;
        }
    }
    stack<int> s;
    for(i=n-1;i>=0;i--)
    {
        s.push(i);
    }
    i=0;
    while(!s.empty())
    {
      for(j=0;j<n;j++)
      {
          if(menpref[i][j]!=-1)
          {
              matching[i]=menpref[i][j];
              for(k=0;k<n;k++)
              {


              }
              manpref[i][j]=-1;
              s.pop()
              break;
          }
          else
          {
              for(k=0;k<n;k++)
              {
                  if(matching[k]==manpref[i][j])
                  {
                      int x=k;
                      break;
                  }
              }
              if(rank[x]>rank[i]))
              {
                  matching[i]=menpref[i][j];
                  manpref[]
                  s.pop();
                  s.push(x);
                  break;
              }
              else
              {
                   continue;

              }

          }
      }

    }
}



