NAME := bf

ifeq ($(OS),Windows_NT)
NAME := bf.exe
endif

default:
	gcc -o $(NAME) src/*.c

run:
	gcc -o $(NAME) src/*.c
	$(NAME)

hello-world:
	gcc -o $(NAME) src/*.c
	$(NAME) examples/helloworld.bf