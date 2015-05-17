/*************************************************************************
	> File Name: 15_3.cpp
	> Author:  YaoC 
	> Mail:  chengyao09@hotmail.com 
	> Created Time: 2015年05月17日 星期日 19时39分11秒
 ************************************************************************/

#include<iostream>
#include<climits>
int memoized_matrix_chain(const int *p,int *m,int n);
int lookup_chain(int *m,const int *p,int i, int j,int n);

int memoized_matrix_chain(const int *p,int *m,int n)
{
    for(int i=0;i<(n*n);i++)
        m[i] = INT_MAX;
    return lookup_chain(m,p,0,n-1,n);
}

int lookup_chain(int *m,const int *p,int i,int j,int n)
{
    if(m[i*n+j]<INT_MAX)
        return m[i*n+j];
    if(i==j)
        m[i*n+j] = 0;
    else
    {
        for(int k=i;k<j;k++)
        {
            int q = lookup_chain(m,p,i,k,n)+lookup_chain(m,p,k+1,j,n)+p[i]*p[k+1]*p[j+1];
            //std::cout<<"q="<<q<<std::endl;
            if(q<m[i*n+j])
            {
                //std::cout<<"test\n";
                m[i*n+j] = q;    
            }
        } 
    }
    //std::cout<<"m["<<i<<","<<j<<"]:"<<m[i*n+j]<<std::endl;
    return m[i*n+j];
}

int main()
{
    using namespace std;
    int p[] = {30,35,15,5,10,20,25};
    int *m;
    m = new int[6*6];
    int result = memoized_matrix_chain(p,m,6);
    cout<<result<<endl;
}
