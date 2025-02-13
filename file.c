#include<stdio.h>
int main(int argc, char** argv){
	FILE *fp = fopen(argv[1],"r");
	if (fp == NULL) return 1;
	signed char c;
	while((c = fgetc(fp)) != EOF)
		printf("%c",c);
	fclose(fp);
	return 0;
}
