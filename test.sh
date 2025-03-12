clang -O3 eo.c
printf '\e[32m even \e[0m\n'
printf '\e[32m 2 6 \e[0m\n'
./a.out e 2 6
printf '\e[32m 1 6 \e[0m\n'
./a.out e 1 6
printf '\e[32m 1 5 \e[0m\n'
./a.out e 1 5
printf '\e[32m 2 5 \e[0m\n'
./a.out e 2 5

printf '\e[32m odd \e[0m\n'
printf '\e[32m 2 6 \e[0m\n'
./a.out o 2 6
printf '\e[32m 1 6 \e[0m\n'
./a.out o 1 6
printf '\e[32m 1 5 \e[0m\n'
./a.out o 1 5
printf '\e[32m 2 5 \e[0m\n'
./a.out o 2 5