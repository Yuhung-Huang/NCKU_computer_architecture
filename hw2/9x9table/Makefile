BINS = emu-rv32i setup test1
BINS_hanoi = emu-rv32i setup_hanoi hanoi

CROSS_COMPILE = riscv-none-embed-
ifeq (${O},1)
RV32I_CFLAGS = -march=rv32im -mabi=ilp32 -nostdlib
else
RV32I_CFLAGS = -march=rv32im -mabi=ilp32 -O3 -nostdlib
endif
link = link.ld
link_hanoi = link_hanoi.ld

ifeq (${D},1)
CFLAGS = -O3 -Wall -D DEBUG_OUTPUT -D DEBUG_EXTRA
else
CFLAGS = -O3 -Wall
endif
CFLAGS1 = -O3 -Wall
LDFLAGS = -lelf

all: check
	
emu-rv32i: emu-rv32i.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)  


test1: test1.c setup.o
	$(CROSS_COMPILE)gcc $^ $(RV32I_CFLAGS) -T $(link) -o $@
hanoi: hanoi.c setup_hanoi.o
	$(CROSS_COMPILE)gcc $^ $(RV32I_CFLAGS) -T $(link_hanoi) -o $@

check_hanoi: $(BINS_hanoi)
	./emu-rv32i hanoi

check: $(BINS)
	./emu-rv32i test1

setup: setup.s
	$(CROSS_COMPILE)gcc $(RV32I_CFLAGS) -c $<

setup_hanoi: setup_hanoi.s
	$(CROSS_COMPILE)gcc $(RV32I_CFLAGS) -c $<

clean:
	$(RM) $(BINS) 
	$(RM) $(BINS_hanoi)
	$(RM) *.mem
