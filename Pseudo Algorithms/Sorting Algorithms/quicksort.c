/* 
	Quick sort algorithm. Uses partitioning (similiar to mergesort).
	Steps include:
	1. Choose a partition pivot element
	2. Iterate from both ends of the arrays, swapping values if they are greater than or less than pivot element
	3. Stop at the pivot element.
	4. Continue 1-2 for new pivot element in partitions left and right of current partition.
*/

/** initialises our quicksort. This would be used to seed random generator. **/
quicksort(a)
{
	partition(a, a.length);
}

/** Main method of partitioning down an array */
parition(a, size)
{
	/* if less than two elements, then return it's sorted */
	if (size < 2)
		return;
	/* random generate our pivot */
	pivot = a[rand() % size);
	lower = 0; 
	upper = size - 1;
	
	/* 	loop until all elements left and smaller than pivot 
		have been swapper with elements right and greater than pivot. 
	*/
	while (lower < upper)
	{
		/* get left element */
		while (a[lower] < pivot)
			lower = lower + 1;
		/* get right element */
		while a[U] > pivot
			upper = upper + 1;
		/* swap them */
		swap(a[lower],a[upper]);
	}
	/* partition the new sub-arrays either side of pivot */
	partition(a, lower);
	partition(a, upper);
}