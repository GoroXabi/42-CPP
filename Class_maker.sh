#!/bin/bash

if [ -z "$1" ]; then
  echo "mete un numero tolai"
  exit 1
fi

class_name="placeholder"

folder_name=$1
class_name=$2

class_name_HPP=$(echo "$class_name" | tr '[:lower:]' '[:upper:]')
class_name_HPP=$(printf "%s_HPP" $class_name_HPP)

mkdir -p "$folder_name"

  cat <<EOL > "$folder_name/main.cpp"
#include <iostream>
#include "$class_name.hpp"


int main() {
    
    return 0;
}
EOL

  cat <<EOL > "$folder_name/$class_name.cpp"
#include "$class_name.hpp"

/*--------------------------------------------------------------*/
/*							CONSTRUCTORS						*/
/*--------------------------------------------------------------*/

$class_name::$class_name() {

}

$class_name::$class_name(const $class_name &model) {

}

$class_name &$class_name::operator=(const $class_name &model) {

}

/*--------------------------------------------------------------*/
/*							DESTRUCTORS							*/
/*--------------------------------------------------------------*/

$class_name::~$class_name() {

}

/*--------------------------------------------------------------*/
/*						PUBLIC_FUNCTIONS						*/
/*--------------------------------------------------------------*/

EOL

  cat <<EOL > "$folder_name/$class_name.hpp"
#ifndef $class_name_HPP
#define $class_name_HPP

#include <iostream>

class	$class_name
{
private:

public:

/*--------------------CONSTRUCTORS-------------------*/
	$class_name();
	$class_name(const $class_name &model);
	$class_name &operator=(const $class_name &model);

/*--------------------DESTRUCTORS--------------------*/

	~$class_name();

/*-----------------PUBLIC_FUNCTIONS------------------*/

};

#endif
EOL
  cat <<EOL > "$folder_name/Makefile"
name		:=	$class_name
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: \$(name)

\$(name):
	\$(compiler) \$(cflags) main.cpp $class_name.cpp -o \$(name)

clean:
	rm \$(name)

re: clean all
EOL
echo "Se ha creado una carpeta $folder_name, para la clase $class_name"
