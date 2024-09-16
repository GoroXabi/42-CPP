name		:=	Farm
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: $(name)

$(name):
	$(compiler) $(cflags) main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp -o $(name)

clean:
	rm $(name)

re: clean all
