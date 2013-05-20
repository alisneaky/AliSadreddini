Chapter 5 - Divide and Conquer
Divide and Conquer Algorithms
-----------

1. Tromino (page 218)
/**
	Input Parameters: n, a power of 2 (the board size);
	the location L of the missing tile
	Output Parameters: none
**/
tile(n,L)
{
	if (n == 2)
	{
		//the board is a right tromino T
		tile with T
		return
	}
	/** 
		- divide the board into four n/2 by n/2 subboards
		- place one tromino in the center
		- let m[i] denote the location of the missing squares 
	**/
	for i = 1 to 4 
		tile(n/2, m[i])
}
