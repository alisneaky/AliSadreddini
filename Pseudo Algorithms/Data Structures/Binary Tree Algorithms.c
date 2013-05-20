Chapter 3 - Data Structures

Binary Trees Algorithms
-----------

1. Counting nodes
	/** Simple recursive function for counting the nodes of a binary tree **/
	count_nodes(root)
	{
		/* first step is to check whether the tree is empty. If the tree is empty, return 0 */
		if (root == null)
			return 0;
		count = 1;
		/* recursively count all the nodes on the left of the tree */
		count = count + count_nodes(root.left);
		/* do the same for the right */
		count = count + count_nodes(root.right);
		/* now we have the result of recursively counting each node on the left and right subtrees */
		return count;
	}

	
2. Inserting into a binary tree (page 126)
	/** Recursive algorithm for inseting a new node into a binary tree
		Precondition: Root of a binary tree, value to be inserted
		Postconditions: Root of the new binary tree
	**/
	BSTInsert(root,val)
	{
		/* create our new node, assume left and right pointers are null on construction */
		temp = new node(val);
		/* check for special case: empty tree -> return our new node as root */
		if (root == null)
			return temp;
		BSTInsert_recurs(root, temp);
		return root;
	}
	BSTInsert_recurs(root, temp)
	{
		/* First check whether the it's smaller than root of subtree */
		if (temp.data <= root.data)
		{
			/* Now check that the left branch is empty, if so add here */
			if (root.left == null)
				root.left = temp;
			/* The left branch is not empty, so go down a level into left branch */
			else
				BSTInset_recurs(root.left, temp);
		}
		/* Repeat for the right subtree */
		else
		{
			if (root.right == null)
				root.right = temp;
			else
				BSTInsert_recurs(root.right, temp)
		}
	}
	
3. Deleting from a binary tree (page 129)
	/** Algorithm for deleting a node from a binary tree.
		Preconditions: root of the tree, reference to the node
		Postconditions: root of the tree without the referenced node
		
		Steps to algorithm:
		1. Locate the minimum weighted sucessor in the nodes right subtree.
		2. If the node has zero or more children then replace the sucessor with the node (or the child).
		3. Else, find the smallest successor (root.left) in this successor and replace with node.
		4. Make the parent of the node point to it's (only) child and return root
	**/
	
	BSTdelete(root, ref)
	{
		/* Case 1: if zero or one children */
		if (ref.left == null || ref.right == null)
			return BSTreplace(root,ref);
		/* Find minimum weighted successor in refs right subtree */
		succ = ref.right;
		while (succ != null)
			succ = succ.left;
		/* Replace the successor with parent and delete (step 3 + 4) */
		ref.data = succ.data;
		return BSTreplace(root,succ);
	}
	/* Handles the first case, where the node has zero or one child */
	BSTreplace(root,ref)
	{
		/* set child to ref's child or null, if no child */
		if (ref.left == null)
			child = ref.right;
		else
			child = ref.left;
		/* If the node is the root node, then we only need to return the only child */
		if (ref == root)
		{
			/* if the child of the root node is null, then delete root node and return child */
			if (child != null)
				child.parent = null;
			/* Also if the child is null, then we return null (empty tree) */
			return child;
		}
		/* Make the parent point to other children (deleting ref) */
		if (ref.parent.left == ref)
			/* if so then replace ref with our new child */
			ref.parent.left = child;
		else
			/* replace ref's right child */
			ref.parent.right = child;
		/* now make the new child point to parent, otherwise it's a leaf */
		if (child != null)
			child.parent = ref.parent;
		/* We would need to delete ref (otherwise memory leak here) */
		delete ref;
		return root;
	}
	
	