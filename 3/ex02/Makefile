name		:=	FragTrap
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: $(name)

$(name):
	$(compiler) $(cflags) main.cpp FragTrap.cpp -o $(name)

clean:
	rm $(name)

re: clean all
