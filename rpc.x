struct client_data {
    int client_id;
    char client_msg[7999];
};

struct response {
    int status_code;
    char message[7999];
}

program RPC_PRG {
	version RPC_V1 {
		int put(struct client_data) = 1;
		struct response get(void) = 2;
	} = 1;
} = 0x20000001;
