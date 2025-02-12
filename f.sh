run(){ clang -O0 -Wall -Werror -Wextra $1;shift;./a.out "$@";rm a.out;}
create(){ cp template.c $1; vis $1;}
