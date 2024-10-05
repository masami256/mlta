CUR_DIR = $(shell pwd)
LLVM_BUILD := ${CUR_DIR}/../llvm-project/build/
CC=${LLVM_BUILD}/bin/clang
IRDumper_DIR=${CUR_DIR}/../IRDumper/build/lib
KANALYZER=${CUR_DIR}/../build/lib/kanalyzer

CFLAGS=-Wno-error -g -v -Xclang -opaque-pointers=0 -fpass-plugin=${IRDumper_DIR}/libDumper.so
#CFLAGS=-Wno-error -g -v -Wno-error -g -Xclang -no-opaque-pointers -Xclang -flegacy-pass-manager -Xclang -load -Xclang ${IRDumper_DIR}/libDumper.so

all: test_single_layer \
test_multi_layer

test_single_layer:
	${CC} ${CFLAGS} single_layer_test.c -o test_single_layer_main

test_multi_layer:
	${CC} ${CFLAGS} multi_layer_test.c -o test_multi_layer_main

test_single:
	${KANALYZER} single_layer_test.bc

test_multi:
	${KANALYZER} multi_layer_test.bc

clean:
	rm -f test_* *.bc bc.list *.o
