#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct item item_t;
typedef struct item
{
    int value;
    int degree;
    item_t *child_list;
    bool mark;
} item;

item *list_init(int size)
{
    if (size < 1)
        return NULL;

    item *list = malloc(size * sizeof(item));

    if (list == NULL)
        return NULL;

    for (int i = 0; i < size; i++)
    {
        list[i].child_list = NULL;
        list[i].degree = 0;
        list[i].mark = false;
        list[i].value = -1;
    }

    return list;
}

void print_root_list(item *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Item %d:\n", i + 1);
        if (list[i].child_list == NULL)
            printf("\tChild list: None\n");
        else
            printf("\tChild list: Exist\n");
        printf("\tDegree: %d\n", list[i].degree);
        if (list[i].mark)
            printf("\tMark: True\n");
        else
            printf("\tMark: False\n");
        printf("\tValue: %d\n", list[i].value);

    }
}

int insert(int value, item *list, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (list[i].value == -1)
        {
            list[i].value = value;
            return 0;
        }
    }
    return 1;
}

void merge(item *list, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (list[i].degree == list[j].degree)
            {
                // DEGREE IS SAME -> GONNA MERGE
                if (list[i].value <= list[j].value)
                {
                    printf("tady1");
                    list[i].child_list[list[i].degree] = list[j];
                    printf("tady3");
                }
                else
                {
                    printf("tady2");
                    list[j].child_list[list[j].degree] = list[i];
                }
            }
        }
    }
}


int main()
{
    int size = 4;

    item *root_list = list_init(size);

    for (int value = 1; value <= size - 1; value++)
    {
        insert(value, root_list, size);
    }

    print_root_list(root_list, size);

    insert(10, root_list, size);
    root_list->child_list[root_list->degree] = root_list[3];
    
    printf("tusu");
    
    print_root_list(root_list, size);
    
    
    return 0;
}

