#include "libft.h"

int         is_in_set(char c, char *set)
{
    int i;

    i = 0;
    while (set[i])
    {
        if (c == set[i])
        {
            return (1);
        }
        i++;
    }
    return (0);
}