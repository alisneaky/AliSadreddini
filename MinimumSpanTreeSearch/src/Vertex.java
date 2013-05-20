/**
 * Created with IntelliJ IDEA.
 * User: Ali Sadreddini
 * Date: 5/07/12
 * Time: 5:32 PM
 * To change this template use File | Settings | File Templates.
 */
public class Vertex {
    public String label;                    //The label will include the name of the Destination
    public boolean isInTree;              //This will indicate whether the vertex has already been traversed through

    public Vertex(String lab)
    {
        label = lab;
        isInTree = false;
    }
}
