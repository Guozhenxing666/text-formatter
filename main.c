#include <stdio.h>
#include "head.h"
#include <stdlib.h>
#define WIDTH 50
int main()
{
    FILE *f = fopen("test", "r");
    FILE *fout = fopen("output", "w");
    if (f == NULL)
    {
        printf("Some error occured.");
    }
    char buffer[BUF_SIZE] = {'\0'};
    char *line;

    int pre_by_empln = 0;

    while ((line = fgets(buffer, BUF_SIZE, f)) != NULL)
    {
        char *t = remove_spaces(line);
        if (t[0] == '\n')
        {
            if (pre_by_empln == 1)
            {
                continue;
            }
            pre_by_empln = 1;
        }
        else
        {
            pre_by_empln = 0;
        }
        printf("%s", t);
        fprintf(fout, "%s", t);

        free(t);

        char *w = word_wrap(t, WIDTH);
        // printf("\n\nAfter wrap:\n");
        // printf("%s", w);

        // free(t);
        // free(w);
    }

    fclose(f);
    fclose(fout);
    return 0;
}