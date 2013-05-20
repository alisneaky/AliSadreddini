package Graph;

/**
 *
 * @author Ali Sadreddini
 */
public class Edge 
{
    private Vertex fromVertex = null;
    private Vertex toVertex = null;
    private int weight;
    
    public Edge(Vertex from, Vertex to, int weight)
    {
        this.fromVertex = from;
        this.toVertex = to;
        this.weight = weight;
    }

    public Vertex getFromVertex() {
        return this.fromVertex;
    }

    public Vertex getToVertex() {
        return this.toVertex;
    }

    public int getWeight() {
        return this.weight;
    }
}
