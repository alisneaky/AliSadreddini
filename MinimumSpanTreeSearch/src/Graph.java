/**
 * Created with IntelliJ IDEA.
 * User: Ali Sadreddini
 * Date: 5/07/12
 * Time: 5:38 PM
 * To change this template use File | Settings | File Templates.
 */
public class Graph {
    private final int MAXVERTS= 100;
    private final int INFINITY = 1000000;
    private Vertex vertexList[];
    private int adjMat[][];
    private int nVerts;
    private int currentVert;
    private PriorityQ thePQ;
    private int nTree;

    public Graph()
    {
        vertexList = new Vertex[MAXVERTS];
        adjMat = new int[MAXVERTS][MAXVERTS];
        nVerts = 0;
        for(int j = 0; j<MAXVERTS; j++)
            for(int k = 0; k<MAXVERTS;k++)
                adjMat[j][k] = INFINITY;
        thePQ = new PriorityQ();
    }

    public void addVertex(String lab)
    {
        vertexList[nVerts++] = new Vertex(lab);
    }

    public void addEdge(int start, int end, int weight)
    {
        adjMat[start][end] = weight;
    }

    public void displayVertex(int v)
    {
        System.out.print(vertexList[v].label);
    }

    public void mstw(int start)
    {
        currentVert = start;
        while(nTree < nVerts-1)
        {
            vertexList[currentVert].isInTree = true;
            nTree++;

            for(int j = 0; j<nVerts; j++)
            {
                if(j==currentVert)
                    continue;
                if(vertexList[j].isInTree)
                    continue;
                int weight = adjMat[currentVert][j];
                if(weight == INFINITY)
                    continue;;
                putInPQ(j, weight);
            }
            if(thePQ.size()==0)
            {
                System.out.println("Graph not Connected!");
                return;
            }

            Edge theEdge = thePQ.removeMin();
            int sourceVert = theEdge.srcVert;
            currentVert = theEdge.destVert;

            System.out.print(vertexList[sourceVert].label);
            System.out.print(vertexList[currentVert].label);
            System.out.print(" ");
        }

//        mst is complete
        for(int j=0; j<nVerts; j++)
            vertexList[j].isInTree = false;
    }

    public void putInPQ(int newVert, int newWeight)
    {
        int queueIndex = thePQ.find(newVert);
        if(queueIndex != -1)
        {
            Edge tempEdge = thePQ.peekN(queueIndex);
            int oldWeight = tempEdge.weight;
            if(oldWeight>newWeight)
            {
                thePQ.removeN(queueIndex);
                Edge theEdge = new Edge(currentVert, newVert,newWeight);
                thePQ.insert(theEdge);
            }
        }
        else
        {
            Edge theEdge = new Edge(currentVert,newVert,newWeight);
            thePQ.insert(theEdge);
        }
    }
}
