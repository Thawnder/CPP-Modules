MAKEFLAGS = --silent

NAME = typeinfo
SRC = main.cpp
OBJ = ${SRC:.cpp=.o}
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g -Wshadow -Wno-shadow

all: ${NAME}
		echo "\033[1;34m~| All files updated ! |~\033[0m"\

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME} \
			&& echo "\033[1;36m~| $@ compilation: OK |~\033[0m"\
            || echo "\033[0;31m~| $@ compilation: Error |~\033[0m"

clean:
	rm -rf ${OBJ} \
			&& echo "\033[1;35m~| Object files cleaning : OK |~\033[0m"\
            || echo "\033[0;31m~| Object files cleaning : Error |~\033[0m"

fclean: clean
	rm -rf ${NAME} \
			&& echo "\033[1;35m~| Executable files cleaning : OK |~\033[0m"\
            || echo "\033[0;31m~| Executable files cleaning : Error |~\033[0m"

re: fclean all