/*************************************************************************
	> File Name: 15_5.cpp
	> Author:  YaoC 
	> Mail:  chengyao09@hotmail.com 
	> Created Time: 2015年05月21日 星期四 11时18分11秒
 ************************************************************************/

#include<iostream>
#include<cfloat>
void optimal_bst(double*,double*,int);
void print_tree(int*,int,int,int);

void optimal_bst(double *p,double *q,int n)
{
    double *e,*w;
    int *root;
    int k = n+1;
    e = new double[(n+2)*k];
    w = new double[(n+2)*k];
    root = new int[k*k];
    for(int i=1;i<n+2;i++)
    {
        e[i*k+i-1] = q[i-1];
        w[i*k+i-1] = q[i-1];
    }
    for(int l=1;l<n+1;l++)
    {
        for(int i=1;i<=(n-l+1);i++)
        {
            int j = i+l-1;
            e[i*k+j] = DBL_MAX;
            w[i*k+j] = w[i*k+j-1] + p[j] + q[j];
            for(int r=i;r<j+1;r++)
            {
                double t = e[i*k+r-1] + e[(r+1)*k+j] + w[i*k+j];
                if(t<e[i*k+j])
                {
                    e[i*k+j] = t;
                    root[i*k+j] = r;
                }
            }
        }
    }
    std::cout<<"The optimal binary search tree is (DLR):\n";
    print_tree(root,1,5,k);
    std::cout<<std::endl;
}

void print_tree(int *root,int i,int j,int n)
{

    int r = root[i*n+j];
    std::cout<<r<<" ";
    if(i!=j)
    {
        if(r>i)
            print_tree(root,i,r-1,n);
        if(r<j)
            print_tree(root,r+1,j,n);
    }
}

int main()
{
    double p[] = {0,0.15,0.10,0.05,0.10,0.20};
    double q[] = {0.05,0.10,0.05,0.05,0.05,0.10};
    int n = 5;
    optimal_bst(p,q,n);
    return 0;
}
