/* 
	Insertion sort algorithm. Basically performs the following:
	1. Grabs the first element and inserts into array
	2. Compare a new element against array, if our element is larger, iterate index
	3. When we find an element thats bigger than ours, insert here
	4. Shuffle the rest along.
*/

insertion_sort(a)
{
	/* get length */
	n = a.last;
	/* loop entire array */
	for (i -> n)
	{
		/* store our value */
		val = a[i];
		/* iterate from start */
		j = i - 1;
		/* loop until we find a value larger than ours or we reach end */
		while (j >= 1 && val < a[j])
		{
			/* shuffle along */
			a[j + 1] = a[j];
			/* re-index */
			j = j - 1;
		}
		/* insert our value */
		a[j + 1] = val;
	}
}