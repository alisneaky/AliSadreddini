/**
 * Created with IntelliJ IDEA.
 * User: Ali Sadreddini
 * Date: 5/07/12
 * Time: 12:52 PM
 * To change this template use File | Settings | File Templates.
 */
public class Graph{
    private final int MaxVerts = 100;      //Maximum Number of Vertices
    private Vertex vertexList[];            //Array of Vertices
    private int adjMat[][];                 //Adjacency Matrix
    private int nVerts;                     //Current Number of Vertices in the Graph
    private StackX theStack;
//  --------------------------------------------------------------------------------------------------------------------
//  Default Constructor
    public Graph()
    {
        vertexList = new Vertex[MaxVerts];          //Array of all vertices
        adjMat = new int[MaxVerts][MaxVerts];       //Adjacency Matrix Initialisation
        nVerts = 0;

        for(int j = 0; j<MaxVerts; j++)             //Set Adjacency
            for(int k = 0; k<MaxVerts; k++)         //Matrix to 0
                adjMat[j][k] = 0;
        theStack = new StackX();
    }
//  --------------------------------------------------------------------------------------------------------------------
//  Add Vertex to a graph
    public void addVertex(String label)
    {
        vertexList[nVerts++] = new Vertex(label);
    }
//  --------------------------------------------------------------------------------------------------------------------
//  Add Edge between two vertices
//    Directed Graph
    public void addEdge(int start, int end)
    {
        adjMat[start][end] = 1;
    }
//  --------------------------------------------------------------------------------------------------------------------
//  Display Vertex
    public void displayVertex(int v)
    {
        System.out.print(vertexList[v].label);
    }
//  --------------------------------------------------------------------------------------------------------------------
//  Depth First Search
    public void dfs(int startingVertex)
    {
        vertexList[startingVertex].wasVisited = true;            //Mark the vertex
        displayVertex(startingVertex);                           //Display it
        theStack.push(startingVertex);                           //Push it

        while( !theStack.isEmpty())
        {
            //get an unvisited vertex adjacent to stack top
            int v = getAdjUnvisitedVertex(theStack.peek());
            if(v==-1)
            {
                theStack.pop();
            }
            else
            {
                vertexList[v].wasVisited = true;
                displayVertex(v);
                theStack.push(v);
            }
        }//end while
        //Stack is empty, so we are done
        for(int j = 0; j<nVerts;j++)
            vertexList[j].wasVisited = false;
    }//end dfs
//  --------------------------------------------------------------------------------------------------------------------
//  Return an unvisited vertex adjacent to v
    public int getAdjUnvisitedVertex(int v)
    {
        for(int j = 0;j<nVerts;j++)
            if(adjMat[v][j]==1 && !vertexList[j].wasVisited)
                return j;
//        System.out.println();
        return -1;
    }
}
//End of Graph Class
