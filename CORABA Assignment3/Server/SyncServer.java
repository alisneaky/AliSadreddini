
import SyncService.*; // The skeleton and interfaces
import org.omg.CosNaming.*; // The naming service
import org.omg.CosNaming.NamingContextPackage.*; // The special name service exception package
import org.omg.CORBA.*; // Needed by all CORBA applications
import org.omg.PortableServer.*;
import org.omg.PortableServer.POA;

import java.util.Properties;
import java.util.Random;

public class SyncServer {

    public static void main(String[] args) {
        try {
            ORB orb = ORB.init(args, null);
            // Get a reference to the root POA and activate the POA manager
            POA rootpoa = POAHelper.narrow(orb.resolve_initial_references("RootPOA"));
            rootpoa.the_POAManager().activate();

            SyncImpl syncRef = new SyncImpl(); // Create servant and register with the ORB
            syncRef.setORB(orb);

            // Get an object reference for the servant
            org.omg.CORBA.Object ref = rootpoa.servant_to_reference(syncRef);
            Sync sRef = SyncHelper.narrow(ref);

            // Get root Naming Service context ... "NameService" invokes the name service
            org.omg.CORBA.Object objRef = orb.resolve_initial_references("NameService");
            // Convert Object reference to a NamingContext reference
            // From Java 1.4 on use NamingContextExt which complies with the
            // Interoperable Naming Service (INS) specification
            NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

            // Bind the Server reference into the Naming Context
            String name = "Sync";
            NameComponent[] path = ncRef.to_name(name);
            ncRef.rebind(path, sRef);

            System.out.println("Server waiting to be called ...");
            orb.run(); // wait for client invocations
        } catch (Exception e) {
            System.out.println("Error: " + e);
            e.printStackTrace(System.out);
        }
        System.out.println("HelloServer Exiting...");
    }
}

class SyncImpl extends SyncPOA {

    private ORB orb;
    private Random randyDelay = new Random();

    public void setORB(ORB orb_val) {
        orb = orb_val;
    }

    public int getOffset() {
		//Server decides how long to wait until it is ready to respond to client
		//This is simulated by the server thread going to sleep for a random amount of time
		//And then upon waking up, it sends an interrupt to client thread (MainThread)
		try { Thread.sleep(randyDelay.nextInt(5)); } 
		catch (InterruptedException ex) {   }
		
		return (randyDelay.nextInt(10));
    }
}