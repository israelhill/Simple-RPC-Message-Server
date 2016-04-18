/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rpc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char* exe_fortune();


int main(int argc, char *argv[]){
    char *host;
    CLIENT *client;
    int *return_value, filler;
    char message[2048];


    if (argc < 4) {
        printf("Usage: %s server host\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = argv[1];

    if ((client = clnt_create(host, RPC_PRG, RPC_V1, "tcp")) == (CLIENT *) NULL) {
        clnt_pcreateerror(host);
        exit(EXIT_FAILURE);
    }

	struct client_data data;
	data.client_id = atoi(argv[2]);
	strcpy(data.client_msg, exe_fortune());

    //exe_fortune();

    printf("Client : Calling put function.\n");
    return_value = put_1(&data, client);

    if (return_value) {
        printf("Client: Put successful.\n");
    }
    else {
        printf("Client: Unable to display message.\n");
    }

    sleep(1);
    printf("Client : Calling get function.\n");
    return_value = get_1((void *) filler, client);

    if (return_value) {
        printf("Client: Get successful.\n");
    }
    else {
        printf("Client: Unable to display message.\n");
    }

    exit(EXIT_SUCCESS);
}

char* exe_fortune() {
    FILE *fp;
    static char path[2048];
    int status;

    /* Open the command for reading. */
    fp = popen("/usr/games/fortune", "r");
    if (fp == NULL) {
        printf("Failed to run command: fortune\n" );
        exit(1);
    }

    /* Read the output a line at a time - output it. */
    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        // do nothing
    }

    /* close */
    status = pclose(fp);
    if(status == -1) {
        perror("pclose()");
        exit(EXIT_FAILURE);
    }
    return path;
}
