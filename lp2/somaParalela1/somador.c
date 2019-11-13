#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char* fileName;
	FILE *fs;
	int i;
	char c;
	int num_read;
	int sum = 0;

	if (argc < 2) {
		printf("usage: %s <filename.txt>\n",argv[0]);
		exit(-1);
	}
	

	fileName = argv[1];

	// printf("Reading file: %s\n",fileName);

	fs = fopen(fileName, "r");
	

	while (!feof(fs)) {
		c = getc(fs);
		if (feof(fs)) break;
		if (c != '\n') {
			num_read = c - 48;
			sum += num_read;
			// printf("lido: %d\n",num_read);	
		} 
	}	

	printf("%d\n",sum);	

	return 0; 
	

}
