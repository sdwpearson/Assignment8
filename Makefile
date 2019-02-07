CXX=g++
CXXFLAGS=-std=c++11 -g -O3 -march=native
LDFLAGS=-g
LDLIBS=

all: antsontable-orig antsontable

clean: clean-orig clean-new

distclean: clean clean-more

.PHONY: all clean distclean clean-orig clean-new clean-more run-orig run test

antsontable-orig.o: antsontable-orig.cc
	${CXX} ${CXXFLAGS} -c -o $@ $^

antsontable-orig: antsontable-orig.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

run-orig: antsontable-orig
	./antsontable-orig > run-orig

clean-orig:
	\rm -f antsontable-orig.o


timestep.o: timestep.cc timestep.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

report.o: report.cc report.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

initialization.o: initialization.cc initialization.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

randompartition.o: randompartition.cc randompartition.h
	${CXX} ${CXXFLAGS} -c -o $@ $<

antsontable.o: antsontable.cc
	${CXX} ${CXXFLAGS} -c -o $@ $<

antsontable: antsontable.o initialization.o randompartition.o report.o  timestep.o
	${CXX} ${LDFLAGS} -o $@ $^ ${LDLIBS}

run: antsontable
	./antsontable > run

clean-new:
	\rm -f antsontable.o initialization.o randompartition.o report.o timestep.o

clean-more:
	\rm antsontable antsontable-orig run run-orig

test: run run-orig
	diff run run-orig

