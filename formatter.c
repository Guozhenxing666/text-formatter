#include "head.h"
#include <stdlib.h>
#include <string.h>
char *remove_spaces(char *str)
{
    int pre_by_space = 0;
    char *res = malloc(strlen(str) + 1); // 需要调用者free
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            if (pre_by_space == 1)
            {
                i++;
                continue;
            }
            pre_by_space = 1;
        }
        else
        {
            pre_by_space = 0;
        }
        res[j++] = str[i++];
    }
    res[j] = '\0';
    return res;
}

char *word_wrap(char *str, int width)
{
    char *res = malloc(strlen(str) + 1); // 需要调用者free
    int i = 0, j = 0, count = 0;         // i是str串的游标, j是res串的游标, count是一行中已有的字符数
    int last_j;                          // 在res[]中上一个token后的一个位置
    int last_count;                      // 在res[]中截至上一个token的count总数
    while (str[i] != '\0')
    {

        if (count == width)
        {
            if (str[i] == ' ')
            {
                res[j++] = '\n';
                i++;
                count = 0;
                last_count = 0;
            }
            else
            {
                res[last_j] = '\n';
                count = count - last_count + 1;
                res[j++] = str[i];
            }
        }
        else
        {
            res[j++] = str[i];
            if (str[i] == ' ')
            {
                last_j = j;
                last_count = count;
            }
            count++;
        }
    }
    res[j] = '\0';
    return res;
}