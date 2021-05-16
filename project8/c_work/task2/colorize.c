#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "ppmIO.h"

// Define the maximum number of threads for the program.
int THREAD_MAX = 2;

// This struct holds essential **thread control parameters**. This is used to keeep track of the threads while conducting the merge sort. The most important is the POSIX thread id, which makes it so we don't 
// accidentally get any race conditions.
struct tcp {
	Pixel *src;
    int tcp_id;
    int tcp_low;
    int tcp_high;
};

/*
 * Function:  process_bold
 * --------------------
 * Processes a subarray of pixels and amplifies the colors.
 * 
 * returns: N/A
 */
void *process_bold(void *thread){
	struct tcp *tcp = thread;
	int low;
	int high;

	// Get low and high for the given thread that is passed in by arg.
	low = tcp->tcp_low;
	high = tcp->tcp_high;
	Pixel *src = tcp->src;

	for(int i = low; i < high; i++) {
		src[i].r = src[i].r > 128 ? (220+src[i].r)/2 : (30+src[i].r)/2;
		src[i].g = src[i].g > 128 ? (220+src[i].g)/2 : (30+src[i].g)/2;
		src[i].b = src[i].b > 128 ? (220+src[i].b)/2 : (30+src[i].b)/2;
	}
	return 0;
}

/*
 * Function:  process_neg
 * --------------------
 * Processes a subarray of pixels and turns the section fo the image to negative colors.
 * 
 * returns: N/A
 */
void *process_neg(void *thread){
	struct tcp *tcp = thread;
	int low;
	int high;

	// Get low and high for the given thread that is passed in by arg.
	low = tcp->tcp_low;
	high = tcp->tcp_high;
	Pixel *src = tcp->src;

	for(int i = low; i < high; i++) {
		src[i].r = 255 - src[i].r;
		src[i].g = 255 - src[i].g;
		src[i].b = 255 - src[i].b;
	}
	return 0;
}


/*
 * Function:  process_bw
 * --------------------
 * Processes a subarray of pixels and turns the subsection of the image to black and white.
 * 
 * returns: N/A
 */
void *process_bw(void *thread){
	struct tcp *tcp = thread;
	int low;
	int high;
	Pixel *src = tcp->src;

	// Get low and high for the given thread that is passed in by arg.
	low = tcp->tcp_low;
	high = tcp->tcp_high;

	double avg;

	for(int i = low; i < high; i++) {
		avg = (src[i].r + src[i].g + src[i].b) / 3;
		src[i].r = avg;
		src[i].g = avg; 
		src[i].b = avg;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	Pixel *src;
	int rows, cols, colors;
	int i;

	char* filter;
	char* filename;
	char *cp;
    struct tcp *tcp;

	// check usage
	if( argc < 3 ) {
		printf("Usage: %s <image filename> <filter>\n", argv[0]);
		printf("Filter options are 'bw' (black and white), 'bold' (high contrast), 'neg' (negative colors)\n");
		exit(-1);
	}

	filter = argv[2];

	// read image and check for errors
	src = ppm_read( &rows, &cols, &colors, argv[1] );
	if( !src ) {
		printf("Unable to read file %s\n", argv[1]);
		exit(-1);
	}

	// Initialize an array of threads and associated thread control parameter structs. 
	pthread_t threads[THREAD_MAX];
	struct tcp tcplist[THREAD_MAX];

	// Get the proper length of subarray.
	int len = (rows * cols) / THREAD_MAX;

	int low = 0;

	// Partition the subarrays out, assign proper thread control parameters to the list of them.
	for (int i = 0; i < THREAD_MAX; i++, low += len) {
		tcp = &tcplist[i];
		tcp->tcp_id = i;
		tcp->src = src;
		tcp->tcp_low = low;
		tcp->tcp_high = low + len - 1;
		if (i == (THREAD_MAX - 1)){
			tcp->tcp_high = (rows * cols) - 1;
		}
	}

	// Create THREAD_MAX threads and run the iamge processing for each thread
	for (int i = 0; i < THREAD_MAX; i++) {
		tcp = &tcplist[i];
		if (strcmp(filter, "bold") == 0){
			filename = "bold.ppm";
			pthread_create(&threads[i], NULL, process_bold, tcp);
		} else if (strcmp(filter, "neg") == 0){
   			filename = "neg.ppm";
			pthread_create(&threads[i], NULL, process_neg, tcp);
		} else if (strcmp(filter, "bw") == 0){
			filename = "bw.ppm";
			pthread_create(&threads[i], NULL, process_bw, tcp);
		} else{
			printf("Invalid filter option provided. Please try again. \n");
		}
	}

	// Join all the created threads.
	for (int i = 0; i < THREAD_MAX; i++)
		pthread_join(threads[i], NULL);

	// write out the image
	ppm_write(src, rows, cols, colors, filename);

	free(src);

	return(0);
}

	
