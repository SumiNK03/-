#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;


int main(void) {
	int T = 0;
	scanf("%d", &T);
	while (T > 0) {
		string list[100];
		int N = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			int count = -1;
			string str;
			cin >> str;
			list[i] = str;
			int a = i;
			while (a > 0) {
				count++;
				count += list[a].length();
				a = a / 2;
			}
			printf("%d\n", count);
		}
		T--;
	}
	return 0;
}