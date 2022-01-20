#include "fileList.h"

int main(int argc,char *argv[]){
	char *d="\ec\e[44;36m";
	//list all files in argv 1
	char *lst;
	int n=0;
	char *dirs=".";
	print(d);
	if (argc>1){
		lst=fileLists(argv[1]);
		printList(lst);
		freeList(lst);
	}
	return 0;
}
