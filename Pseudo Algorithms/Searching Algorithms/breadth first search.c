/**
Chapter 4 - Searching

Search Algorithms
-----------

2. Breadth First Search
Notes about the algorithm:
	- Implements a queue


	Requires a queue and a visited array. Finds a value key. 
	NOTE: By replacing the queue with a stack -> we have a DFS
	Steps:
	1. Enqueue the root node
	2. Dequeue a node and examine it
		- If the element sought is found in this node, quit the search and return a result.
		- Otherwise enqueue any successors (the direct child nodes) that have not yet been discovered.
	3. If the queue is empty, every node on the graph has been examined – quit the search and return "not found".
	4. If the queue is not empty, repeat from Step 2.
**/
bfs(adj, start, key)
{
	/* initialise our queue */
	q = new queue();
	/* set all the vertices to not being visited */
	for (i -> n)
		visit[i] = false;
	/* visit the start node */
	visit[start] = true;
	/* print the vertice visited */
	println(start);
	/* put the start node on the queue */
	q.enqueue(start);
	/* loop until no more vertice to explore */
	while (!q.isEmpty())
	{
		/* take the next vertice to be explored */
		current = q.dequeue();
		/* If the current vertice matches the key, return true */
		if (current == key)
			return true;
		/* get the adjacent vertices */
		trav = adj[current];
		/* loop through all the adjacent vertices */
		while (trav != null)
		{
			/* take the first vertice from the adjacent list */
			v = trav.ver;
			/* if it hasn't been visited, print the path and put on the queue for later */
			if (!visit[v])
			{
				visit[v] = true;
				println(v);
				q.enqueue(v);
			}
			/* get the next adjacent vertice */
			trav = trav.next;
		}
	}
}
	
	