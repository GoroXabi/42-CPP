name		:=	test
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: $(name)

$(name):
	$(compiler) $(cflags) Account.cpp tests.cpp -o $(name)

clean:
	rm $(name)
