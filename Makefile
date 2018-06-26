main: wuzichi.c startscreen.o save.o leaderboard.o blackwin.o whitewin.o
	gcc wuzichi.c startscreen.o save.o leaderboard.o blackwin.o whitewin.o -o Wuzichi
startscreen.o: startscreen.c
	gcc -c startscreen.c
save.o: save.c
	gcc -c save.c
leaderboard.o: leaderboard.c
	gcc -c leaderboard.c
blackwin.o: blackwin.c
	gcc -c blackwin.c
whitewin.o: whitewin.c
	gcc -c whitewin.c