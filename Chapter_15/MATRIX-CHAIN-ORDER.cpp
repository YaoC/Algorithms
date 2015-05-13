/*************************************************************************
	> File Name: MATRIX-CHAIN-ORDER.cpp
	> Author:  YaoC 
	> Mail:  chengyao09@hotmail.com 
	> Created Time: 2015年05月13日 星期三 20时33分19秒
 ************************************************************************/

#include <iostream>
#include <climits>

void matrix_chain_order(int *p,int *m,int *s,int n)
{
	n--;	
	for(int l=2;l<n+1;l++)//子问题矩阵链长度
	{
		for(int i=0;i<n-l+1;i++)
		{
			int j = i+l-1;
			m[i*n+j] = INT_MAX;
			int q = 0;
			for(int k=i;k<j;k++)
			{
				q = m[i*n+k] + m[(k+1)*n+j] + p[i]*p[k+1]*p[j+1];
				if(q<m[i*n+j])
				{
					m[i*n+j] = q;
					s[i*n+j] = k;
				}  
			}
		}
	}
}


//Test
int main()
{
	using namespace std;
	int p[] = {30,35,15,5,10,20,25};
	int *m,*s;
	m = new int[6*6];
	s = new int[6*6];
	matrix_chain_order(p,m,s,7);
	cout<<m[0*6+5]<<endl;
}
