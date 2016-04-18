CC = clang
CFLAGS = -g -Wall
LIBS =
CSOURCE = client.c rpc_clnt.c rpc_xdr.c
SSOURCE = server.c rpc_svc.c rpc_xdr.c
RPCSRC = rpc.x
RPCGEN = rpc.h rpc_clnt.c rpc_svc.c rpc_xdr.c
CLIENT = client
SERVER = server

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CSOURCE) $(RPCGEN)
	$(CC) $(CSOURCE) -o $(CLIENT)

$(SERVER): $(SSOURCE) $(RPCGEN)
	$(CC) $(SSOURCE) -o $(SERVER)

$(RPCGEN): $(RPCSRC)
	rpcgen $(RPCSRC)

clean:
	@# Using the '@' sign suppresses echoing
	@# the line while the command is run
	rm -f $(CLIENT) $(SERVER) $(RPCGEN)
