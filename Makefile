CC=icpc
CFLAGS=-c -O3 -xHost -msse4.1 -pthread -w
LDFLAGS=-pthread 
SOURCES=hybridSSESort.cpp insertion.cpp sortingnetwork.cpp sortingnetworkSSE.cpp rsort/rsort_a.cpp rsort/rsort_u.cpp rsort/rsort_as.cpp rsort/rsort_us.cpp quicksort.cpp quicksortsse.cpp testing.cpp papitesting.cpp timer.cpp mergesort.cpp psrs.cpp
OBJECTS=$(SOURCES:.cpp=.o) /usr/lib/libpapi.so
EXECUTABLE=sort1

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf *o sort1
