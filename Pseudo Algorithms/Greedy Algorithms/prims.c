/* 
	Prim's Algorithm - Greedy Algorithm
	=> starts with initial vertice
	=> gets adjacent vertices
	=> gets the minimum weight edge between vertices and makes the edge
	=> roots the new vertice to the start vertice
	=> continues until no more vertices can be added
*/

prims(adj, start, parent)
{
	/* initialise */
	n = adj.length;
	/* make all key values max */
	for (i = 1 -> n)
		key[i] = MAX;
	key[start] = 0;
	parent[start] = 0;
	h.init(key, n);
	/* loop over each vertice */
	for (i = 1 -> n)
	{
		/* remove our first vertice */
		v = h.del();
		/* get the vertices adjacent vertices */
		ref = adj[v];
		/* loop until no more adjacent vertices */
		while (ref != null)
		{
			/* get adjacent vertice */
			w = ref.ver;
			/* check whether the weight of the edge is less than w,
				for the first check (against MAX) it will always selecgt */
			if (h.isin(w) && ref.weight < h.keyval(w))
			{
				/* make the parent of the w -> v */
				parent[w] = v;
				/* decrease the weight of w by ref.weight */
				h.decrease(w, ref.weight);
			}
			/* get next adjacent vertice in the list */
			ref = ref.next;
		}
	}
}
