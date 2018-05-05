gcc -c tree.c
gcc -c parse.c
gcc -c solution.c
gcc parse.c tree.c solution.c -o solution
gcc parse.c tree.c solution.c -g -c solution
objcopy --only-keep-debug solution solution.dbg
