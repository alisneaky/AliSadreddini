/**
Chapter 4 - Searching

Search Algorithms
-----------

2. Depth First Search
Notes about the algorithm:
	- Can be used recursively (using computers stack) or can be used iteratively with a stack ADT
	- Worst case is O(m + n)
	- Best Case is when n = m


	Recursive algorithm, initialises visited array to zero and start the recursion.
**/
dfs(adj, start)
{
	n = adj.last;
	for (i -> n)
		visit[i] = false;
	dfs_recurs(adj, start);
}
/* Recursive algorithm, will print out the paths of the graph. Optional addition of adding a key to search for */
dfs_recurs(adj,start)
{	
	/* print the node, if searching for key, would be if (key == start) println(start) */
	println(start);
	/* visit the node */
	visit[start] = true;
	/* get the linked list of adjacent vertices */
	trav = adj[start];
	/* While there are adjacent nodes loop */
	while (trav != null)
	{
		/* get the vertice */
		v = trav.ver;
		/* If it hasn't been visited, do it */
		if (!visit[v])
			dfs_recurs(adj,v);
		/* get the next vertice */
		trav = trav.next;
	}
}