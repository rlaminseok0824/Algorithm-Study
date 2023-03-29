#include <iostream>
using namespace std;

int main() {
	while (true) {
		cout << "문자열 입력>>";
		char line[100000];
		cin.getline(line, 100000, '\n');
		int length = strlen(line);
	
		char rline[100000];

		for (int i = 0; i < length + 1; i++) {
			if (line[i] == ' ') {
				rline[i] = line[i];
			}

			else if (line[i] == '<') {
				for (int j = i; j < length + 1; j++) {
					rline[j] = line[j];
					if (line[j] == '>') {
						i = j;
						j += length + 1;
					}
				}
			}

			else if (i < length) {
				int j = 0;

				while (line[i + j] != ' ' and line[i + j] != '<' and line[i + j] != '>' and i + j < length) {
					j++;
				}
			
				for (int l = 0; l < j + 1; l++) {
					rline[i + l] = line[i + j - 1 - l];
				}

				i += j - 1;
			}
		}

		cout << "뒤집어진 문자열>>";
		for (int i = 0; i < length + 1; i++) {
			cout << rline[i];
		}
		cout << endl;
	}
}