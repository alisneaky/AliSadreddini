C3044337 - Ali Sadreddini
SENG3400 - Bachelor of Software Engineering
2012 - Semester 2
Assignment 3
--------------------------------------------------------------------------------------
The project is organized in 3 different sections

You will find the IDL file (sync.idl) in the root directory, next to this Readme File

The Server file (SyncServer.java) within the Server Directory

The Client file (SyncClient.java) within the Client Directory

To compile and execture the project, the same steps as the assignment specifications
are to be taken.

If the project is to be run on a Windows machine, there's also a Batch file
available that will run the entire project from start to finish.

It shows the steps taken to compile and execture the ORB, the Server and the Client.
As well as running the Client itself and producing the output required by the specs.

The Content of the batch file is also included below in order to ensure security has
not been breached on the host machine.
---------------------------------------------------------------------------------------
@echo off
::Corba Complete Execution Batch File
cls
echo Creating Helper files for the Client
idlj -td Client -fclient sync.idl
timeout /T 1 >nul
echo Creating Helper files for the Server
idlj -td Server -fall sync.idl
timeout /T 1 >nul
echo Compiling Client
cd Client
javac SyncClient.java SyncService\*.java
timeout /T 1 >nul
cd..
echo Compiling Server
cd Server
javac SyncServer.java SyncService\*.java
timeout /T 1 >nul
echo Starting ORB
cd..
start orbd -ORBInitialPort 2222
timeout /T 2 >nul
echo Starting Server
cd Server
start java -cp . SyncServer -ORBInitialHost localhost -ORBInitialPort 2222
cd..
cd Client
timeout /T 2 >nul
echo Starting Client
cls
java SyncClient -ORBInitialHost localhost -ORBInitialPort 2222
cd..
tskill java
tskill orbd
cmd /k
---------------------------------------------------------------------------------------
The Client Program provides a way simulating the Client Server Interactions by the use 
of Threads within Java Environment.

For Synchronous interaction, a simple call is made to the server, and the server responds
with an answer to the client. There's no form of delay between the time the client makes 
the call to the server and the server responding.

However, in Deferred Synchronous interaction, The Client makes the call to the server,
by creating a thread to act on behalf of the server in real life. Once the client starts 
the thread, the thread puts itself to sleep for a moment. In the mean time, the client
continues on other tasks (printing 5 more *'s) and then joins the thread again and receives
the server response. This interaction simulates the presence of delay on the client's side
between the time that it calls the server and the time it actually requires the response.

For Asynchronous interaction, again a thread is made by the client to represent the server.
However, this time the client starts the thread when it would normally Call the server.
Then it continues on executing other tasks (printing indefinite number of *'s).

Then when the server is ready to respond back to the client, it sends an interrupt 
to the Main thread which is the client to provide it with the response.

The amount of delay between the time the server was called and its response, is a random
generated value defined by the server (server thread) which reprsents the Asynchronous
interaction between the two parties.
-------------------------------------------------------------------------------------------
























