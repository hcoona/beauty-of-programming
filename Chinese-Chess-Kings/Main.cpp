#include <cstdio>

using namespace std;

int solution1(void);
int solution2(void);
int solution3(void);
int solution4(void);
int solution5(void);

int main(void) {
    solution5();
    printf("\n");
    solution4();
    printf("\n");
    solution3();
    printf("\n");
    solution2();
    printf("\n");
    return solution1();
}

int solution1(void) {    
	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= 9; j++) {
			if(i % 3 != j % 3) {
				printf("(B%d, R%d)\n", i, j);
			}
		}
	}
    return 0;
}

int solution2(void) {    
	for(int k = 10; k / 10 <= 9;) {
		for(k = k / 10 * 10 + 1; k % 10 != 0; k++) {
			if(k / 10 % 3 != k % 10 % 3) {
				printf("(B%d, R%d)\n", k / 10, k % 10);
			}
		}
	}
    return 0;
}

typedef unsigned char BYTE;
inline int GET_HIGHER(BYTE value) { return value >> 4; }
inline BYTE INC_HIGHER(BYTE value) { return value + (1 << 4); }
inline int GET_LOWER(BYTE value) { return value & ((1 << 4) - 1); }
inline BYTE INC_LOWER(BYTE value) { return value + 1; }
inline BYTE SET_ONE_LOWER(BYTE value) { return (value & (~((1 << 4) - 1))) | 1; }
int solution3(void) {
    BYTE k = 0;
    k = INC_HIGHER(k);
    k = INC_LOWER(k);
    for(; GET_HIGHER(k) <= 9; k = INC_HIGHER(k)) {
        for(k = SET_ONE_LOWER(k); GET_LOWER(k) <= 9; k = INC_LOWER(k)) {
            if(GET_HIGHER(k) % 3 != GET_LOWER(k) % 3) {
				printf("(B%d, R%d)\n", GET_HIGHER(k), GET_LOWER(k));
            }
        }
    }
    return 0;
}

int solution4(void) {
    union {
        struct {
            unsigned char higher : 4;
            unsigned char lower : 4;
        } pair;
        BYTE byte;
    } k;
    for(k.pair.higher = 1; k.pair.higher <= 9; k.pair.higher++) {
        for(k.pair.lower = 1; k.pair.lower <= 9; k.pair.lower++) {
            if(k.pair.higher % 3 != k.pair.lower % 3) {
                printf("(B%d, R%d)\n", k.pair.higher, k.pair.lower);
            }
        }
    }
    return 0;
}

int solution5(void) {
    for(int k = 0; k < 9 * 9; k++) {
        if((k / 9 + 1) % 3 != (k % 9 + 1) % 3) {
            printf("(B%d, R%d)\n", k / 9 + 1, k % 9 + 1);
        }
    }
    return 0;
}