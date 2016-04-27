# RPC Message Server

Each client will send 5 messages to the server at 1 second intervals. Clients will then wait 5 seconds
before requesting 10 messages at 1 second intervals. The server will only send messages back to the client
that were posted by other clients. If there are no messages for the client, the server will return
a struct containing a status code of -1 and an empty string. If there are messages on the server that do not
belong to the client, the server will return one at random in a struct along with a status code of 0.
The server only allows 3 unique clients to read and write to the server.

If a 4th client attempts to communicate with the server via get() or put(), he will receive the error status code -1.

## Run Existing Code _(Recommended)_

To run the program, you first need to start the server. I use _eecslinab7_ as the server. You then need to start 3
clients. I recommend that you make these calls in two separate terminal tabs so that the server and client outputs
do not get mixed together.

$ ssh -f idh@eecslinab7 "./assignment7/server"

$ ssh -f idh@eecslinab3 "./assignment7/client eecslinab7"; ssh -f idh@eecslinab3 "./assignment7/client eecslinab7"; ssh -f idh@eecslinab3 "./assignment7/client eecslinab7";

## Run Downloaded Code

If you run the code by downloading it, and not using the code that is already on the servers, you will need to
first run make. After running make, you will need to update the executables on each server via SFTP or some
filer transfer client like Filezilla. These executables need to be in the _/home/idh/assignment7_ directories on each
server.

$ make

_Update the executables on each server with the executables produced by make._


$ ssh -f idh@eecslinab7 "./assignment7/server"

$ ssh -f idh@eecslinab3 "./assignment7/client eecslinab7"; ssh -f idh@eecslinab3 "./assignment7/client eecslinab7"; ssh -f idh@eecslinab3 "./assignment7/client eecslinab7";
