#include "fileList.h"

int main(int argc,char *argv[]){
	char *d="\ec\e[44;36m";
	// check if you have the access to this file
	int n=0;
	print(d);
	if (argc>1){
		n=isAccess(argv[1]);
		printf("%d\n",n);
	}
	
	return 0;
}
