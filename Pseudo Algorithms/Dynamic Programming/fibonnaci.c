/* 
	Fibonnacie - Dynamic Version
	Simple dynamic program. Uses previously gained calculations to use in the next.
	[first][second] array used. Calculate new value based on these, then update them.
	O(n).
*/

fibonacci(n)
{
	/* if n < 3 return the number */
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	/* initialise our dynamic memory */
	mem[0] = 1;
	mem[1] = 1;
	
	/* runs n times */
	for (i = 3 -> n)
	{
		/* calculate new f */
		f = mem[0] + mem[1];
		/* update memory */
		mem[0] = mem[1];
		memp[1] = f;
	}
	/* return value */
	return f;
}
