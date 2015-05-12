# exercise 15
## 15.1-1
 ![image](https://github.com/YaoC/Algorithms/raw/master/Pictures/15.1-1.png)

$T(n)=1+\sum_{j=0}^{n-1}T(j)$

$\qquad=1+T(n-1)+\sum_{j=0}^{n-2}T(j)$

$\qquad= 1+(1+\sum_{j=0}^{n-2})+\sum_{j=0}^{n-2}T(j)$

$\qquad=2^{1}*(1+\sum_{j=0}^{n-2}T(j))$

$\qquad=2^{2}*(1+\sum_{j=0}^{n-3}T(j))$

$\qquad=2^{i-1}*(1+\sum_{j=0}^{n-i}T(j))$

$When \quad i=n:$

$T(n)=2^{n-1}*(1+T(0))$

$\qquad =2^{n-1}*2$

$\qquad = 2^{n}$