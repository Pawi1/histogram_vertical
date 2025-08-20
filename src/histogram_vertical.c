/*
 * histogram_vertical.c
 *
 *  Created on: 20 Aug 2025
 *      Author: pawil
 */
#include <stdio.h>

int* countDigits(){
	static int nd[10] = {0};
	int c;
	while((c = getchar()) != EOF){
		if(c >= '0' && c <= '9')
			++nd[c-'0'];
	}
	return nd;
}

int findMax(int* list){
	int max, i;
	max = list[0];
	for(i = 1; i < 10; i++){
		if(list[i] > max)
			max = list[i];
	}
	return max;
}

void drawHistogram(int* nd, int maxD){
	printf("\tHistogram\n");
	for(; maxD > 0; maxD--){
		printf("%2d \u2591%s\u2591%s\u2591%s\u2591%s\u2591%s\u2591%s\u2591%s\u2591%s\u2591%s\u2591%s\u2591\n",
				maxD,
				(nd[0] >= maxD)?"\u2588":"\u2591",
				(nd[1] >= maxD)?"\u2588":"\u2591",
				(nd[2] >= maxD)?"\u2588":"\u2591",
				(nd[3] >= maxD)?"\u2588":"\u2591",
				(nd[4] >= maxD)?"\u2588":"\u2591",
				(nd[5] >= maxD)?"\u2588":"\u2591",
				(nd[6] >= maxD)?"\u2588":"\u2591",
				(nd[7] >= maxD)?"\u2588":"\u2591",
				(nd[8] >= maxD)?"\u2588":"\u2591",
				(nd[9] >= maxD)?"\u2588":"\u2591"
		);
	}
	printf("    0 1 2 3 4 5 6 7 8 9 \n");
}

int main(){
	int* nd = countDigits();
	drawHistogram(nd, findMax(nd));
}
