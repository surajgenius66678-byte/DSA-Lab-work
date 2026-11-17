
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    if (size <= 0)
        return 0;

    int arr[size];

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    int *pos = NULL, *neg = NULL;
    int n_pos = 0, n_neg = 0;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] >= 0)
        {
            pos = realloc(pos, sizeof(int) * (n_pos + 1));
            pos[n_pos++] = arr[i];
        }
        else
        {
            neg = realloc(neg, sizeof(int) * (n_neg + 1));
            neg[n_neg++] = arr[i];
        }
    }

    int *ans = malloc(size * sizeof(int));

    if (abs(n_pos - n_neg) > 1)
    {
        printf("Not Possible");

        free(pos);
        free(neg);
        free(ans);

        return 0;
    }

    int i = 0, j = 0, k = 0;

    if (n_pos > n_neg)
    {
        while (i < n_pos || j < n_neg)
        {
            if (i < n_pos)
                ans[k++] = pos[i++];

            if (j < n_neg)
                ans[k++] = neg[j++];
        }
    }
    else
    {
        while (i < n_pos || j < n_neg)
        {
            if (j < n_neg)
                ans[k++] = neg[j++];

            if (i < n_pos)
                ans[k++] = pos[i++];
        }
    }

    for (int i = 0; i < size; i++)
        printf("%d ", ans[i]);

    free(pos);
    free(neg);
    free(ans);

    return 0;
}
