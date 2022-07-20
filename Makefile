DESTDIR ?= /usr/bin

leet: mainleet.cpp
	g++ mainleet.cpp -o leet


install: leet
	install leet $(DESTDIR)/leet


uninstall: leet
	rm -v leet $(DESTDIR)/leet


clean: 
	rm leet
