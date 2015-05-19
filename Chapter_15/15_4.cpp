/*************************************************************************
	> File Name: 15_4.cpp
	> Author:  YaoC 
	> Mail:  chengyao09@hotmail.com 
	> Created Time: 2015年05月19日 星期二 14时06分12秒
 ************************************************************************/

#include<iostream>
void lcs_length(char *x,char *y,int m,int n);
void print_lcs(int *b,char *x,int n,int i,int j);

void lcs_length(char *x,char *y,int m,int n)
{
    int *b,*c;
    b = new int[m*n];
    c = new int[(m+1)*(n+1)];
    int k = n+1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(x[i]==y[j])
            {
                c[(i+1)*k+j+1] = c[i*k+j]+1;
                b[i*n+j] = 1;//left:0,up-left:1;up:2
            }
            else
            {
                if(c[i*k+j+1]>=c[(i+1)*k+j])
                {
                    c[(i+1)*k+j+1] = c[i*k+j+1];
                    b[i*n+j] = 2;
                }
                else
                {
                    c[(i+1)*k+j+1] = c[(i+1)*k+j];
                    b[i*n+j] = 0;
                }
            }
        }
    }
    std::cout<<"The longest-common-subsequence is ";
    print_lcs(b,x,n,m-1,n-1);
    std::cout<<std::endl;
}

void print_lcs(int *b,char *x,int n,int i,int j)
{
    if(i>=0&&j>=0)
    {
        if(b[i*n+j]==1)
        {
            print_lcs(b,x,n,i-1,j-1);
            std::cout<<x[i];
        }
        else 
        {
            if(b[i*n+j]==2)
            {
                print_lcs(b,x,n,i-1,j);
            }
            else
            {
                print_lcs(b,x,n,i,j-1);
            }
        }
    }
}

int main()
{
    char x[] = "ABCBDAB";
    char y[] = "BDCABA";
    lcs_length(x,y,7,6);
    return 0;
}
