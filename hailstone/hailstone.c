#include <stdio.h>
#include <stdlib.h>

// Forward declarations
int calc(int num);

int calc(int num) 
{
	int newnum = (num & 1) ? num * 3 + 1 : num / 2;
	return newnum;
}

int hailstone(int start, int end)
{
	int max_cyclelength = 0;
	int current_cyclelength = 1;
	int newnumber = 0;
	for (int i = start; i <= end; i++) {
		current_cyclelength = 1;
		newnumber = calc(i);
		if (i <= 1) {
			current_cyclelength++;
		} else {
			
			current_cyclelength++;
			while (newnumber > 1) {
				newnumber = calc(newnumber);
				current_cyclelength++;
			}
		}
		if (max_cyclelength < current_cyclelength) {
			max_cyclelength = current_cyclelength;
		}
	}
	return max_cyclelength;
}

int main(int argc, char *argv[])
{
	int cyclelength;
	if (argc == 3) {
		if ((atoi(argv[1]) > 0) && (atoi(argv[2]) <= 100000000)) {
			//the argument is a number convert to date
			cyclelength = hailstone(atoi(argv[1]), atoi(argv[2]));
			printf("\n\n%d %d %d\n\n", atoi(argv[1]), atoi(argv[2]), cyclelength);
		} else {
			printf("\n You're doing it wrong... This command works as follow:\n\n");
			printf("\t hailstone startinteger endinteger\n\n");	
			printf("\t start must be > 0 and end < 100000000\n\n");	
		}
	} else {
		printf("\n You're doing it wrong... This command works as follow:\n\n");
		printf("\t hailstone startinteger endinteger\n\n");
	}
	return 0;
}