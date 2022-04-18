#include "dlist_library.h"

int main()
{
    dlist_t *list = init_empty();

    for(int i = 0; i <= 5; i++) {
        add_first(list, i);
    }
    print_list(list);

    printf("\n");
    add_before(list, 4, 9);
    print_list(list);
    return 0;
}
