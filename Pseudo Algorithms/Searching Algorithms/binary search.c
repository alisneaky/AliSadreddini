Chapter 4 - Searching

Search Algorithms
-----------

1. Binary Search / Worst Case time  = lg(n)
/** Precondition: non-decreasing array (L) + value, also can search between any two indexes (i, j)
	Postcondition: index of the array or -1 for not found
**/

bsearch(L, i, j, key)
{
	while (i <= j)
	{
		/* Divide the array by half and start searching there */
		k = (i + j) / 2;
		/* If we find the value, return it's index */
		if (key == L[k])
			return k;
		/** If the key is less than middle value, we refine our search 
			by bringing in the index range for that half */
		if (key < L[k])
			j = k - 1;
		/* Do the same but for the start index */
		else
			i = k + 1;
	}
	/* not found */
	return -1
}


	