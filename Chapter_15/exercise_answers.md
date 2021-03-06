# exercise 15
## 15.1-1

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

##15.1-2

`动态规划算法：`
>$r_4 = 10$ ，切割方案 $4=2+2$

`使用贪心算法:`
>$r_4=9$ ，切割方案 $4=3+1$
## 15.1-3
```
CUT-ROD-WITH-COST(p,n)
	let r[0..n] be a new array
	r[0] = 0
	for j = 1 to n
		q = -∞
		for i = 1 to j
			//i=j即不切割，成本为0
			q = max(q,p[i]+r[j-i]-(i=j?0:c)) 
		r[j] = q
	return r[n]
```
## 15.1-4
```
EXTENDED-MEMORIZED-CUT_ROD(p,n)
	let r[0..n] and s[0..n] be a new array
	for i = 0 to n
		r[i] = -∞
		s[i] = 0
	return EXTENDED-MEMORIZED-CUT-ROD-AUX(p,n,r,s)

EXTENDED-MEMORIZED-CUT-ROD-AUX(p,n,r,s)
	if r[n]>=0
		return r[n]
	if n == 0
		q = 0
	else q = -∞
		for i = 1 to n
			if q < p[i] + EXTENDED-MEMORIZED-CUT-ROD-AUX(p,n-i,r,s)
			q = p[i] + EXTENDED-MEMORIZED-CUT-ROD-AUX(p,n-i,r,s)
			s[n] = i
	r[n] = q
	return q				
```
## 15.1-5
```
FIBONACCI(n)
	let f[0..n] to be a new array
	f[0] = 0
	f[1] = 1
	for i = 2 to n
		f[i] = f[i-1] + f[i-2]
	return f[n]
```

## 15.2-1
> 最少标量乘法运算次数为2010次
> 括号化方案：
> **((A0A1)((A2A3)(A4A5)))**

## 15.2-3

$假设当n>2时，P(n)\ge cn^2$

$P(n+1)=\sum_{k=1}^{n}P(k)P(n+1-k)$

$\qquad\qquad=P(1)P(n)+P(2)P(n-1)+...+P(n-1)P(2)+P(n)P(1)$

$\qquad\qquad\ge2P(n)$

$\qquad\qquad=2cn^2$

$\qquad\qquad\ge c(n^2+2n+1)$

$\qquad\qquad=c(n+1)^2$

$故当n>2时，P(n)\ge cn^2成立，即\Omega(n^2)$

## 15.2-4
> **顶点个数：**
> $|V| = 1+2 +...+ n-1+n=\frac{(n+1)n}{2}$
> 
> **边的条数：**
> $|E| = 2((n-1)+2(n-2)+...+(n-1)(n-(n-1))+n(n-n))$
> 
> $\quad=2\sum_{k=1}^{n}(n-k)k$
> 
> $\quad=\frac{n(n-1)(n+1)}{3}$
> 
> **对一个长度为k的子问题可以有k-1种选择，每种选择有2条边。**

## 15.2-5
> $\sum_{i=1}^{n}\sum_{j=1}^{n}R(i,j)=\sum_{l=2}^{n}2(l-1)(n-l+1)$
>  
> $\quad =2\sum_{l=2}^{n}(l-1)(n-l+1)$
> 
> $\quad=2((n-1)+2(n-2)+3(n-3)+..+(n-1)*1)$  
>   
>   $\quad=\frac{n(n-1)(n+1)}{3}$
>   
>   其中i的循环次数：$n-l+1$
>   k的循环次数：$j-1-i+1=i+l-1-1-i+1=l-1$
>   每次循环访问$m[i,j]$两次
>   另：其实访问$m[i,j]$的次数就是`15.2-4`中边的条数