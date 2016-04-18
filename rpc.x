struct client_data {
    int client_id;
    char client_msg[2048];
};

program RPC_PRG {
	version RPC_V1 {
		int put(struct client_data) = 1;
		int get(void) = 2;
	} = 1;
} = 0x20000001;
