schedule: schedule.c schedule.h
	gcc -o schedule schedule.c schedule.h

clean:
	rm *.o schedule
