/**
 * Created with IntelliJ IDEA.
 * User: Ali Sadreddini
 * Date: 5/07/12
 * Time: 3:17 PM
 * To change this template use File | Settings | File Templates.
 */
public class DFSApplication {
    public static void main(String[] args)
    {
        Graph theGraph = new Graph();
        theGraph.addVertex("A");
        theGraph.addVertex("B");
        theGraph.addVertex("C");
        theGraph.addVertex("D");
        theGraph.addVertex("E");
        theGraph.addVertex("F");
        theGraph.addVertex("G");
        theGraph.addVertex("H");
        theGraph.addVertex("I");
        theGraph.addVertex("J");
        theGraph.addVertex("K");
        theGraph.addVertex("L");
        theGraph.addVertex("M");
        theGraph.addVertex("N");
        theGraph.addVertex("O");
        theGraph.addVertex("P");
        theGraph.addVertex("Q");
        theGraph.addVertex("R");
        theGraph.addVertex("S");
        theGraph.addVertex("T");
        theGraph.addVertex("U");
        theGraph.addVertex("V");
        theGraph.addVertex("W");
        theGraph.addVertex("X");
        theGraph.addVertex("Y");
        theGraph.addVertex("Z");

        theGraph.addEdge(0,1);
        theGraph.addEdge(0,2);
        theGraph.addEdge(0,3);
        theGraph.addEdge(0,4);
        theGraph.addEdge(1,5);
        theGraph.addEdge(1,6);
        theGraph.addEdge(2,6);
        theGraph.addEdge(2,7);
        theGraph.addEdge(3,8);
        theGraph.addEdge(4,9);
        theGraph.addEdge(5,11);
        theGraph.addEdge(6,10);
        theGraph.addEdge(6,11);
        theGraph.addEdge(7,11);
        theGraph.addEdge(7,17);
        theGraph.addEdge(8,16);
        theGraph.addEdge(9,12);
        theGraph.addEdge(10,13);
        theGraph.addEdge(10,14);
        theGraph.addEdge(11,15);
        theGraph.addEdge(11,16);
        theGraph.addEdge(12,17);
        theGraph.addEdge(12,21);
        theGraph.addEdge(13,18);
        theGraph.addEdge(14,19);
        theGraph.addEdge(15,18);
        theGraph.addEdge(16,0);
        theGraph.addEdge(16,22);
        theGraph.addEdge(16,20);
        theGraph.addEdge(17,20);
        theGraph.addEdge(17,24);
        theGraph.addEdge(17,21);
        theGraph.addEdge(18,22);
        theGraph.addEdge(19,22);
        theGraph.addEdge(20,23);
        theGraph.addEdge(20,24);
        theGraph.addEdge(21,24);
        theGraph.addEdge(21,25);
        theGraph.addEdge(22,23);
        theGraph.addEdge(22,25);
        theGraph.addEdge(24,25);

        System.out.print("Visits: ");
        theGraph.dfs(0);
        System.out.println();
    }
}
