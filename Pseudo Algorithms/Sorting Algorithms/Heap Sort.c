Heap Sort (page 145)
/** The algorithm uses heapify to create the heap out of an array. Then it swaps the largest element to that back and
	runs siftdown on the heap except the last element. Now the second largest element is at the top...repeat
**/
heapsort(v,n)
{
	/* first make the heap */
	heapify(v,n);
	for (i = n downto 2)
	{
		/* swap the largest element to the back. The back of the array will change as i gets reduced */
		swap(v[1], v[i]);
		/* Siftdown the new root with the heap ending at i-1 and make a new heap */
		siftdown(v, 1, i - 1);
		/* repeat */
	}
}

Heapify (page 141)
/**
	Really simple algorithm, just iterates over every index from n/2 (which is the second bottom) all the way to root. 
	Performs siftdown on each iteration
**/
heapify(v,n)
{
	for (i = n/2 downto 1)
		siftdown(v,i,n);
}

Siftdown (page 138)
/** This algorithm is used to make a heap out of two sub-heaps rooted at a node.
	Algorithm is extremely efficient and runs in (h) time = lg(n);
	Notes about this algorithm:
		- Remember that the trees after the root node are heaps, soe essentially the tests are whether that the root node is smaller than
			it's children. We just keep sifting down the root node essentially.
**/
siftdown(v,i,n)
{
	/* Start by storing our root node */
	temp = v[i];
	/* continue while there is a left child */
	while (2 * i <= n)
	{
		/* if the right child is bigger than the left child, use the right child instead */
		if  (child < n && v[child + 1] > v[child])
			child = child + 1;
		/* if it's bigger than our stored node, then move child up */
		if (v[child] > temp)
			v[i] = v[child];
		/* our break condition: if there is no child that is bigger than it's parent, then we have our heap */
		else
			break;
		i = child;
	}
	/* Now just put our stored value back into the heap */
	v[i] = temp;
}