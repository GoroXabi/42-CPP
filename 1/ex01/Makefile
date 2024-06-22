name		:=	Horde
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: $(name)

$(name):
	$(compiler) $(cflags) main.cpp Zombie.cpp zombieHorde.cpp -o $(name)

clean:
	rm $(name)
