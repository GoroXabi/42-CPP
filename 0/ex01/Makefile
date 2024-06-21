name		:=	phone_book
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: $(name)

$(name):
	$(compiler) $(cflags) main.cpp contact.cpp phone_book.cpp -o $(name)

clean:
	rm $(name)