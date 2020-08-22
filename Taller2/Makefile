
all: completo


completo:
	g++ main.cpp -o programa -Wall -I/usr/local/pgsql/include -L/usr/local/pgsql/lib -lpq
	$(RM) *.o
clean:
	$(RM) *.o
#g++ connPgSQL.cpp -o connPgSQL -Wall -I/usr/local/pgsql/include -L/usr/local/pgsql/lib -lpq