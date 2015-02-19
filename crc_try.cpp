#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int v[] = {1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1};
	int g[] = {1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1};
	int v_len, g_len, i, j, k;
	int vp[17];

	v_len = sizeof(v) / sizeof(int);
	g_len = sizeof(g) / sizeof(int);

	cout << v_len << " " << g_len << endl;

	for (i = 0; i < v_len; i++) {
		vp[i] = v[i];
	}

	for (i = 0; i < v_len - g_len; i++) {
		if (vp[i] == 0) 
			continue;
		for (j = 0; j < g_len; j++) {
			vp[j+i] = vp[j+i] ^ g[j];
		}

		for (k = 0; k < v_len; k++) {
			cout << vp[k]; 
		}
		
		cout << endl;
	}

	
	return 0;
}
