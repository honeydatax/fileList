#include "fileList.h"
int main(int argc,char *argv[]){
	
	char *d="\ec\e[44;36m";
	char *cc;

	//  file name
	int n=0;
	print(d);
	
	if (argc>1){
		cc=fileName(argv[1]);
		print(cc);
		cc=file(argv[1]);
		print(cc);
		print("------ ");
		print(ext(argv[1]));
		frees(cc);
		
	}

	return 0;
}
