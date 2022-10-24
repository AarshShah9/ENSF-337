// ENSF 337 - lab 6 - exercise b
// M. Moussavi
// lab5exe_B.c

#include <stdio.h>
#include <stdlib.h>
#include "lab6exe_B.h"

int main(void)
{
    char input_filename[30] = "lab6exe_B.txt";
    char output_filename[30] = "lab6exe_B_output.txt";
    IntVector intVec;
    intVec.number_of_data = 0;

    read_text_file(&intVec, input_filename);

    display_single_column(&intVec);

    display_multiple_column(&intVec, 4, output_filename);

    return 0;
}

void read_text_file(IntVector *vec, const char *input_filename)
{
    int nscan;
    FILE *fp = fopen(input_filename, "r");

    if (fp == NULL)
    {
        fprintf(stdout, "Sorry cannot open the text file %s.\n", input_filename);
        exit(1);
    }

    do
    {
        nscan = fscanf(fp, "%d", &vec->storage[vec->number_of_data]);
        if (nscan == 1)
            (vec->number_of_data)++;
        else if (nscan != EOF)
        {
            fprintf(stderr, "Invalid data in %s.\n", input_filename);
            exit(1);
        }
    } while ((nscan != EOF) & (vec->number_of_data < MAX_CAPACITY));

    fclose(fp);
}

void display_single_column(const IntVector *intV)
{
    int i;
    for (i = 0; i < intV->number_of_data; i++)
        printf("%10d\n", intV->storage[i]);
}

void display_multiple_column(const IntVector *intV, int col, const char *output_filename)
{
    // STUDENTS MUST COMPLETE THE DEFINITION OF THIS FILE
    /* REQUIRES: intV points to an existing object of IntVector. col > 0.
     * PROMISES: opens a text file with the given name by the string filename, and
     *           saves the data in the storage array of intV, into the opened text
     *           file, in tabular format (like a table depending on the value of col).
     *           For example if col is 3 and storage contains values:
     *           30, 40, 50, 70, 90, 3, 4, 5. It will print the data into the text
     *           file in 3 columns, as follows:
     *           30  40  50
     *           70  90   3
     *            4   5
     *           However, if col is greater than or equal number of the data in the
     *           array,for example, 8 or more, the data will be saved in the following
     *           format (8 columns but only one row):  30  40  50  70  90  3  4  5
     *           In other words, columns in the file, will be the number of data
     *           in the array printed in one row.
     */
    FILE *fp2 = fopen(output_filename, "w");
    if (fp2 == NULL)
    {
        exit(1);
    }

    if (col >= (intV->number_of_data))
    {

        for (int i = 0; i < intV->number_of_data; i++)
        {
            fprintf(fp2, "%d ", intV->storage[i]);
        }
    }
    else if (col < (intV->number_of_data))
    {

        for (int i = 0; i < intV->number_of_data; i++)
        {
            if (i % 3 == 0 && i != 0)
            {
                fprintf(fp2, "\n");
            }
            fprintf(fp2, "%d ", intV->storage[i]);
        }
    }
    fclose(fp2);
}
