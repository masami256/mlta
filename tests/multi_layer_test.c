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

static struct multi_layer *init_layer(void *addr)
{
    struct multi_layer *ml = malloc(sizeof(*ml));
    ml->s = malloc(sizeof(*(ml->s)));
    ml->s->fp = addr;
    return ml;
}

static void multi_layer_func_a(void)
{
    printf("%s\n", __func__);
}

struct multi_layer *get_multi_layer_a(void)
{
    return init_layer(&multi_layer_func_a);
}

static void multi_layer_func_b(void)
{
    printf("%s\n", __func__);
}

struct multi_layer *get_multi_layer_b(void)
{
    return init_layer(&multi_layer_func_b);
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