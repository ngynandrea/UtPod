final: UtPodDriver.o UtPod.o Song.o
	g++ -otest  UtPodDriver.o UtPod.o Song.o
driver: UtPodDriver.cpp UtPod.h Song.h
	g++ -c UtPod_Driver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c UtPod.cpp
song.o: song.cpp song.h
	g++ -c Song.cpp
