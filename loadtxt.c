#include "fileList.h"
int main(int argc,char *argv[]){
	char *cc;
	char *ccc;
	printf("\ec\e[44;36m\a\n\n");
	if(argc>1){
		cc=loadtxt(argv[1],5000008);
		ccc=splitString(cc,'\n');
		printList(ccc);
		frees(ccc);
		frees(cc);
	}
	return 0;
}
