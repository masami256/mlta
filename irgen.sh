# Configurations
KERNEL_SRC="/opt/masami/v6.1.112"
#KERNEL_SRC="$(pwd)/../kernels/linux"
IRDUMPER="$(pwd)/IRDumper/build/lib/libDumper.so"
CLANG="$(pwd)/llvm-project/prefix/bin/clang"
CONFIG="defconfig"
#CONFIG="allyesconfig"

# Use -Wno-error to avoid turning warnings into errors
NEW_CMD="\n\n\
KBUILD_USERCFLAGS += -Wno-error -g -v -fpass-plugin=$IRDUMPER\nKBUILD_CFLAGS += -Wno-error -g -v -fpass-plugin=$IRDUMPER"

# Back up Linux Makefile
#cp $KERNEL_SRC/Makefile $KERNEL_SRC/Makefile.bak

if [ ! -f "$KERNEL_SRC/Makefile.bak" ]; then
	echo "Back up Linux Makefile first"
	exit -1
fi

# The new flags better follow "# Add user supplied CPPFLAGS, AFLAGS and CFLAGS as the last assignments"
echo -e $NEW_CMD >$KERNEL_SRC/IRDumper.cmd
cat $KERNEL_SRC/Makefile.bak $KERNEL_SRC/IRDumper.cmd >$KERNEL_SRC/Makefile

cd $KERNEL_SRC && make mrproper && make $CONFIG
echo $CLANG
echo $NEW_CMD
make V=1 CC=$CLANG -j`nproc` -k -i

