/**
 * * Name: Kadejha Jones 
 * * Lab/task: Lab 2
 * * Date: 09/5/2022
 * **/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(){
        printf("USAGE: \n\
   sub [ -h | --fromChars -+toChars [-i inputFile] [-o outputFile] ]\n\
\n\
DESCRIPTION:\n\
   This utility copies text from an input stream to an output stream replacing every\n\
   instance of a specific character in fromChars with a corresponding (position-wise)\n\
   character from toChars. Any characters in fromChars and in toChars that do not\n\
   have corresponding counterparts in the other one are ignored. If an input file is\n\
   provided, the content is read from that file; otherwise, the standard input is used.\n\
   If an output file is provided, then the modified content is written to that file;\n\
   otherwise, the standard output is used.\n\
\n\
OPTIONS:\n\
   -- (followed by a string without separating space)\n\
     indicates all characters that will be replaced in the processed text\n\
   -+ (followed by a string without separating space)\n\
     indicates the characters that will be used to replace corresponding\n\
     (position-wise) characters from fromChars in the processed text\n\
   -i (followed by input file name)\n\
     use the provided file as an input stream instead of standard input\n\
   -o (followed by output file name)\n\
     use the provided file as an output stream instead of standard output\n\
   -h prints this help message; it is also a default if no command line\n\
     arguments are provided\n");
}

int main(int arg, char *argv[]){
	char *fs;
	char *rs;

	FILE *in = stdin;
	FILE *out = stdout;

	char filePath[50];

	//printf("enter the file name that is being read: \n");
	//scanf("%s", filePath);
	if (arg <= 1){
		print();
	} else {
		for (int i = 1; i < arg; i++){
			if(argv[1][0] == '-'){
				switch (argv[1][1]){
                                case '-':
					//find
					fs = &argv[i][2];
                                        break;
			 	case 'i':
					in = fopen(argv[i+1], "r");
                                        if(in == NULL){
						printf("ERROR");
						break;
					}
					break;
				case 'h': 
					print();
					break;
				case 'o':
					out = fopen(argv[i+1], "w");
					if(out == NULL){
						printf("ERROR");
						break;
					}
					break;
				case '+': 
					//replace
					rs = &argv[i][2];
					break;
				default: 
					break;
                                }

			}
			printf("ERROROROROROR");

		}

		int length = strlen(fs);
		int outLength = strlen(rs);

		if(length > outLength){
			printf("sub: WARNING - extraneous replacement character");
		}	

		if(length < outLength){
                	printf("sub: ERROR - missing replacement character");
        	}
	}
	
	return 0;

}

