/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "rpc.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

char* get_time();
int check_for_multiple_clients(int id);

client_data messages[100] = {{-1, ""}};
int client_req_num = 0;
int current_client_id;
int past_client = 0;
int count;

int *put_1_svc(struct client_data *argp, struct svc_req *rqstp) {
	static int  result;
	int id = argp->client_id;
	current_client_id = argp->client_id;

	messages[client_req_num] = *argp;

	result = printf("Server Says-- Put() Request: \"%s\" from Client_%d at %s\n", messages[client_req_num].client_msg,
					messages[client_req_num].client_id, get_time());
	client_req_num++;
	return (&result);
}

struct response *get_1_svc(void *argp, struct svc_req *rqstp) {
	static struct response  result;

	if(check_for_multiple_clients(current_client_id) == -1) {
		result.status_code = -1;
		return &result;
	}

	int found_msg = 0;
	int i;

	while(found_msg == 0) {
		int rand_val = rand() % (client_req_num - 1);
		int id = messages[rand_val].client_id;

		if(client_req_num <= 1) {
			// You are the first client to request a msg. Only your msg is saved at this point.
			result.status_code = -1;
			return &result;
		}
		else if(id != current_client_id) {
			found_msg = 1;
			//result = printf("Server Says-- Get() Request at %s. Message: \"%s\"\n", get_time(), messages[rand_val].client_msg);
			result.status_code = 0;
			strcpy(result.message, messages[rand_val].client_msg);
		}
	}

	return &result;
}

// this function checks if there is only one client who has visited the server so far
int check_for_multiple_clients(int id) {
	if(past_client == 0) {
		past_client = id;
		count++;
		return -1;
	}

	if(past_client == id && count == 1) {
		return -1;
	}
	else {
		count++;
		return 0;
	}


}


char* get_time() {
	time_t rawtime;
	struct tm *timeinfo;

	time (&rawtime);
	timeinfo = localtime(&rawtime);
	return asctime(timeinfo);
}