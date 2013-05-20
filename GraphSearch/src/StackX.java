/**
 * Created with IntelliJ IDEA.
 * User: Ali Sadreddini
 * Date: 5/07/12
 * Time: 3:02 PM
 * To change this template use File | Settings | File Templates.
 */
public class StackX {
    private final int SIZE = 15;
    private int[] st;
    private int top;
    public StackX()
    {
        st = new int[SIZE];
        top = -1;
    }

    public void push(int j)
    {
        st[++top] = j;
    }

    public int pop()
    {
        return st[top--];
    }

    public int peek()
    {
        return st[top];
    }

    public boolean isEmpty()
    {
        return (top == -1);
    }
}
