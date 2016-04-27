**RPC Message Server**

Each client will send 5 messages to the server at 1 second intervals. Clients will then wait 5 seconds
before requesting 10 messages at 1 second intervals. The server will only send messages back to the client
that were posted by other clients. If there are no messages for the client, the server will return
a struct containing a status code of -1 and an empty string. If there are messages on the server that do not
belong to the client, the server will return one at random in a struct along with a status code of 0.
The server only allows 3 unique clients to read and write to the server.

If a 4th client attempts to communicate with the server via get() or put(), he will receive the error status code -1.
