open:
	vim nutrition.c
file:
	gcc -Wall -Werror -std=c11 -o file nutrition.c
read:
	vim *.txt
clean:
	rm file && rm *.txt
