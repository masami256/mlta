#include <stdio.h>
#include <stdlib.h>
#include "common.h"

static void test_func_a(void);
static void test_func_b(void);

static void test_func_a(void)
{
    printf("%s\n", __func__);
}

static void test_func_b(void)
{
    printf("%s\n", __func__);
}

static struct fp_struct fp_struct_a = {
    .n = 10,
    .fp = &test_func_a,
};

static struct fp_struct fp_struct_b = {
    .n = 11,
    .fp = &test_func_b,
};

struct fp_struct *get_fp_struct_a(void)
{
    return (struct fp_struct *) &fp_struct_a;
}

struct fp_struct *get_fp_struct_b(void)
{
    return (struct fp_struct *) &fp_struct_b;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("usage: %s <number>\n", argv[0]);
        exit(1);
    }
    struct fp_struct *p;

    int opt = atoi(argv[1]);

    switch (opt) {
        case 0:
        p = get_fp_struct_a();
        break;
        case 1:
        p = get_fp_struct_b();
        break;
        default:
        printf("Unkown option %s\n", argv[1]);
    }

    p->fp();

    return 0;
}