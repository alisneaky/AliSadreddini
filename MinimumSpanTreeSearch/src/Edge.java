/**
 * Created with IntelliJ IDEA.
 * User: Ali Sadreddini
 * Date: 5/07/12
 * Time: 5:24 PM
 * To change this template use File | Settings | File Templates.
 */
public class Edge {
    public int srcVert;
    public int destVert;
    public int weight;

    public Edge(int sv,int dv, int w)
    {
        srcVert = sv;
        destVert = dv;
        weight = w;
    }
}
