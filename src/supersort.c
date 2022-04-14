#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    else
    {
        printf("supersort: '%s' is not a supersort command. See 'supersort --help'.\n", argv[1]);
    }

    return 0;
}
