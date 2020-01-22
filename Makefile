#######################################################################
#
#   MAKEFILE for Xe100_ReadGainFiles -- Gain files reader/plotter
#   March 2009, Alexander Kish  
#
######################################################################

EXE	=	pt100

CC	=	g++

COPTS	=	-fPIC -DLINUX -Wall \
                $(shell root-config --cflags) 

FLAGS	=	-Wall

DEPLIBS	=       -l m

LIBS	=	$(shell root-config --libs)

INCLUDEDIR =	-I.

OBJS	=	$(EXE).o

INCLUDES =	

#########################################################################

all	:	$(EXE)

clean	:
		/bin/rm -f $(OBJS) $(EXE)

$(EXE)	:	$(OBJS)
		/bin/rm -f $(EXE)
		$(CC) $(FLAGS) -o $(EXE) $(OBJS) $(LIBS) $(DEPLIBS)

$(OBJS)	:	$(INCLUDES) Makefile

%.o	:	%.cpp
		$(CC) $(COPTS) $(INCLUDEDIR) -c -o $@ $<
