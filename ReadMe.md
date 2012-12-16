# My Solution for book *Beauty of Programming*

## Fun of Game

### Control CPU usage curve

1. Fix CPU usage curve to 50% as a straight line.
2. Fix CPU usage curve to a straight line with given arguments.
3. Fix CPU usage curve to a sine curve.

Use loop to force CPU into busy, use `Sleep()` to make CPU idle.

### Chinese Chess Kings

Abstraction:

	Black:
	1 - 2 - 3
	|   |   |
	4 - 5 - 6
	|   |   |
	7 - 8 - 9

	V.S.

	Red:
	7 - 8 - 9
	|   |   |
	4 - 5 - 6
	|   |   |
	1 - 2 - 3

Both of Kings should be in one line. (In column, say (b1, r7))

Use only one variable to generate all possible position pairs.

Without the restriction, there are naive solution as below:

	for(int i = 1; i <= 9; i++) {
		for(int j = 1; j <= 9; j++) {
			if(i % 3 != j % 3) {
				printf("(B%d, R%d)\n", i, j);
			}
		}
	}

Consider the concept of [Linear Independence](http://en.wikipedia.org/wiki/Linear_independence), we could use a variable to represent two independent variables. For example:

	c = a + b \dot i, where i means imaginary unit.

However, complex number is not a build-in type in C++. We need some tricks. As both `i` and `j` are from 1 to 9, we could use decades to represent `i` while single digit for `j`.

	k = 10i + j

The solution above could be convert to the ones below:

	for(int k = 10; k / 10 <= 9;) {
		for(k = k / 10 * 10 + 1; k % 10 != 0; k++) {
			if(k / 10 % 3 != k % 10 % 3) {
				printf("(B%d, R%d)\n", k / 10, k % 10);
			}
		}
	}

In binary world, there are even more ways to approach the Linear Independence. For example, use higher 4 bits for `i` while lower 4 bits for `j`.

	typedef unsigned BYTE;
	inline int GET_HIGHER(BYTE value) { return value >> 4; }
	inline BYTE INC_HIGHER(BYTE value) { return value + (1 << 4); }
	inline int GET_LOWER(BYTE value) { return value & ((1 << 4) - 1); }
	inline BYTE INC_LOWER(BYTE value) { return value + 1; }
	inline BYTE SET_ONE_LOWER(BYTE value) { return (value & (~((1 << 4) - 1))) | 1; }
	
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

Another way with actually same effect is

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

Switching to the Combinatorics, there are 9 * 9 = 81 status in total. We enumerate all these status, and generate the outputs. The first 9 status means `i = 1` while `j` from 1 to 9, the second 9 status means `i = 2` while `j` from 1 to 9, etc. In another word, `i = k / 9` while `j = k % 9`.

	for(int k = 0; k < 9 * 9; k++) {
		if((k / 9 + 1) % 3 != (k % 9 + 1) % 3) {
			printf("(B%d, R%d)\n", k / 9 + 1, k % 9 + 1);
		}
	}

