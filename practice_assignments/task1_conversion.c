#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function that checks which data file is trying to be read
int checkfile(char *filename){
    int i;
    int extention = 0;
    for(i=0; i < 128 && extention == 0; i++){
        if(filename[i] == '.'){
            if(filename[i+1] == 'c' && filename[i+2] == 's' && filename[i+3] == 'v'){
                extention = 1;
                return 1;
            }
            else if(filename[i+1] == 'd' && filename[i+2] == 'a' && filename[i+3] == 't' && filename[i+4] == 'a'){
                extention = 1;
                return 2;
            }
            else{
                printf("invalid type \n");
                return 0;
            }
        }
    }
}

void _datafile(char *filename, char * newfilename){
    FILE *datafile, *xmlfile;
    char tags[64][256];
    datafile = fopen(filename, "r");
    xmlfile = fopen(newfilename, "w");

    if (datafile == NULL){
        fprintf(stderr, "\nCan't open input file [%s]!\n", filename);
    }
    else{
    printf("\nInput file [%s] opened \n", filename);
    printf("Creating .xml file [%s]. Please wait...", newfilename);

    int i = 0;
    int j = 2;
    int x = 0;
    int c = 1;


    while (!feof(datafile)){
        int a = fgetc(datafile);

// Filters out initial irrelevant strings
        if (j == 2){
            if(a < 65 && a != ' ' && a != '\n'){
                    while(!(a == '\r' || a == '\n' || a == '\v' || a == '\t' || a == '  ' || a == '\f')){
                        a = fgetc(datafile);
                    }
            }
            else{
                j=0;
            }
        }

// Tag creation loop
        else if (j == 0){
            if(a == '\r' || a == '\n' || a == '\v' || a == '\t' || a == '\f' || a == ' '){
                i=0;
                fprintf(xmlfile, "<Report> \n");
                fprintf(xmlfile, "  <Object>\n");
                fprintf(xmlfile, "    <%s>", tags[i] );
                j = 1;

                a = fgetc(datafile);

                if(a == '\r' || a == '\n' || a == '\v' || a == '\t' || a == '\f'){

                }

                else if (a == ' '){
                    tags[i][x] = '_';
                    x++;
                }
                else{
                    if (a != ',' && a!= ' '){
                        tags[i][x] = a;
                        x++;
                    }
                    else{
                        x = 0;
                        i++;
                    }
                    }
                }


            else{
                if (a != ','){
                    tags[i][x] = a;
                    x++;
                }
                else{
                    x = 0;
                    i++;
                }

            }
        }

        else if (a == EOF){
            fprintf(xmlfile, "</%s>\n", tags[i]);
            fprintf(xmlfile, " </Object>\n", c);
        }

// Main printing loop
        else{
            if(a == '\r' || a == '\n' || a == '\v' || a == '\t'){
                fprintf(xmlfile, "</%s>\n", tags[i]);
                fprintf(xmlfile, "  </Object>\n");
                i = 0;
                c++;
                fprintf(xmlfile, "  <Object>\n");
                fprintf(xmlfile, "    <%s> ", tags[i]);
            }
            else if (a != ','){
                fprintf(xmlfile, "%c", a);
            }

            else{
                fprintf(xmlfile, "</%s>\n", tags[i]);

                i++;
                fprintf(xmlfile, "    <%s> ", tags[i]);
            }
        }
    }
    printf("\n\nCompleted creating %s \n", newfilename);
    printf("No. of data items created: %d\n\n", c);
    fprintf(xmlfile, "</Report>");
    fclose(datafile);
    fclose(xmlfile);
    }
}

void _csvfile(char *filename, char *newfilename){
    FILE *csvfile, *xmlfile;
    char tags[64][256];
    csvfile = fopen(filename, "r");
    xmlfile = fopen(newfilename, "w");

    if (csvfile == NULL){
        fprintf(stderr, "\nCan't open input file [%s]!\n", filename);
    }
    else{
    printf("\nInput file [%s] opened \n", filename);
    printf("Creating .xml file [%s]. Please wait...", newfilename);

    int i = 0;
    int j = 0;
    int x = 0;
    int c = 1;


    while (!feof(csvfile)){
        int a = fgetc(csvfile);

// tag creation loop
        if(j == 0){
            if(a == '\r' || a == '\n' || a == '\v'){
                i=0;
                fprintf(xmlfile, "<Report> \n");
                fprintf(xmlfile, "  <Object>\n", c);
                fprintf(xmlfile, "       <%s> ", tags[i] );
                j = 1;

            }
            else{
                if (a == ' '){
                    tags[i][x] = '_';
                    x++;
                }
                else if (a != ','){
                    tags[i][x] = a;
                    x++;
                }
                else{
                    x = 0;
                    i++;
                }

            }
        }

        else if (a == EOF){
            fprintf(xmlfile, "</%s>\n", tags[i]);
            fprintf(xmlfile, "  </Object>\n", c);
        }

// Main printing loop

        else{
            if(a == '\r' || a == '\n' || a == '\v'){
                fprintf(xmlfile, "</%s>\n", tags[i]);
                fprintf(xmlfile, "  </Object>\n", c);
                i = 0;
                c++;
                fprintf(xmlfile, "  <Object>\n");
                fprintf(xmlfile, "       <%s> ", tags[i]);
            }
            else if (a != ','){
                fprintf(xmlfile, "%c", a);
            }

            else{
                fprintf(xmlfile, "</%s>\n", tags[i]);

                i++;
                fprintf(xmlfile, "       <%s> ", tags[i]);
            }
        }

    }

    printf("\n\nCompleted creating %s \n", newfilename);
    printf("No. of data items created: %d\n\n", c);

    fprintf(xmlfile, "</Report>");
    fclose(csvfile);
    fclose(xmlfile);
    }
}


// The end function that can get called in main
void conversion_main(){
    char *filename[128];
    char *newfilename[128];

    printf("Please enter the input file name: ");
    scanf("%s", &filename);

    printf("Please enter the output file name: ");
    scanf("%s", &newfilename);

// Checks for the right data format and performs the function
    if (checkfile(filename) == 1){
        _csvfile(filename, newfilename);
    }
    else if(checkfile(filename) == 2){
        _datafile(filename, newfilename);
    }
    else{
        printf("Invalid file name \n");
    }

}


