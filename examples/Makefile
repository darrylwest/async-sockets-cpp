CC		:= g++
CFLAGS	:= --std=c++11
LIBS	:= -lpthread
INC		:= -I../async-sockets/include
RM		:= rm

all: tcp-client tcp-server udp-client udp-server udp-request

tcp-client:
	$(CC) $(CFLAGS) tcp-client.cpp $(INC) $(LIBS) -o tcp-client

tcp-server:
	$(CC) $(CFLAGS) tcp-server.cpp $(INC) $(LIBS) -o tcp-server

udp-client:
	$(CC) $(CFLAGS) udp-client.cpp $(INC) $(LIBS) -o udp-client

udp-server:
	$(CC) $(CFLAGS) udp-server.cpp $(INC) $(LIBS) -o udp-server

udp-request:
	$(CC) $(CFLAGS) udp-request.cpp $(INC) $(LIBS) -o udp-request

clean:
	$(RM) -f tcp-client tcp-server udp-client udp-server udp-request
