/* 
	Merge sort algorithm. Basically performs the following:
	1. Breaks down the array into single sub-arrays
	2. Merge two sub-arrays together in non-decreasing order
	3. Repeat step 2 until complete
*/

mergesort(a, i, j)
{
	/* if only one element, return */
	if (i == j)
		return;
	/* divide a into two nearly equal parts */
	m = (i + j) / 2;
	/* sort each half recursively */
	mergesort(a, i, m);
	mergesort(a, m + 1, j);
	
	/* merge the two sorted halves together */
	merge(a, i, m, j);
}

/*
	Merges two index sub-arrays into one
*/
merge(a, i, m, j)
{
	/* p = index of first sub-array start */
	p = i;
	/* q = index of second sub-array start */
	q = m + 1;
	/* r = index of local sub array start */
	r = i;
	/* loop until we reach the end of a sub-array */
	while(p <= m &&  q <= j)
	{
		/* if left sub-array value is smaller copy to c and increase index of left sub-array */
		if (a[p] <= a[q])
		{
			c[r] = a[p];
			p = p + 1;
		}
		/* opposite, if the right sub-array value is smaller */
		else
		{
			c[r] = a[q];
			q = q + 1;
		}
		/* if the sub-array lengts weren't equal there will be a remainder. copy the remainder to c */
		while(p <= m)
		{
			c[r] = a[p];
			p = p + 1;
			r = r + 1;
		}
		/* do same for second sub array */
		while (q <= j)
		{
			c[r] = a[q];
			q = q + 1;
			r = r + 1;
		}
		/* copy everything back to a */
		foreach(r)
			a[r] = c[r];
	}
}