/* 
	Kruskall's Algorithm - Greedy Algorithm
	=> sorts all edges
	=> selects next smallest weight edge that does not create cycle
	=> continues until MST
*/

kruskall(edgelist, n)
{
	/* step one is to sort edges in non-decreasing order */
	sort(edgelist);
	/* make sets out of each vertex */
	for (i -> n)
		makeset(i);
	
	/* initialise */
	count = 0;
	i = 1;
	/* loop until we run out of vertices */
	while (count < n - 1)
	{
		/* if we find an edge where both start/end vertices do not create a cycle */
		if (findset(edgelist[i].v) != findset(edgelist[i].w)
		{	
			/* then print it */
			println(edgelist[i].v + "-" + edgelist[i].w);
			/* increment count */
			count = count + 1;
			/* and union the vertice sets */
			union(edgelist[i].v, edgelist[i].w);
		}
		i = i + 1;
	}
}
