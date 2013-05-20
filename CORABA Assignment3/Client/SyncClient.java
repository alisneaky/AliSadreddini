import SyncService.*;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;

public class SyncClient {

    private static String offset = "*"; //The Offset value to be printed by each iteration
    private static Sync syncRef;    //the Object on the server to interact with

    public static void main(String[] args) {
        try {
            ORB orb = ORB.init(args, null);
            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);
            NameComponent nc = new NameComponent("Sync", "");
            NameComponent[] path = {nc};

            syncRef = SyncHelper.narrow(ncRef.resolve(path));
            System.out.println("----------------------------------------------");

            //Run the Synchronous Interaction
            synchronous(offset);
            System.out.println("----------------------------------------------");
            
            //Run the Deferred Synchronous Interaction
            deferredSynchronous(offset);
            System.out.println("----------------------------------------------");
            
            //Run the Asynchronous Interaction
            asynchronous(offset);
            System.out.println("----------------------------------------------");
            
        } catch (org.omg.CORBA.ORBPackage.InvalidName | NotFound | CannotProceed | InvalidName e) {
            System.out.println("Error: " + e);
        }
    }

    private static void synchronous(String offset) {
        System.out.println("Demonstarting Synchronous Interaction");
        for (int i = 0; i < 10; i++) {
            System.out.println((i + 1) + ".Value is " + offset);
            if (i == 4) {
                System.out.println("Call to server");
                //Get the server response
                offset = Integer.toString(syncRef.getOffset());
            }
        }
        offset = "*";   //Reset the offset value to * for the next interaction
    }

    private static void deferredSynchronous(String offset) {
        System.out.println("Demonstarting Deferred Synchronous Interaction");
        //Create a Thread for the deferred synchronous interaction
        deferredSynchronousThread runnableThread = new deferredSynchronousThread();

        for (int i = 0; i < 15; i++) {
            System.out.println((i + 1) + ".Value is " + offset);

            if (i == 4) {
                System.out.println("Call to server");
                //Start the thread to simulate calling the server
                runnableThread.start();
            }
            if (i == 9) {
                //When the client is ready to receive the response from the server
                //It polls the server for the response.
                //For the simulation, we simply join the thread again and 
                //request for its response when we are ready.
                try { runnableThread.join(); } 
                catch (InterruptedException ex) { ex.printStackTrace(); }
                //Retrieve the response value and get ready to print it.
                offset = runnableThread.delayedOutput();
            }
        }
        offset = "*"; //Reset the offset value to * for the next interaction
    }

    private static void asynchronous(String offset) {
        System.out.println("Demonstarting Asynchronous Interaction");
        //Create a Thread for the Asynchronous interaction
        asynchronousThread asyncThread = new asynchronousThread();
        //Pass the current Thread object to the asynchronous thread
        //In order to able to interrupt it when it is required.
        asyncThread.setMainThread(Thread.currentThread());

        int counter = 0;    //Counter to count the digits before each iteration
        for (int i = 0; i < 5; i++) {
            System.out.println((i + 1) + ".Value is " + offset);
            if (counter == 4) {
                System.out.println("Call to server");
                //Call the server by starting the asynchronous thread
                asyncThread.start();    
            }
            counter++;
        }
        //While the server hasn't responded, do what you normally do
        //For simulation, this action is performed by checking to see
        //if the main thread has been interrupted by the server thread
        while (!Thread.currentThread().isInterrupted()) {
            System.out.println((counter + 1) + ".Value is " + offset);
            counter++;
        }
        //Once the main thread has been interrupted by the server,
        //take the value of the offset from the server
        for (int i = 0; i < 5; i++) {
            offset = asyncThread.delayedOutput();
            System.out.println((counter + 1) + ".Value is " + offset);
            counter++;
        }
    }

    public static class deferredSynchronousThread extends Thread {

        private String delayedOutput = "*";
        Random random = new Random();

        @Override
        public void run() {
            delayedOutput = Integer.toString(syncRef.getOffset());
            //This delay is simulating the delay of which the client wants
            //until it is ready to request for the response of the server
            try { Thread.sleep(500 * (random.nextInt(3))); } 
            catch (InterruptedException ex) { return; }
        }

        public String delayedOutput() 
        { return delayedOutput; }
    }

    public static class asynchronousThread extends Thread 
    {
        private String delayedOutput = "*";
        Random random = new Random();
        Thread mainThread;

        @Override
        public void run() {
            delayedOutput = Integer.toString(syncRef.getOffset());
            //Interrupt the main thread when you are ready to respond
            mainThread.interrupt(); 
        }

        public void setMainThread(Thread mainThread) 
        { this.mainThread = mainThread; }

        public String delayedOutput() 
        { return delayedOutput; }
    }
}