/* 
	Counting sort algorithm.
	Works by establishing an array that counts the number of instances of values of that index.
	It will then place the values into an array based on how many occurences before that array exist.
	This array is then sorted.
	 - a: array
	 - m: the range of values in array (to establish local array)
*/

counting_sort(a, m)
{
	/* initialise the counting array */
	for (k = 0 -> m)
		c[k] = 0;
	/* add the number of occurences of each element into counting array */
	for (i -> n)
		c[a[i]] = c[a[i]] + 1;
	/* count all the elements previous to each element, starts at first element */
	for (k = 1 -> m)
		c[k] = c[k] + c[k-1];
	/* place values into sorted array */
	for (i = n -> 1)
	{
		b[c[a[i]]] = a[i];
		/* remove occurence from counting array */
		c[a[i]] = c[a[i]] - 1;
	}
	/* put elements back into array */
	for (i = 1 -> n)
		a[i] = b[i];
}

/*
	Radix sort just does a counting sort iteratively on each significant bit of the number.
	Base 10 is used here. Will sort the array based on the least significant -> most significant.
*/

radix_sort(a, k)
{
	for (0 -> k - 1)
	{
		counting_sort(a, 10);
	}
}