name		:=	bsp
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: $(name)

$(name):
	$(compiler) $(cflags) main.cpp Fixed.cpp Point.cpp bsp.cpp -o $(name)

clean:
	rm $(name)
