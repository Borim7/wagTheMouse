all: wagTheMouse.exe

wagTheMouse.exe: wagTheMouse.c
	gcc -Wall -o $@ $<

clean:
	rm -f wagTheMouse.exe
