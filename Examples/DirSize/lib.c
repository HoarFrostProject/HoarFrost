#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include "lib.h"

int fileSize(char* path) {
	struct stat st;
	stat(path, &st);
	return st.st_size;
}

int dirSize(char* path) {
	DIR* d;
	struct dirent* dir;
	int totalSize = 0;
	
	d = opendir(path);
	if (d) {
		while ((dir = readdir(d)) != NULL) {
			totalSize += fileSize(dir->d_name);
		}
	}
	closedir(d);
	return totalSize;
}
