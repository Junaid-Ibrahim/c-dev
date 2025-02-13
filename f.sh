run(){ clang -O0 -Werror -Wall -Wextra $1; shift; ./a.out "$@"; rm -rf ./a.out;}
edit(){ [ -a $1 ] cp template.c $1; vis $1;}
