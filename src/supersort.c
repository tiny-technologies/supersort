#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "algorithms.h"

void print_usage_main()
{
    printf("usage: supersort <command> [<args>]\n\n");
    printf("These are common supersort commands:\n\n");
    printf("\trun\tRun various supersort algorithms on std input\n");
    printf("\tbench\tBench supersort algorithms performances\n");
}

void print_usage_run()
{
    printf("usage: supersort run <algorithm>\n\n");
    printf("valid algorithms are: insertion, selection, bubble\n\n");
}

void print_usage_bench()
{
    printf("usage: supersort bench\n\n");
    printf("applies various sort algorithms on random arrays with different lenghts\n\n");
}

int run(char *name)
{
    void (*sort)(int array[], int len);
    if (strcmp(name, "bubble") == 0)
    {
        sort = bubble_sort;
    }
    else if (strcmp(name, "insertion") == 0)
    {
        sort = insertion_sort;
    }
    else if (strcmp(name, "selection") == 0)
    {
        sort = selection_sort;
    }
    else
    {
        return 1;
    }

    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);

    const char delimiter[2] = " ";
    char *token = strtok(buffer, delimiter);

    int array[16];
    int length = 0;
    while (token != NULL)
    {
        array[length++] = atoi(token);
        token = strtok(NULL, delimiter);
    }

    sort(array, length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void bench(void (*sort)(int array[], int length))
{
    const int step = 1000;
    int array[step * 10];

    for (int i = step; i <= step * 10; i += step)
    {
        for (int j = 0; j < i; j++)
        {
            array[j] = rand();
        }
        long int time = clock();
        sort(array, i);
        printf("%10d %10.3f ms\n", i, (double)(clock() - time) / (CLOCKS_PER_SEC / 1000));
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1 || strcmp(argv[1], "--help") == 0)
    {
        print_usage_main();
        exit(1);
    }

    if (strcmp(argv[1], "run") == 0)
    {
        if (argc != 3 || strcmp(argv[2], "--help") == 0)
        {
            print_usage_run();
            exit(1);
        }

        if (run(argv[2]) == 1)
        {
            print_usage_run();
            exit(1);
        }
    }
    else if (strcmp(argv[1], "bench") == 0)
    {
        if (argc != 2)
        {
            print_usage_bench();
            exit(1);
        }

        printf("\nBUBBLE SORT\n");
        printf("%10s %10s\n", "elements", "speed");
        bench(bubble_sort);

        printf("\nSELECTION SORT\n");
        printf("%10s %10s\n", "elements", "speed");
        bench(selection_sort);

        printf("\nINSERTIONS SORT\n");
        printf("%10s %10s\n", "elements", "speed");
        bench(insertion_sort);
    }
    else
    {
        printf("supersort: '%s' is not a supersort command. See 'supersort --help'.\n", argv[1]);
    }

    return 0;
}
