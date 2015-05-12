# exercise 15
## 15.1-1
 ![image](https://github.com/YaoC/Algorithms/master/Pictures/15.1-1.png)

##15.1-2
 ![image](https://github.com/YaoC/Algorithms/master/Pictures/15.1-2.png)

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