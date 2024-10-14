CUR_DIR = $(shell pwd)
LLVM_BUILD := ${CUR_DIR}/../llvm-project/build/
CC=${LLVM_BUILD}/bin/clang
IRDumper_DIR=${CUR_DIR}/../IRDumper/build/lib
KANALYZER=${CUR_DIR}/../build/lib/kanalyzer

CFLAGS=-Wno-error -g -fpass-plugin=${IRDumper_DIR}/libDumper.so

all: test_single_layer \
test_multi_layer \
test_multi_layer2

test_single_layer:
	${CC} ${CFLAGS} single_layer_test.c -o test_single_layer_main

test_multi_layer:
	${CC} ${CFLAGS} multi_layer_test.c -o test_multi_layer_main

test_multi_layer2:
	${CC} ${CFLAGS} multi_layer_test2.c -o test_multi_layer_main2

test_single:
	${KANALYZER} --verbose-level=3 --srcdir ${CUR_DIR} single_layer_test.bc

test_multi:
	${KANALYZER} --verbose-level=3 --srcdir ${CUR_DIR} multi_layer_test.bc

test_multi2:
	${KANALYZER} --verbose-level=3 --srcdir ${CUR_DIR} multi_layer_test2.bc

clean:
	rm -f test_* *.bc bc.list *.o
