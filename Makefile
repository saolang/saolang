help:
	@echo TODO help

build-with-tcc:
	tcc -vv

build-with-c:
	@echo build with default CC[$(CC)]
	$(CC) c/sao.c -o sao.bin

build-with-sao:
	set CC=sao
	$(CC) libsao.sao

env:
	@echo CC=$(CC)
