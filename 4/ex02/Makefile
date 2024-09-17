name		:=	Farm
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: $(name)

$(name):
	$(compiler) $(cflags) main.cpp Brain.cpp AAnimal.cpp Dog.cpp Cat.cpp -o $(name)

clean:
	rm $(name)

re: clean all
