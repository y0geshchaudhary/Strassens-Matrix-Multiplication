# Strassens-Matrix-Multiplication
C++ code for Strassens algo for Matrix Multiplication.

https://en.wikipedia.org/wiki/Strassen_algorithm


The	input	is	specified	in	a	file whose	name	is	the	first	argument	of	the	program.	The	first	line	contains	an	integer	
M specifying	how	many	datasets	are	in	the	file.		The	reminder	of	the	file	encodes	the	datasets.	Each	dataset	
starts	with	an	integer	N that	is	a	power	of	2	specifying	the	size	of	the	2	input	matrices	(i.e.	N	by	N).	The	following	
2 lines	each	contain	the entries	of	the	two	input	matrices	(N>0).		Each	matrix	is	encoded	in	one	line	as	a	space	
separated	sequence	of	�"floating	point	numbers,	enumerate	row	by	row.
Here	is	an	example:
3
2
1	2	3	4
9	8	7	6	
4
1	0	2	3	7	8	-1	9	4	2	0	0	1	-1	2	5
2	8	10	19	21	0	0	-1	-5	2	8	7 7	0	1	2
1
7	
8
The	above	example	corresponds	to	the	following	test	cases		(in	order):
1 2
3 4 ∗ 9 8
7 6
1 0
7 8
2 3
−1 9
4 2
1 −1
0 0
2 5
∗
2 8
21 0
10 19
0 −1
−5 2
7 0
8 7
1 2
7 ∗ 8
The	output	is	a	file	called	whose	name	is	the	second	argument	of	the	program.:	Each	line	encodes	the	matrix	
result	for	each	test	case	in	the	order	in	which	they	were	read	form	the	input	file.	
For	example,	the	output	corresponding	to	the	input	above	is	as	follows:
23	20	55	48
13	12	29	39	250	54	71	136	50	32	40	74	6	12	31	44
56
