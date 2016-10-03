all: wagTheMouse.exe

wagTheMouse.exe: wagTheMouse.c
	gcc -m32 -Wall -o $@ $<

clean:
	rm -f wagTheMouse.exe
