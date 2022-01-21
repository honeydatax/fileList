#include "fileList.h"
int main(int argc,char *argv[]){
	FILE  *f1;
	char cc[2080];
	printf("\ec\e[44;36m\a\n\n");
	if(argc>1){
	f1=fopen(argv[1],"r");
		if(f1!=NULL){
			while(!feof(f1)){
				cc[0]=0;
				fgetstr(cc,2070,">",f1);
				printf("%s\n",cc);
			}
			fclose(f1);
		}	
	}
	return 0;
}
