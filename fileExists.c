#include "fileList.h"

int main(int argc,char *argv[]){
	char *d="\ec\e[44;36m";
	// check file exists
	int n=0;
	print(d);
	if (argc>1){
		n=fileExists(argv[1]);
		printf("%d\n",n);
	}
	
	return 0;
}
