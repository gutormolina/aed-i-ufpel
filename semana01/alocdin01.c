#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", v[i]);
    }
    free(v);
}