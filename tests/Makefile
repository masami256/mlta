CUR_DIR = $(shell pwd)
LLVM_BUILD := ${CUR_DIR}/../llvm-project/build/
CC=${LLVM_BUILD}/bin/clang
IRDUMPER=${CUR_DIR}/../IRDumper/build/lib/libDumper.so
KANALYZER=${CUR_DIR}/../build/lib/kanalyzer

CFLAGS=-I. -Wno-error -g -Xclang -no-opaque-pointers -Xclang -flegacy-pass-manager -Xclang -load -Xclang ${IRDUMPER}

all: build_tests

build_tests:
	${CC} ${CFLAGS} fp_struct.c -o test_fp_struct

TEST_TARGETS := $(patsubst %.bc,test_%, $(wildcard *.bc))
.PHONY: $(TEST_TARGETS)

tests: $(TEST_TARGETS)

test_fp_struct:
	sha1sum fp_struct.bc
	$(KANALYZER) --src-path=${CUR_DIR} fp_struct.bc
	sha1sum fp_struct.bc

clean:
	rm -f test_* *.bc bc.list *.o