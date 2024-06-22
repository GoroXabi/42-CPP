name		:=	Armory
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: $(name)

$(name):
	$(compiler) $(cflags) main.cpp Weapon.cpp HumanA.cpp HumanB.cpp -o $(name)

clean:
	rm $(name)
