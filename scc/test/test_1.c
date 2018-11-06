#include "scc_dl.h"
int main(){
	SCC(printf)("%04X | %04X = %04X; %04X\n", 15, 0x40,(15 | 0x40),~(15|0x40));
	SCC(printf)("%04X \n", 0x8 | (0x20 & ~(15|0x40)));
}
