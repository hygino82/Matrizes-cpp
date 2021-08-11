#include <iostream>

using namespace std;

double t[4][5] = {
		{ 3.81, 0.25, 1.28, 0.8, 4.21 },
		{ 2.25, 1.31, 5.08, 0.49, 6.97 },
		{ 5.31, 6.78, 0.98, 1.04, 2.38 },
		{ 9.89, 2.45, 3.35, 2.28, 10.98 } };

void escreva_t();
void escalonamento();
void determinarValores();

int main() {
	cout << "Matriz inicial do sistema" << endl;
	escreva_t();
	escalonamento();
	cout << endl << "Matriz escalonada do sistema" << endl;
	escreva_t();
	determinarValores();
	//double x4=t[3][4]/t[3][3];
	//double x3=t[2][4]-x4*t[2][3];
	return 0;
}

void escreva_t() {
	int r, s;
	for (r = 0; r < 4; r++) {
		for (s = 0; s < 5; s++)
			printf("%.5f  ", t[r][s]);
		printf("\n");
	}
	printf("\n");

}

void escalonamento() {
	int x, y, p;
	int n = 4;
	double cte;
	for (p = 0; p < n; p++) {
		if (t[p][p] == 0)
			for (x = p + 1; x < n; x++)
				if (t[x][p] != 0)
					for (y = 0; y < n; y++)
						t[p][y] = t[p][y] + t[x][y];
		if (t[p][p] != 0)
			for (x = p + 1; x < n; x++) {
				cte = t[x][p] / t[p][p];
				for (y = 0; y < n; y++)
					t[x][y] = t[x][y] - cte * t[p][y];
			}
	}
}

void determinarValores() {
	cout << "Solução encontrada do sistema\n";
	double x[4] = { 0, 0, 0, 0 };
//	 x[3] = t[3][4] / t[3][3];
//	 x[2] = (t[2][4] - x[3] * t[2][3]) / t[2][2];
//	 x[1] = (t[1][4] - x[3] * t[1][3] - x[2] * t[1][2]) / t[1][1];
//	 x[0] = (t[0][4] - x[3] * t[0][3] - x[2] * t[0][2] - x[1] * t[0][1]) / t[0][0];
	int n = 3;	//número de linhas
//	for (int p = n; p >= 0; p--) {
//		cout << p << endl;
//	}
	for (int p = n; p >= 0; p--) {
		double soma = 0.0;
//		if (p == n)
//			x[p] = t[p][4] / t[p][p];
//		else {
//			for (int c = p + 1; c <= n; c++) {
//				soma = x[c] * t[p][c];
//			}
//		}
		for (int c = p + 1; c <= n; c++) {
			soma = x[c] * t[p][c];


		}
		x[p] = (t[p][n + 1] - soma) / t[p][p];


	}
	for (int p = 0; p <= 3; p++) {
		printf("x[%d] = %.5f\n", p, x[p]);
	}
	cout << "Fim do programa!" << endl;
}

