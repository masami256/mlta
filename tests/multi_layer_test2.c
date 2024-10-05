#include <stdio.h>
#include <stdlib.h>

struct second_layer {
    int n;
    void (*fp)(void);
};

struct multi_layer {
    int n;
    struct second_layer *s;
};

static void second_layer_func_a(void)
{
    printf("%s\n", __func__);
}

static void second_layer_func_b(void)
{
    printf("%s\n", __func__);
}

static struct second_layer sl1 = {
    .fp = &second_layer_func_a,
};

static struct second_layer sl2 = {
    .fp = &second_layer_func_b,
};

static struct multi_layer ml1 = {
    .s = & sl1,
};

static struct multi_layer ml2 = {
    .s = & sl2,
};

struct multi_layer *get_multi_layer_a(void)
{
    return &ml1;
}

struct multi_layer *get_multi_layer_b(void)
{
    return &ml2;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("usage: %s <number>\n", argv[0]);
        exit(1);
    }
    struct multi_layer *p;

    int opt = atoi(argv[1]);

    switch (opt) {
        case 0:
        p = get_multi_layer_a();
        break;
        case 1:
        p = get_multi_layer_b();
        break;
        default:
        printf("Unkown option %s\n", argv[1]);
    }

    p->s->fp();

    return 0;
}