/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rpc.h"
#include <stdio.h>
#include <stdlib.h>

client_data messages[100] = {{-1, ""}};

//working
int *put_1_svc(struct client_data *argp, struct svc_req *rqstp) {
	static int  result;
	int id = argp->client_id;
//	char *msg = argp->client_msg;
//	int msg = argp->client_msg;
	
	
	int i = 0;
	while(messages[i] != {-1, ""}) {
		messages[i] = *argp;
	}
//	messages[0] =* argp;
	
	
	result = printf("Server: %s, %d\n", messages[0].client_msg, messages[0].client_id);
//	result = printf("Server: %s, %d\n", argp->client_msg, id);
//	result = printf("Server: %d, %d\n", msg, id);
//	result = 99;
	//result = printf("Server: Hello world");
	return (&result);
}

int *
get_1_svc(void *argp, struct svc_req *rqstp)
{
	static int  result;

	/*
	 * insert server code here
	 */

	return &result;
}
