#!/bin/bash

if [ -z "$1" ]; then
  echo "mete un numero tolai"
  exit 1
fi

num_folders=$1

for ((i=0; i<num_folders; i++))
do
  folder_name=$(printf "ex%02d" $i)
  mkdir -p "$folder_name"
  
  cat <<EOL > "$folder_name/main.cpp"
#include <iostream>
#include "placeholder.hpp"


int main() {
    
    return 0;
}
EOL

  cat <<EOL > "$folder_name/placeholder.cpp"
#include "placeholder.hpp"
EOL

  cat <<EOL > "$folder_name/placeholder.hpp"
#ifndef PLACEHOLDER_HPP
#define PLACEHOLDER_HPP

#include <iostream>

class	Placeholder
{
private:

public:

};

#endif
EOL
  cat <<EOL > "$folder_name/Makefile"
name		:=	placeholder
compiler	:=	c++
cflags		:=	-Wall -Wextra -Werror -std=c++98



all: \$(name)

\$(name):
	\$(compiler) \$(cflags) main.cpp placeholder.cpp -o \$(name)

clean:
	rm \$(name)
EOL
done
echo "Se han creado $num_folders carpetas."
