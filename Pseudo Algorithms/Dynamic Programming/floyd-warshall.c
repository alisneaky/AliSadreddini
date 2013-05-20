/* 
	Floyd's Algorithm - Dynamic Programming
	Finds the shortest path of all paths.
*/

floyd(A)
{
	n = A.size;
	for (k <- 1 to n)
		for (i <- 1 to n)
			for (j <- 1 to n)			
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
			}
		}
	}
}

/* 
	Floyd's Algorithm Version 2 - Dynamic Programming
	Finds all paths and allows them to be displayed via next[][]
*/

floyd(A)
{
	n = A.size;
	for (i <- 1 to n)
		for (j <- 1 to n)
			next[i][j] = j;
	for (k <- 1 to n)
		for (i <- 1 to n)
			for (j <- 1 to n)			
				if (A[i][k] + A[k][j] < A[i][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					next[i][j] = next[i][k];
				}
			}
		}
	}
}
