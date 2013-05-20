Chapter 3 - Data Structures

Binary Heaps Algorithms
-----------

1. Siftdown (page 138)

/** This algorithm is used to make a heap out of two sub-heaps rooted at a node.
	Algorithm is extremely efficient and runs in (h) time = lg(n);
	Notes about this algorithm:
		- Remember that the trees after the root node are heaps, soe essentially the tests are whether that the root node is smaller than
			it's children. We just keep sifting down the root node essentially.
	Steps:
	1. Save root
	2. Iterate for each child (2*i)
	3. Check if right child is bigger than left
	4. Check is the child is bigger than parent, move up
	5. make i = new child
	6. break loop if no more child larger 
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

2. Delete (page 139) 
/**	This algorithm is used to delete the root node of a heap. 
	Siftdown is used here because all we do is replace the root node with a leaf node and than
	shrink the array size of the heap (making n -> out of bounds)
**/

heap_delete(v,n)
{
	/* Make the root equal to the furtherst leaf node */
	v[1] = v[n];
	/* Shrink the array size to delete the leaf */
	n = n - 1;
	/* Siftdown from the root (which was a leaf) */
	siftdown(v, 1, n);
}

3. Inserting (page 140)

/** The algorithm for inserting is a little confusing unless you do a trace on it with test data (i.e page 140).
	What the algorithm doesn't specify directly is that you must do the following steps:
	1. Increase the array size by 1 (this creates a 'bubble') and use it as the index
	2. Check value against the parent, if it's greater, than shift the parent into this index and move 'bubble' up.
	3. Repeat until our value is greater than the current index and insert our value into the bubble
	
	Bubble: The bubble is just my definition of the array index that acts as a placeholder for our value. It just takes the value of it's parent
	and keeps moving up (and taking parents value) until the parent is no longer greater than the value.
**/
heap_insert(val, v, n)
{
	/* Here we define our array size getting bigger, this would be similiar to a vector */
	i = n = n + 1;
	/* Loop until our value is larger than the index (bubble) parent */
	while (i > 1 && val > v[i/2];
	{
		/** If the bubble's parent is larger than this one, make the bubbles value 
			it's parents and move up **/
		v[i] = v[i/2];
		/* move up to parent and now the parent is the bubble */
		i = i / 2;
	}
	/* Insert our value into the bubble */
	v[i] = val;
}

4. Heapify (page 141)
/**
	Really simple algorithm, just iterates over every index from n/2 (which is the second bottom) all the way to root. 
	Performs siftdown on each iteration
**/

heapify(v,n)
{
	for (i = n/2 downto 1)
		siftdown(v,i,n);
}

5. Heap Sort (page 145)
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






	