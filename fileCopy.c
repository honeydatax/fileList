#include "fileList.h"

int main(int argc,char *argv[]){
	char *d="\ec\e[44;36m";
	// copy files in argv 1 to argv2
	int n=0;
	print(d);
	if (argc>2){
		fileCopy(argv[1],argv[2]);
		
		
	}
	return 0;
}
