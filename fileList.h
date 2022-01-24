#include <dirent.h>
#include "cstring.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
char *fileLists(char *directory){
	char *lst;
	struct dirent *ldir;
	char *s;
	int lens=0;
	int total=0;
	char r[2080];
	lst=NULL;
	DIR *dir=opendir(directory);
	if(dir==NULL)return lst;
	//list directorys
	ldir=readdir(dir);
	while(ldir!=NULL){
		if(ldir->d_name!=NULL){
			lens=strlen(ldir->d_name);
			if (lens>2070)lens=2070;
			strncpy(r,ldir->d_name,(int)lens+1);
			r[lens];
			if (total==0){
				if (ldir->d_type==DT_DIR){
					lst=newList(r);
					total++;
				}
			}else{
				if (ldir->d_type==DT_DIR){
					lst=addList(lst,r);
					total++;
				}
			}
			ldir=readdir(dir);
		}
	}
	//list files
	dir=opendir(directory);
	if(dir==NULL)return lst;
	ldir=readdir(dir);
	while(ldir!=NULL){
		if(ldir->d_name!=NULL){
			lens=strlen(ldir->d_name);
			if (lens>2070)lens=2070;
			strncpy(r,ldir->d_name,(int)lens+1);
			r[lens];
			if (total==0){
				if (ldir->d_type!=DT_DIR){
					lst=newList(r);
					total++;
				}
			}else{
				if (ldir->d_type!=DT_DIR){
					lst=addList(lst,r);
					total++;
				}
			}
			
			ldir=readdir(dir);
		}
	}
	return lst;
}

void fileCopy(char *file1,char *file2){
	char cc[2080];
	char *ccc;
	int f1;
	int f2;
	size_t sizes;
	ccc=cc;
	if (file1!=NULL && file1!=NULL){
		f1=open(file1,O_RDONLY);
		f2=creat(file2,O_WRONLY);
		if(f1>0 && f2>0){
			sizes=2070;
			while(sizes!=0){
				sizes=read(f1,ccc,2070);
				write(f2,&ccc,sizes);				
			}
		}
	}
}
int fileExists(char *file){
	FILE* f1;
	if(file==NULL) return 0;
	f1=fopen(file,"r");
	if(errno==2)return 0;
	if(f1!=NULL){
		fclose(f1);
		return -1;
	}else{
		if(errno!=2)return -1;
		return 0;
	}
	if(errno!=2)return -1;
	return 0;
}
char *fgetstr(char *c,int sizes,char *s,FILE * f1){
	int ipos=0;
	int poss=0;
	char *cc;
	char *ccc;
	cc=c;
	if (sizes>3){
		ipos=ftell(f1);
		poss=fread(c,sizes-2,1,f1);
		c[sizes-1]=0;
		if (poss >4)c[poss+1]=0;
		ccc=strstr(c,s);
		if (ccc!=NULL){
			ccc[0+strlen(s)]=0;
			ipos=ipos+strlen(c);
			fseek(f1,ipos,SEEK_SET);
		}
		
	}else{
		cc=NULL;
		return cc;
	}
	return cc;
}
char *fgetcol(char *c,int sizes,FILE * f1){
	int ipos=0;
	int poss=0;
	char *lns="\n";
	char *cc;
	char *ccc;
	cc=c;
	if (sizes>3){
		ipos=ftell(f1);
		poss=fread(c,sizes-2,1,f1);
		c[sizes-1]=0;
		if (poss >4)c[poss+1]=0;
		ccc=strstr(c,lns);
		if (ccc!=NULL){
			ccc[0+strlen(lns)]=0;
			ipos=ipos+strlen(c);
			fseek(f1,ipos,SEEK_SET);
		}
		
	}else{
		cc=NULL;
		return cc;
	}
	return cc;
}
int isAccess(char *file){
	FILE* f1;
	if(file==NULL) return 0;
	f1=fopen(file,"r");
	if(f1!=NULL){
		fclose(f1);
		return -1;
	}else{
		return 0;
	}
	return 0;
}

char *loadtxt(char *argv,int sizes){
	int n;
	char *c;
	char *cc;
	char *ccc;
	char *cccc;
	FILE* f;
	int style3=0;
	int style2=0;
	int style=0;
	c=NULL;
	int r=0;
		if(argv!=NULL){
			f=fopen(argv,"r");
			if (f!=NULL){
				fseek(f,0,SEEK_END);
				n=ftell(f);
				if(n<sizes+1){
					fseek(f,0,SEEK_SET);
					c=malloc(n+5);
					if (c!=NULL){
						style=0;
						c[0]=0;
						fread(c,n,1,f);
						c[n]=0;
						r=0;
						ccc=c;
			
					}
				}
			}
		}
	return c;
}

