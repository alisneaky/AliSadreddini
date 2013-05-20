/**
 * Created with IntelliJ IDEA.
 * User: Ali Sadreddini
 * Date: 5/07/12
 * Time: 12:41 PM
 * To change this template use File | Settings | File Templates.
 */
public class Vertex {

    public String label;                    //The label will include the name of the Destination
    public boolean wasVisited;              //This will indicate whether the vertex has already been traversed through

    public Vertex(String lab)
    {
        label = lab;
        wasVisited = false;
    }
}
