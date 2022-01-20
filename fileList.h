#include <dirent.h>
#include "cstring.h"
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
