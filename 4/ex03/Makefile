name		:=	AMateria
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: $(name)

$(name):
	$(compiler) $(cflags) main.cpp AMateria.cpp -o $(name)

clean:
	rm $(name)

re: clean all
