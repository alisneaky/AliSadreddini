Chapter 3 - Data Structures

Disjoint Sets Algorithms -  Simple algorithms
-----------

1. Make Set (page 152)
/** simple algorithm makes a set out of a value, rooted to itself **/
makeset(i)
{
	parent[i] = i;
}

2. Findset (page 152)
/** simple algorithm, returns the root of the tree to which i belong **/
findset(i)
{
	while (i != parent[i])
		i = parent[i];
	return i;
}

3. Merge Tree (page 153)
/** Combines two trees into one. Roots of the trees are input **/
mergetrees(i, j)
{
	parent[i] = j;
}

4. Union (page 153)
/** Unions the trees of two values to which they belong **/
union(i, j)
{
	mergetrees(findset(i), findset(j));
}


/**
	NOTE: Optimisations can be heavily made for these.
	These include:
		- Storing height values of the trees so mergetrees will always create an optimal tree (O(n) --> O(lgn))
		- Storing ranks of trees (which indicate the upper bounded height of the tree)
**/