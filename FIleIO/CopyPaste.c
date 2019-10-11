#include <stdio.h>

int CopyPaste_main() {

    //File copy and paste
    char input_file_name[100], output_file_name[100];
    scanf("%s" , input_file_name);
    scanf("%s", output_file_name);

    FILE *input_file, *output_file;
    input_file = fopen(input_file_name, "r");
    output_file = fopen(output_file_name, "w");

    if(input_file == NULL || output_file == NULL){
        puts("An error occurred");
    }else{
        char c;
        while(!feof(input_file)){
            fscanf(input_file, "%c", &c);
            fprintf(output_file,"%c", c);
        }

        fflush(output_file);

        fclose(input_file);
        fclose(output_file);

    }



    return 0;
}