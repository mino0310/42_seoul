#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

int main(void)
{
    int n, i;
    scanf("%d", &n);

    std::vector<int> input(n);

    for (i = 0; i < n; i++) 
        scanf("%d", &input[i]);

    for (i = 0; i < n; i++) 
        if (input[i] < 0) 
            printf("%d ", input[i]);

    for (i = 0; i < n; i++)
        if (input[i] > 0) 
            printf("%d ", input[i]);

    return 0;
}

