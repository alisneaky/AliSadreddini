package Graph;

/**
 *
 * @author Ali Sadreddini
 */
public class Vertex 
{
    private int vertexNo;               //Vertex number or label starting from 0
    private boolean visited;            //Boolean to save whether the vertex has been visited
    private Object data = null;         //Vertex can store any value or object of any data type
    
    public Vertex(int vertexNo, Object data)
    {
        this.vertexNo = vertexNo;
        this.visited = false;
        this.data = data;
    }
    
    //Instantiate a vertex object without a data value
    public Vertex(int vertexNo)
    {
        this(vertexNo, null);
    }
    
    public void visit()
    {
        this.visited = true;
    }
    
    public boolean isVisisted()
    {
        return this.visited;
    }
    
    public int getVertexNo()
    {
        return this.vertexNo;
    }
    
    public Object getData()
    {
        return this.data;
    }
}
