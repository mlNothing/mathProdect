#include <stdio.h>
#include <string.h>
void Index_bf(char one[], char two[])
{
    int i = 0, j = 0;
    while (i < strlen(one) && j < strlen(two))
    {
        printf("i=%d j=%d\n", i, j);
        if (one[i] == two[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    printf("===i=%d j=%d\n", i, j);

    if (j >= strlen(two) - 1) //匹配成功
    {
        printf("%d", i - strlen(two));
        return;
    }
    printf("匹配失败\n");
    return;
}
int main()
{
    char one[13] = "aaaab";
    char two[13] = "ab";
    Index_bf(one, two);
    return 0;
}