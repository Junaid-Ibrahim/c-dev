clang -O0 eo.c
printf '\e[32m e \e[0m\n'
printf '\e[32m 2 6 \e[0m'
./a.out << f
e
2 6
f
printf '\e[32m 1 6 \e[0m'
./a.out << f
e
1 6
f
printf '\e[32m 1 5 \e[0m'
./a.out << f
e
1 5
f
printf '\e[32m 2 5 \e[0m'
./a.out << f
e
2 5
f

printf '\e[32m o \e[0m\n'
printf '\e[32m 2 6 \e[0m'
./a.out << f
o
2 6
f
printf '\e[32m 1 6 \e[0m'
./a.out << f
o
1 6
f
printf '\e[32m 1 5 \e[0m'
./a.out << f
o
1 5
f
printf '\e[32m 2 5 \e[0m'
./a.out << f
o
2 5
f

