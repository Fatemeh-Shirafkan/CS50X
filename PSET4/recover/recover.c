#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // make file for image

    FILE *drive = fopen(argv[1], "r");

    unsigned char *temp = malloc(512);

    char *filename = malloc(3 * sizeof(int));

    int image = 0;

    if (temp == NULL)
    {
        return 1;
    }

    if (filename == NULL)
    {
        return 1;
    }

    while (fread(temp , sizeof(unsigned char) , 512 , drive))
    {
       if(temp[0] == 0xff && temp[1] == 0xd8 && temp[2] == 0xff && (temp[3] &  0xf0) == 0xe0)
       {
        // name of the files

        sprintf(filename , "%03i.jpg" , image);
        FILE *imgf = fopen(filename , "w");
        fwrite (temp , 1 , 512 , imgf);
        fclose (imgf);

        image++;
       }
       else if (image != 0)
       {
        FILE *imgf = fopen(filename , "a");
        fwrite (temp , 1 , 512 , imgf);
        fclose (imgf);
       }
    }
    free(temp);
}