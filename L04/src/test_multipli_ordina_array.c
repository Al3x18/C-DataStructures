#include <stdio.h>
#include <stdlib.h>
#include "vettore.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Numero parametri non corretto\n");
        printf("Usage: <path_to_test_suite_file>.txt\n");
        exit(1);
    }

    FILE *test_suite_file;
    FILE *results_file;

    test_suite_file = fopen(argv[1], "r");
    results_file = fopen("outputs/results.txt", "w");

    if (test_suite_file == NULL)
    {
        printf("Errore nell'apertura del file di test\n");
        exit(1);
    }

    if (results_file == NULL)
    {
        printf("Errore nella creazione del file di risultati\n");
        exit(1);
    }

    char file_name[20];
    int array_length;

    while (fscanf(test_suite_file, "%s %d", file_name, &array_length) == 2)
    {
        int *array = (int *)calloc(array_length, sizeof(int));

        if (array == NULL)
        {
            printf("Errore nell'allocazione della memoria\n");
            exit(1);
        }

        char input_file_name[50];
        char output_file_name[50];

        snprintf(input_file_name, sizeof(input_file_name), "test_files/%s_input.txt", file_name);
        snprintf(output_file_name, sizeof(output_file_name), "outputs/%s_output.txt", file_name);

        finput_array(input_file_name, array, array_length);
        ordina_array(array, array_length);
        foutput_array(output_file_name, array, array_length);

        char oracle_file_name[50];
        snprintf(oracle_file_name, sizeof(oracle_file_name), "test_files/%s_oracle.txt", file_name);

        int *oracle = (int *)calloc(array_length, sizeof(int));

        if (oracle == NULL)
        {
            printf("Errore nell'allocazione della memoria oracle array\n");
            exit(1);
        }

        finput_array(output_file_name, oracle, array_length);

        if (confronta_array(array, oracle, array_length))
        {
            fprintf(results_file, "%s PASS\n", file_name);
        }
        else
        {
            fprintf(results_file, "%s FAILED\n", file_name);
        }

        free(array);
        free(oracle);
    }

    printf("++++ BUILD DONE, CHECK OUTPUTS FOLDER FOR RESULTS ++++\n");

    fclose(test_suite_file);
    fclose(results_file);

    return 0;
}