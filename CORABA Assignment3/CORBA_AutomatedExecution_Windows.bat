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