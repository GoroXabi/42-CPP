name		:=	DiamondTrap
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: $(name)

$(name):
	$(compiler) $(cflags) main.cpp DiamondTrap.cpp -o $(name)

clean:
	rm $(name)

re: clean all
