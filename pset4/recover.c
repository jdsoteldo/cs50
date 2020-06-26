#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    // ensures only two command line arguments
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    char *raw_file = argv[1];
    FILE *file_ptr = fopen(raw_file, "r");
    if (file_ptr == NULL)
    {
        fprintf(stderr, "Could not open file %s.\n", raw_file);
        return 2;
    }

    unsigned char *buffer = malloc(512);
    int jpg = 0;
    FILE *image;

    while (fread(buffer, 512, 1, file_ptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
            // checks the first 4 buffers to compare to a JPEG file
        {
            // close previous file
            if (jpg > 0)
            {
                fclose(image); // closes the image
            }

            // create filename
            char filename[5];
            sprintf(filename, "%03i.jpg", jpg);
            // open new image file
            image = fopen(filename, "w");

            if (image == NULL)
            {
                fclose(file_ptr);
                free(buffer);
                fprintf(stderr, "Could not create output JPG %s", filename);
                return 3;
            }

            jpg++;
        }

        // if not found, skip
        if (!jpg)
        {
            continue;
        }

        // write into the file
        fwrite(buffer, 512, 1, image);
    }

    fclose(file_ptr);
    fclose(image);

    free(buffer);

    return 0;
}
