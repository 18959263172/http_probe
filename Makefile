SRC = $(wildcard *.cpp ./src_gumbo/*.cpp  ./src_hp/*.cpp ./src_gumbo/*.c ./src_gumbo/*.c)
all:
     ifndef ($(shell pkg-config --cflags gumbo_libxml)) 
	cd /root/lib-src/libxml2-2.9.3/&&/root/lib-src/libxml2-2.9.3/configure
	cd /root/lib-src/libxml2-2.9.3/&&make
	cd /root/lib-src/libxml2-2.9.3/&&make install
	g++ ${SRC} -o main -I ./include -lgumbo -lxml2
 endif	
