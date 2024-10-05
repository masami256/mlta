#include <stdio.h>
#include <stdlib.h>

struct single_layer {
    int n;
    void (*fp)(void);
};

static void single_layer_test_func_a(void)
{
    printf("%s\n", __func__);
}

static void single_layer_test_func_b(void)
{
    printf("%s\n", __func__);
}

static struct single_layer test_single_layer_st_a = {
    .n = 10,
    .fp = &single_layer_test_func_a,
};

static struct single_layer test_single_layer_st_b = {
    .n = 11,
    .fp = &single_layer_test_func_b,
};

struct single_layer *get_single_layer_a(void)
{
    return (struct single_layer *) &test_single_layer_st_a;
}

struct single_layer *get_single_layer_b(void)
{
    return (struct single_layer *) &test_single_layer_st_b;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("usage: %s <number>\n", argv[0]);
        exit(1);
    }
    struct single_layer *p;

    int opt = atoi(argv[1]);

    switch (opt) {
        case 0:
        p = get_single_layer_a();
        break;
        case 1:
        p = get_single_layer_b();
        break;
        default:
        printf("Unkown option %s\n", argv[1]);
    }

    p->fp();

    return 0;
}